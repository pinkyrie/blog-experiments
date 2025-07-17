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
    void dfs(vector<vector<int>>& result,
        vector<int>& current, int idx, int pos, int set_nums, const vector<int>& nums) {
        if(result.size() == set_nums) {
            return; // 所有排列已生成
        }
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for(int i = pos; i < nums.size(); i++) {
            current[i] = nums[idx]; // 选择当前数字
            dfs(result, current, idx + 1, pos + 1, set_nums, nums);

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        int len = nums.size();
        int set_nums = 1;
        for(int i = 1; i <= len; i++) {
            set_nums *= i; // 计算排列数
        }

    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = test.permute(nums);
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
}