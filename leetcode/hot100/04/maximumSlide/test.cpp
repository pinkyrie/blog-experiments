//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include<deque>
using namespace std;



vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        // while
        while(!dq.empty() && nums[dq.back()] - nums[i] < 0) {
            dq.pop_back();
        }
        dq.push_back(i);
        // 出队和填入答案的顺序
        // 首先要判断队首元素是否在窗口内，因此先出队
        // 大于等于k vs 等于等于k 两种都是可以的
        if(i - dq.front() >= k) {
            dq.pop_front();
        }
        if(i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto res = maxSlidingWindow(nums, 3);
    for(auto &i : res) {
        cout << i << " ";
    }
    return 0;
}
