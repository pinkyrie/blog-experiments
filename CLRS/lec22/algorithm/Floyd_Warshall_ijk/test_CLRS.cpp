#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <fstream>
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
    for (int k = 0; k < n; ++k) { // 中间节点
        for (int i = 0; i < n; ++i) { // 起点
            for (int j = 0; j < n; ++j) { // 终点
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
    // 打开输入文件
    ifstream inputFile("D:\\codingstack\\blog-experiments\\CLRS\\lec22\\algorithm\\Floyd_Warshall_ijk\\input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }

    int n; // 节点数
    inputFile >> n; // 从文件读取节点数

    vector<vector<int>> graph(n, vector<int>(n)); // 初始化权重矩阵
    vector<vector<int>> predecessor(n, vector<int>(n)); // 初始化前驱矩阵

    // 从文件中读取矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string value;
            inputFile >> value;
            if (value == "INF") {
                graph[i][j] = INF; // 将 "INF" 转换为数值无穷大
            } else {
                graph[i][j] = stoi(value); // 将字符串转换为整数
            }
        }
    }

    inputFile.close(); // 关闭文件

    // 调用 Floyd-Warshall 算法
    floydWarshall(graph, predecessor);

    return 0;
}
