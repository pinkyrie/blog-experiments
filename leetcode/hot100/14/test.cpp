//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
int main() {
    Solution test;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << test.singleNumber(nums) << endl;
}