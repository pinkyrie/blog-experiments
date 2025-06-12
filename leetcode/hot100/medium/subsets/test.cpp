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
    // region dfs
    /*void dfs(const vector<int> &nums, vector<vector<int>>& res,
        vector<int>& current, int idx, int total_subsets) {
        if(res.size() < total_subsets) {
            res.push_back(current);
        }
        else {
            return; // all subsets are generated
        }
        for(int i = idx; i < nums.size(); i++) {
            current.push_back(nums[i]);
            dfs(nums, res, current, i + 1, total_subsets);
            current.pop_back(); // backtrack
        }

    }*/
    // endregion
public:
    // region dfs1
    /*vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        int total_subsets = 1 << len; // 2^len subsets
        vector<int> current = {};
        dfs(nums, result, current, 0, total_subsets);
        return result;
    }*/
    // endregion

    //region backtrack 1
    /*vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) { // 子集构造完毕
                ans.emplace_back(path);
                return;
            }

            // 不选 nums[i]
            dfs(i + 1);

            // 选 nums[i]
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back(); // 恢复现场
        };
        dfs(0);
        return ans;
    }*/
    // endregion

    // region backtrack 2
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        auto dfs = [&](this auto&& dfs, int i) -> void {
            ans.emplace_back(path);
            for (int j = i; j < n; j++) { // 枚举选择的数字
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back(); // 恢复现场
            }
        };
        dfs(0);
        return ans;
    }
    // endregion
};


int main() {
    Solution test;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = test.subsets(nums);

    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

}