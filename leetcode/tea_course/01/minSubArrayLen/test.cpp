/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// n^2 solution
// class Solution {
// public:
     // int minSubArrayLen(int target, vector<int>& nums) {
     //     int minLen = 0;
     //     for (int i = 0; i < nums.size(); i++) {
     //         int sum = nums[i];
     //         if (sum >= target) {
     //             minLen = 1;
     //         }
     //         for (int j = i + 1; j < nums.size(); j++) {
     //             sum += nums[j];
     //             if (sum >= target) {
     //                 if (minLen == 0) {
     //                     minLen = j - i + 1;
     //                 } else {
     //                     minLen = std::min(minLen, j - i + 1);
     //                 }
     //             }
     //         }
     //     }
     //     return minLen;
//     }
// };

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int minLen = INT_MAX;
        int sum = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while(sum >= target) {
                minLen = std::min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    Solution test;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << test.minSubArrayLen(target, nums) << endl;
}
