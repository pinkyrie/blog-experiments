#include <iostream>
#include <vector>


using namespace std;

// 定义颜色枚举
enum Color { WHITE, GRAY, BLACK };
// record global traversing time
int timeCounter = 0;
// recursive search
void DFS_VISIT(int u, const vector<vector<int>>& graph, vector<Color>& color, vector<int>& discovery, vector<int>& finish, vector<int>& parent) {
    // discovering u
    timeCounter += 1;
    discovery[u] = timeCounter;
    color[u] = GRAY;
    // traversing u's neighboring vertexes
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(color[v] == WHITE) {
            parent[v] = u;
            // recursively search the deepest reachable vertexes
            DFS_VISIT(v, graph, color, discovery, finish, parent);
        }
    }
    // finish traversing u
    color[u] = BLACK;
    timeCounter += 1;
    finish[u] = timeCounter;
}
void DFS(const vector<vector<int> > &graph, int V, vector<int> &parent) {
    // init
    vector<Color> color(V, Color::WHITE);
    vector<int> discovery(V, INT_MAX);
    vector<int> finish(V, INT_MAX);
    vector<int> distance(V, INT_MAX);
    timeCounter = 0; // 初始化全局时间
    // 遍历所有顶点
    for (int u = 0; u < V; ++u) {
        if (color[u] == WHITE) { // 如果顶点 u 未被发现
            DFS_VISIT(u, graph, color, discovery, finish, parent);
        }
    }
    // print finish time
    std::cout << "finish is" << std::endl;
    for(int u = 0; u < V; ++u) {
         std::cout << finish[u] << std::endl;
    }
    // print discover time
    std::cout << "discovery is" << std::endl;
    for(int u = 0; u < V; ++u) {
        std::cout << discovery[u] << std::endl;
    }
}

// 递归打印从源点 s 到目标点 v 的路径
void PRINT_PATH(const vector<int>& parent, int s, int v) {
    if (v == s) { // 如果目标点是源点，直接输出
        cout << s << " ";
    } else if (parent[v] == -1) { // 如果前驱是 -1，说明路径不存在
        cout << "No path from " << s << " to " << v << " exists" << endl;
    } else { // 递归回溯前驱节点
        PRINT_PATH(parent, s, parent[v]);
        cout << v << " ";
    }
}

void addDirectedEdge(vector<vector<int>>& adj,
                          int u, int v)
{
    adj[u].push_back(v);
}


int main() {

    // Number of vertices in the graph
    int V = 8;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);
    /* 0:1,2
     * 1:3
     * 2:4
     * 3:4,5
     * 4:5
     * 5:
     */
//    addDirectedEdge(adj, 5, 0);
//    addDirectedEdge(adj, 5, 2);
//    addDirectedEdge(adj, 2, 3);
//    addDirectedEdge(adj, 3, 1);
//    addDirectedEdge(adj, 4, 0);
//    addDirectedEdge(adj, 4, 1);
    addDirectedEdge(adj, 0, 1);
    addDirectedEdge(adj, 1, 2);
    addDirectedEdge(adj, 2, 3);
    addDirectedEdge(adj, 2, 4);
    addDirectedEdge(adj, 3, 0);
    addDirectedEdge(adj, 4, 5);
    addDirectedEdge(adj, 5, 6);
    addDirectedEdge(adj, 6, 4);
    addDirectedEdge(adj, 6, 7);

    for (int i = 0; i < adj.size(); ++i) { // 遍历每个顶点
        cout << i << ": "; // 输出当前顶点编号
        for (int j : adj[i]) { // 遍历当前顶点的邻接点
            cout << j << " ";
        }
        cout << endl;
    }
    vector<int> parent(V, -1);
    DFS(adj, V, parent);
    PRINT_PATH(parent, 0, 5);
    return 0;
}
