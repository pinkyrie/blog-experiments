/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

class Solution {
public:
    // int longestValidParentheses(string s) {
    //     int n = s.length();
    //     int ans = 0;
    //     auto validCnt = [=](int start) {
    //         int cnt = 0;
    //         int maxLen = 0;
    //         for (int i = start; i < n; ++i) {
    //             if (s[i] == '(') cnt++;
    //             else cnt--;
    //
    //             if (cnt < 0) return i - start;
    //             if (cnt == 0) maxLen = max(maxLen, i - start + 1);
    //         }
    //         return maxLen;
    //     };
    //
    //     for (int i = 0; i < n; ++i) {
    //         ans = max(ans, validCnt(i));
    //     }
    //     return ans;
    // }
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;

        return ans;
    }
};


int main() {
    Solution test;
    string s = "(()())";
    auto res = test.longestValidParentheses(s);
    cout << "res: " << res << endl;
}
