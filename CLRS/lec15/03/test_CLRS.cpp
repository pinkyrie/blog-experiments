#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Function prototypes
int memoized_cut_rod_aux(const std::vector<int>& p, int n, std::vector<int>& r);
int memoized_cut_rod(const std::vector<int>& p, int n);

// Main function to demonstrate the memoized cut rod
int main() {
    // Example price vector where p[i] is the price of a rod of length i
    std::vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; // p[0] is unused
    int n;
    std::cout << "Enter the length of the rod: ";
    std::cin >> n;

    int max_profit = memoized_cut_rod(p, n);
    std::cout << "Maximum profit for rod of length " << n << " is " << max_profit << std::endl;

    return 0;
}

// Memoized Cut Rod function
int memoized_cut_rod(const std::vector<int>& p, int n) {
    // Initialize memoization array with -1
    std::vector<int> r(n + 1, -1);
    return memoized_cut_rod_aux(p, n, r);
}

// Helper function for memoization
int memoized_cut_rod_aux(const std::vector<int>& p, int n, std::vector<int>& r) {
    if (r[n] >= 0) {
        return r[n];
    }
    int q;
    if (n == 0) {
        q = 0;
    } else {
        q = std::numeric_limits<int>::min();
        for (int i = 1; i <= n; ++i) {
            if (i < p.size()) { // Ensure i is within the price vector
                q = std::max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
            }
        }
    }
    r[n] = q;
    return q;
}
