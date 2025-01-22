#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

std::tuple<int,int,int> find_across_mid(const vector<int> &arr, const int low, const int mid, const int high){
    int max_left = low;
    int max_right = high;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    // left sum
    for(int i = mid; i >= low; i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    // right sum
    sum = 0;
    for(int i = mid + 1; i <= high; i++){
        sum += arr[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    return std::make_tuple(max_left, max_right, left_sum+right_sum);
};

std::tuple<int,int,int> find_max_subarray(const vector<int> &arr, const int low, const int high) {
    // base casa
    if(low == high) {
        return std::make_tuple(low, high, arr[low]);
    }
    else {
        int mid = low + (high - low) / 2;
        auto [left_low, left_high, left_sum] = find_max_subarray(arr, low, mid);
        auto [right_low, right_high, right_sum] = find_max_subarray(arr, mid + 1, high);
        auto [cross_low, cross_high, cross_sum] = find_across_mid(arr, low, mid, high);

        // Return the maximum of the three options
        if (left_sum >= right_sum && left_sum >= cross_sum) {
            return make_tuple(left_low, left_high, left_sum);
        } else if (right_sum >= left_sum && right_sum >= cross_sum) {
            return make_tuple(right_low, right_high, right_sum);
        } else {
            return make_tuple(cross_low, cross_high, cross_sum);
        }
    }
};
int main() {
    // Example usage
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example array
    int n = A.size();

    auto [low, high, sum] = find_max_subarray(A, 0, n - 1);

    cout << "Maximum subarray is from index " << low << " to " << high << " with sum " << sum << endl;

    return 0;
}