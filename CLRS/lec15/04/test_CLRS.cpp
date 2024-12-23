#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int bottom_up_cut_rod(const std::vector<int>& p, int n) {
    // p[i] 表示长度为 i 的钢条价格（p[0]可忽略，仅为方便索引）
    // r[j] 将存储长度为 j 的钢条的最大利润
    std::vector<int> r(n + 1, 0);
    // 初始化 r[0] = 0
    // r 数组的其他值在计算过程中填充

    for (int j = 1; j <= n; ++j) {
        int q = std::numeric_limits<int>::min(); // 初始设为最小值，确保可以找到最大利润
        // 尝试所有可能的第一段切割长度 i
        for (int i = 1; i <= j; ++i) {
            // p[i] + r[j - i] 表示选择第一段长度为 i 的利润加上剩余 j-i 长度的最佳利润
            if (i < (int)p.size()) { // 确保 i 不超过价格表的长度
                q = std::max(q, p[i] + r[j - i]);
            }
        }
        r[j] = q;
    }
    return r[n];
}

int main() {
    // 示例价格表
    // p[i] 表示长度为 i 的钢条价格
    // p[0] 未使用，仅为索引方便
    std::vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    int n;
    std::cout << "length: ";
    std::cin >> n;

    int max_profit = bottom_up_cut_rod(p, n);
    std::cout << "length " << n << " profit " << max_profit << std::endl;

    return 0;
}
