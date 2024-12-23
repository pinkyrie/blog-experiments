#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function CUT-ROD
int CUT_ROD(const vector<int>& p, int n) {
    // Base case: if n == 0, the revenue is 0
    if (n == 0) {
        return 0;
    }

    int q = -1;  // Initialize the maximum revenue q to a small value
    for (int i = 1; i <= n; i++) {
        // Maximize the revenue by considering cutting the rod at position i
        q = max(q, p[i-1] + CUT_ROD(p, n - i)); // p[i-1] is the price for length i
    }
    return q; // Return the maximum revenue
}

int main() {
    // Define the price list for lengths 1 to n (prices are 1-indexed)
    vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; // Prices for lengths 1 to 10

    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    // Call CUT-ROD function to get the maximum revenue for the rod of length n
    int maxRevenue = CUT_ROD(p, n);

    // Output the result
    cout << "Maximum revenue for a rod of length " << n << " is: " << maxRevenue << endl;

    return 0;
}
