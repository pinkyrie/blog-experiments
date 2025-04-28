/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    /* pull DP */
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // int dp[n] = {};
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[i] = nums[i];
            }
            else{
                dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            }
        }
        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            res = std::max(res, dp[i]);
        }
        return res;
    }

    /* push DP */
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     // int dp[n] = {};
    //     vector<int> dp(n, 0);
    //     for(int i = 0; i < n; i++){
    //         if(i == 0){
    //             dp[i] = nums[i];
    //         }
    //         if(i + 1 < n){
    //             dp[i + 1] = std::max(dp[i] + nums[i + 1], nums[i + 1]);
    //         }
    //     }
    //     int res = INT_MIN;
    //     for(int i = 0; i < n; i++){
    //         res = std::max(res, dp[i]);
    //     }
    //     return res;
    // }
};


int main(){
    Solution test;
    vector<int> nums = {5,4,-1,7,8};
    auto res = test.maxSubArray(nums);
    cout << "res: " << res << endl;
}

