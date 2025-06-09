/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <cstring>
#include <stack>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        function <int(int, int)> dfs = [&] (int i, int j) -> int{
            if(i + 1 >= j) return 0;//这个时候i,j中间没有可以戳破的气球
            if(dp[i][j] != -1) return dp[i][j];
            int &res = dp[i][j];
            for(int k = i + 1; k <= j - 1; k++){
                res = max(res, dfs(i, k) + dfs(k, j) + nums[i] * nums[k] * nums[j]);
            }
            return res;
        };
        return dfs(0, n - 1);
    }
};

// int main() {
//     Solution test;
//     vector<int> nums = {3, 1, 5, 8};
//     auto res = test.maxCoins(nums);
//     cout << "res: " << res << endl;
// }
