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
    int maxCoinsHelper(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        int maxCoins = INT_MIN;
        for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1];
            // if(dp[i][j] != -1) return dp[i][j];
            int remainingCoins =
                maxCoinsHelper(i, k - 1, nums, dp) + maxCoinsHelper(k + 1, j, nums, dp);
            maxCoins = max(maxCoins, coins + remainingCoins);
            // dp[i][j] = maxCoins;
        }
        return maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return maxCoinsHelper(1, n, nums, dp);
    }
};

int main() {
    Solution test;
    vector<int> nums = {3, 1, 5, 8};
    auto res = test.maxCoins(nums);
    cout << "res: " << res << endl;
}
