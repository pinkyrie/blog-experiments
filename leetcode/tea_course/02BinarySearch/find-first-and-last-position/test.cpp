/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left != right){
            int mid = (left + right) / 2; // 0+5)/2=2
            if(nums[mid] <= target){
                left = mid;
            }
        }
    }
};

int main() {
    Solution test;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    auto res = test.searchRange(nums, target);
}
