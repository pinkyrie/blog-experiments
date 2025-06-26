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
        vector<int>& current, int idx, int k, int n) {
        if (current.size() == k && n == 0) {
                result.push_back(current);
            return;
        }

        for(int i = idx; i < 10; i++) {
            if (n - i < 0) {
                break; // 剪枝：剩余和不足以填满组合
            }
            current.push_back(i);
            dfs(result, current, i + 1, k, n - i);
            current.pop_back(); // 回溯
        }

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // 123456789
        vector<vector<int>> result;
        vector<int> current;
        dfs(result, current, 1, k, n);
        return result;

    }
};

int main() {
    Solution test;
    int k = 3, n = 7;
    vector<vector<int>> result = test.combinationSum3(k, n);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
}