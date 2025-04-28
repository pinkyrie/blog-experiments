#include <iostream>
#include <chrono>  // 用于记录运行时间

const int X = 5;
int memo[X+1];

int f(int x) {
    if (memo[x] != -1) return memo[x];
    if (x <= 2) return 1;
    else return memo[x] = f(x-1) + f(x-2);
}

int main() {
    // 初始化 memo 数组
    for (int i = 0; i <= X; i++) memo[i] = -1;

    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();

    // 计算答案
    int ans = f(X);

    // 记录结束时间
    auto end = std::chrono::high_resolution_clock::now();

    // 计算并输出运行时间
    std::chrono::duration<double> duration = end - start;
    std::cout << "答案: " << ans << std::endl;
    std::cout << "运行时间: " << duration.count() << " 秒" << std::endl;

    return 0;
}
