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
public:

/* region brute force  */
//int subarraySum(vector<int>& nums, int k) {
//    int count = 0;
//    for(int i = 0; i < nums.size(); i++) {
//        int sum = 0;
//        for (int j = i; j >= 0; j--) {
//            sum += nums[j];
//            if(sum == k) {
//                count++;
//            }
//        }
//    }
//    return count;
//}
/* endregion */

/* region presum + hash */
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    int count = 0;
    int sum = 0;
    map.insert({0,1}); // 0 sum
    for(int i: nums) {
        sum += i;
        if(map.find(sum - k) != map.end()) {
            count += map[sum - k];
        }
        map[sum] ++;
    }
    return count;
}
/* endregion */

};



int main() {
    Solution test;
    // vector<int> nums = {1, 1, 1};
    // int k = 2;
    vector<int> nums = {6,4,3,1};
    int k = 10;
    cout << test.subarraySum(nums, k) << endl;
}