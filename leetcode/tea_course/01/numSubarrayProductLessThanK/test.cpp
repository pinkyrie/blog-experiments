/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        // l r
        int ans = 0;
        if (k == 1 || k == 0) {
            return 0;
        }
        int left = 0;
        int product = 1;
        for (int right = 0; right < nums.size(); right++) {
            // product

            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << test.numSubarrayProductLessThanK(nums, k) << endl;
}
