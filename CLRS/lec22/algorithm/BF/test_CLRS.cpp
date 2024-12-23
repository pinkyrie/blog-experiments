#include <iostream>
#include <vector>
#include <climits> // 用于 INT_MAX
using namespace std;

// 定义边的数据结构
struct Edge {
    int u, v, weight;
};

// Bellman-Ford 算法实现
bool BellmanFord(int V, int E, vector<Edge>& edges, int source, vector<int>& distances) {
    // 初始化距离数组
    distances.assign(V, INT_MAX);
    distances[source] = 0;

    // 执行 |V| - 1 次松弛操作
    for (int i = 1; i <= V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    // 检查是否存在负权重环
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            // 如果还能松弛，说明存在负权环
            return false;
        }
    }

    // 如果没有负权环，返回 true
    return true;
}

int main() {
    // 顶点和边的数量
    int V = 5; // 顶点数
    int E = 8; // 边数

    // 定义边 (u, v, weight)
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    // 源点
    int source = 0;

    // 存储每个顶点的最短路径距离
    vector<int> distances;

    // 执行 Bellman-Ford 算法
    if (BellmanFord(V, E, edges, source, distances)) {
        cout << "Shortest distances from source " << source << ":" << endl;
        for (int i = 0; i < V; ++i) {
            if (distances[i] == INT_MAX) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Vertex " << i << ": " << distances[i] << endl;
            }
        }
    } else {
        cout << "The graph contains a negative weight cycle." << endl;
    }

    return 0;
}
