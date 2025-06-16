//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
class Solution {
private:
    bool isPalindrome(const string &s, int start, int end) {
        int left = start, right = end;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    // a a b
    void dfs(vector<vector<string>>& res, vector<string> &current,
        const string &s, int start , int idx) {
        // 结束条件
        if (idx == s.size()) {
            res.push_back(current);
            return;
        }
        
        if (idx < s.size()- 1) {
            // 考虑 i+1 后面的逗号怎么选
            dfs(res, current, s, start, idx + 1);
        }

        if(isPalindrome(s, start, idx)) {
            current.push_back(s.substr(start, idx - start + 1)); // 选当前字符
            dfs(res, current, s, idx + 1, idx + 1);
            current.pop_back(); // 回溯
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current_partition;
        if (s.empty()) {
            return result; // 如果字符串为空，直接返回空结果
        }
        dfs(result, current_partition, s, 0, 0);
        return result;
    }
};


int main() {
    Solution test;
    string s = "aab";
    vector<vector<string>> result = test.partition(s);
    for (const auto &group : result) {
        for (const string &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
}