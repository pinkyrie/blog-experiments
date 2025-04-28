#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 5000;
const int MAX_M = 5000;

int main() {
    int N, M;
    N = 3;
    M = 2;

    // 初始化 DP 数组
    vector<vector<long long>> DP(N + 1, vector<long long>(2, 0));

    // 初始状态
    DP[0][0] = DP[0][1] = 1; // 没有花时，红色和白色的排列方式各为1种

    // 动态规划状态填充
    for (int i = 0; i < N; i++) {
        // 如果当前花是红色（DP[i][0]），那么可以更新下一些位置的状态
        for (int j = 1; j <= M && i + j <= N; j++) {
            DP[i + j][1] += DP[i][0];  // 把 `i+1` 到 `i+j` 的位置更新为白色花
        }

        // 如果当前花是白色（DP[i][1]），那么可以更新下一些位置的状态
        for (int j = 1; j <= M && i + j <= N; j++) {
            DP[i + j][0] += DP[i][1];  // 把 `i+1` 到 `i+j` 的位置更新为红色花
        }
    }

    // 最终结果是考虑最后一朵花是红色或白色的所有排列方式
    long long result = DP[N][0] + DP[N][1];
    cout << result << endl;

    return 0;
}