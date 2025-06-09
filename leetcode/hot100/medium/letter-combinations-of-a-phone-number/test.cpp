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
    void dfs(vector<int>& nums, int target, int sum, int index, int& count) {
        if(index == nums.size()) {
            if(sum == target) {
                count += 1;
            }
            return;
        }
        dfs(nums, target, sum + nums[index], index + 1, count);
        dfs(nums, target, sum - nums[index], index + 1, count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        int idx = 0;
        int sum = 0;
        dfs(nums, target, sum,idx,count);
        return count;
    }
};



int main() {
    Solution test;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    cout << test.findTargetSumWays(nums, target) << endl;
}