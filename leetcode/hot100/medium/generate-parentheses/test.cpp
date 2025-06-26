//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
private:
    void dfs(vector<string>& result,
        string& current, int left, int right, int n) {
        if(current.size() == n * 2 && left == right) {
            result.push_back(current);
            return;
        }
        if(left >= right) {
            if(left < n) {
                current.push_back('(');
                dfs(result, current, left + 1, right, n);
                current.pop_back(); // 回溯
            }
            if(right < n) {
                current.push_back(')');
                dfs(result, current, left, right + 1, n);
                current.pop_back(); // 回溯
            }

        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int len = 2 * n; // 每个括号对包含两个括号
        vector<string> result;
        string current;
        dfs(result, current, 0, 0, n);
        return result;

    }
};

int main() {
    Solution test;
    int n = 3;
    vector<string> result = test.generateParenthesis(n);
    for (const string &s : result) {
        cout << s << " ";
    }
}