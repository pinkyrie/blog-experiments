/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char,int> map;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            map[s[right]]++;
            while(map[s[right]] > 1){
                map[s[left]]--;
                left++;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution test;
    string str = "abcabcbb";
    cout << test.lengthOfLongestSubstring(str) << endl;
}
