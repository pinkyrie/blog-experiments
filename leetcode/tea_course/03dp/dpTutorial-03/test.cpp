#include <iostream>
#include <chrono>  // 用于记录时间

using namespace std;

int f(int x) {
    if (x <= 2) return 1;
    else return f(x-1) + f(x-2);
}

int main() {
    int n = 20;  // 测试的 Fibonacci 数列的项

    // 记录开始时间
    auto start = chrono::high_resolution_clock::now();

    // 调用递归方法
    int result = f(n);

    // 记录结束时间
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "F(" << n << ") = " << result << endl;
    cout << "Execution Time: " << duration.count() << " seconds" << endl;

    return 0;
}