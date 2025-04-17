#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/* created by Matoka in 2025-03-25 21:08:23 */
using namespace std;

void max_heapify(vector<int>& A, int i, int size) {
    int n = size;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && A[l] > A[largest]) {
        largest = l;
    }
    if (r < n && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(A[i], A[largest]);
        max_heapify(A, largest, n);
    }
}

void build_max_heap(vector<int>& A) {
    int n = A.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(A, i, n);
    }
}

void heap_sort(vector<int>& A) {
    build_max_heap(A);
    int n = A.size();
    for (int i = n - 1; i >= 1; i--) {
        std::swap(A[0], A[i]);
        n--;
        max_heapify(A, 0, n);
    }
}


int main() {
    vector<int> nums = {4,1,3,2,16,9,10,14,8,7};
    heap_sort(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    return 0;
}