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
    void dfs(int idx, vector<int>& current,
        vector<int>& has_chosen,
        vector<vector<int>> &res,
        vector<int>& nums, int i) {
        if(idx == nums.size()) {
            res.push_back(current);
            return;
        }
        for(int j = 0; j < nums.size(); j++) {
            if(has_chosen[j] == 0) { // 如果数字未被选择
                has_chosen[j] = 1; // 标记为已选择
                current.push_back(nums[j]); // 选择当前数字
                dfs(idx + 1, current, has_chosen, res, nums, j + 1);
                current.pop_back(); // 回溯，撤销选择
                has_chosen[j] = 0; // 恢复标记
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int idx = 0;
        vector<vector<int>> result;
        vector<int> current;
        vector<int> has_chosen(nums.size(), 0); // 标记已选择的数字
        dfs(idx, current, has_chosen, result, nums, 0);
        return result;
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