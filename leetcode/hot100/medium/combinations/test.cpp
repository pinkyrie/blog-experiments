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
    // region test 选或不选
//     void dfs(vector<vector<int>> & result, vector<int> current,
//          int idx, int n, int k) {
//         if(current.size() == k) {
//             result.push_back(current);
//             return;
//         }
//
//         for(int i = idx; i <= n; i++) {
//             current.push_back(i);
//             dfs(result, current, i + 1, n, k);
//             current.pop_back(); // backtrack
//         }
//     }
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> result;
//         vector<int> current;
//         dfs(result, current, 1, n, k);
//         return result;
//     }
    // endregion
    void dfs(vector<vector<int>>& result, vector<int> current, int idx, int n,
            int k) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        if(n - idx + 1 < k - current.size()) {
            return; // 剪枝：剩余元素不足以填满组合
        }
        for(int i = idx; i <= n; i++) {
            current.push_back(i);
            dfs(result, current, i + 1, n, k);
            current.pop_back(); // 回溯
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(result, current, 1, n, k);
        return result;
    }
};

int main() {
    Solution test;
    int n = 4;
    int k = 2;
    vector<vector<int>> result = test.combine(n, k);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}