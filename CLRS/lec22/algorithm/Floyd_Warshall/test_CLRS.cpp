#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // 定义无穷大值

// 打印路径的递归函数
void printPath(const vector<vector<int>>& predecessor, int start, int end) {
    if (start == end) {
        cout << start << " ";
        return;
    }
    if (predecessor[start][end] == -1) {
        cout << "No path";
        return;
    }
    printPath(predecessor, start, predecessor[start][end]);
    cout << end << " ";
}

// Floyd-Warshall算法实现
void floydWarshall(vector<vector<int>>& W, vector<vector<int>>& predecessor) {
    int n = W.size();
    vector<vector<int>> D = W; // 距离矩阵初始化为权重矩阵W

    // 初始化前驱矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && W[i][j] != INF) {
                predecessor[i][j] = i; // 如果有边(i, j)，前驱节点为i
            } else {
                predecessor[i][j] = -1; // 无法到达时设置为-1
            }
        }
    }

    // 动态规划的核心部分
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (D[i][k] != INF && D[k][j] != INF && D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    predecessor[i][j] = predecessor[k][j]; // 更新前驱矩阵
                }
            }
        }
    }

    // 打印最终的距离矩阵
    cout << "Shortest Distance Matrix (D):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (D[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << D[i][j];
        }
        cout << endl;
    }

    // 打印最终的前驱矩阵
    cout << "\nPredecessor Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(5) << predecessor[i][j];
        }
        cout << endl;
    }

    // 打印路径示例
    cout << "\nPaths between all pairs:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Path from " << i << " to " << j << ": ";
            if (D[i][j] == INF)
                cout << "No path" << endl;
            else {
                printPath(predecessor, i, j);
                cout << endl;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> W(n, vector<int>(n)); // 权重矩阵
    vector<vector<int>> predecessor(n, vector<int>(n)); // 前驱矩阵

    cout << "Enter the adjacency matrix (use INF for no edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string input;
            cin >> input;
            if (input == "INF")
                W[i][j] = INF;
            else
                W[i][j] = stoi(input);
        }
    }

    floydWarshall(W, predecessor);

    return 0;
}
