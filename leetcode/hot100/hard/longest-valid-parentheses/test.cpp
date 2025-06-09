//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        // stack
        stack<int> st;
        // record last begin pos
        int last = -1;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(!st.empty()) {
                    last = st.top();
                    ans = max(ans, i - st.top() + 1);
                    st.pop();

                }
            }
        }
        return ans;
    }
};



int main() {
    Solution test;
    // string s = "(()))())(";
    string s = "()()";
    cout << test.longestValidParentheses(s) << endl;
}