#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countStars(const std::string& p) {
        int starCount = 0;
        // 遍历字符串 p
        for (char c : p) {
            if (c == '*') {
                ++starCount;  // 统计 '*' 的个数
            }
        }
        // 计算 p 的长度减去 '*' 的个数
        int result = p.size() - starCount*2;
        return result;
    }
    bool subMatch(string s, string p) {
        // base case
        if (p.empty()){
            return s.empty();
        }
        if(p.size() == 1 && s.size() == p.size()){
            return s[0] == p[0] || p[0] == '.';
        }
        else{
            if(p[0] == '*'){
                string prefix_p = "";
                string tail_p = p.substr(2);
                string extend_p = prefix_p + tail_p;
                int exp_size = countStars(extend_p);
                int s_size = s.size();
                while(exp_size<= s_size) {
                    if (subMatch(s, extend_p)) {
                        return true;
                    }
                    prefix_p = prefix_p + p[1];
                    extend_p = prefix_p + tail_p;
                    exp_size = countStars(extend_p);
                }
                // for(int p_size = extend_p.size(); p_size <= s.size(); p_size = extend_p.size()){
                //     if (subMatch(s, extend_p)) {
                //         return true;
                //     }
                //     prefix_p = prefix_p + p[1];
                //     extend_p = prefix_p + tail_p;
                // }
            }
            // Regular matching case: when the first characters match
            if (s.size() > 0 && (p[0] == s[0] || p[0] == '.')) {
                return subMatch(s.substr(1), p.substr(1));
                // Continue to check the rest of the string
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        std::reverse(s.begin(), s.end());
        std::reverse(p.begin(), p.end());
        // std::cout << s << p;
        // return subMatch(s,p);
        return subMatch(s,p);
    }
};

int main() {
    Solution solution;
    string s = "aaa";
    string p = ".a";

    bool result = solution.isMatch(s, p);
    cout << "Match result: " << (result ? "True" : "False") << endl;

    return 0;
}