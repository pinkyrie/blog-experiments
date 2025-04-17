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
    int trap(vector<int>& height) {
        int res = 0;
        int volume = 0;
        // one direction stack
        stack<int> st;
        st.push(0);
        for(int i = 1; i < height.size(); i++) {
            if(height[i] <= height[st.top()]) {
                st.push(i);
                continue;
            }
            // else if(height[i] > height[st.top()]) {
            //     while(!st.empty()) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if(st.empty()) {
                    break;
                }
                int left = st.top();
                int w = i - left - 1;
                int h = min(height[left], height[i]) - height[top];
                if(h > 0) {
                    volume = w * h;
                }
                res += volume;
            }
            st.push(i);
        }
        return res;
    }
};
int main() {
    Solution test;
    vector<int> height = {4,2,0,3,2,5}; // 9
    cout << test.trap(height) << endl;
}