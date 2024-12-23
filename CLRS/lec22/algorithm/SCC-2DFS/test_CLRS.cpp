#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V; // 顶点数量
    unordered_map<int, vector<int>> adj; // 邻接表

    // 第一次 DFS：记录完成时间
    void DFSFirstPass(int v, vector<bool>& visited, stack<int>& finishStack) {
        visited[v] = true;

        // 递归访问所有邻居
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSFirstPass(neighbor, visited, finishStack);
            }
        }

        // 当前节点完成，加入栈中
        finishStack.push(v);
    }

    // 第二次 DFS：根据转置图找到 SCC
    void DFSSecondPass(int v, unordered_map<int, vector<int>>& transposeAdj, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);

        // 递归访问转置图中的邻居
        for (int neighbor : transposeAdj[v]) {
            if (!visited[neighbor]) {
                DFSSecondPass(neighbor, transposeAdj, visited, component);
            }
        }
    }

    // 构建转置图
    unordered_map<int, vector<int>> getTranspose() {
        unordered_map<int, vector<int>> transposeAdj;

        for (auto& pair : adj) {
            int u = pair.first;
            for (int v : pair.second) {
                transposeAdj[v].push_back(u); // 反转边
            }
        }

        return transposeAdj;
    }

public:
    // 构造函数
    Graph(int V) : V(V) {}

    // 添加边
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Kosaraju's Algorithm 找到强连通分量
    vector<vector<int>> findSCCs() {
        stack<int> finishStack;        // 存储完成时间的栈
        vector<bool> visited(V, false); // 记录节点是否访问
        vector<vector<int>> SCCs;     // 存储所有强连通分量

        // 第一次 DFS：记录完成时间
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSFirstPass(i, visited, finishStack);
            }
        }

        // 构建转置图
        unordered_map<int, vector<int>> transposeAdj = getTranspose();

        // 第二次 DFS：按照完成时间的顺序处理
        fill(visited.begin(), visited.end(), false); // 重置访问状态
        while (!finishStack.empty()) {
            int v = finishStack.top();
            finishStack.pop();

            if (!visited[v]) {
                vector<int> component; // 存储当前 SCC
                DFSSecondPass(v, transposeAdj, visited, component);
                SCCs.push_back(component); // 保存当前 SCC
            }
        }

        return SCCs;
    }
};

int main() {
    Graph g(8);

    // 添加图的边
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 4);
    g.addEdge(6, 7);

    // 找到强连通分量
    vector<vector<int>> SCCs = g.findSCCs();

    // 输出结果
    cout << "Strongly Connected Components:" << endl;
    for (const auto& component : SCCs) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
