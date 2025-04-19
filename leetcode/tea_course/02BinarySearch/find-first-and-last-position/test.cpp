/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int res1 = lower_bound(nums, target);
        int res2 = lower_bound(nums,target  + 1) -1;
        if(res1 == 0 || nums[res1] != target) {
            return {-1, -1};
        }
        cout << "res1: " << res1 << endl;
        cout << "res2: " << res2 << endl;
        return {res1, res2};
    }
};

int main() {
    Solution test;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    auto res = test.searchRange(nums, target);
}
