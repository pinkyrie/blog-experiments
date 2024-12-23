#include <iostream>
#include <queue>
#include <vector>


using namespace std;

// 定义颜色枚举
enum Color { WHITE, GRAY, BLACK };

void BFS(const vector<vector<int> > &graph, int V, int s, vector<int> &parent) {
    // init
    vector<Color> color(V, Color::WHITE);
    vector<int> distance(V, INT_MAX);

    queue<int> Q;
    // start from source
    color[s] = GRAY;
    distance[s] = 0;
    parent[s] = -1;
    Q.push(s);
    // traverse all the reachable vertexes
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(color[v] == Color::WHITE) {
                color[v] = Color::GRAY;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
        //all u's neighbors have been checked
        color[u] = Color::BLACK;
    }
    cout << "Vertex\tDistance\tParent\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << (distance[i] == INT_MAX ? -1 : distance[i])
             << "\t\t" << parent[i] << "\n";
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
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);
    /* 0:1,2
     * 1:3
     * 2:4
     * 3:4,5
     * 4:5
     * 5:
     */
    addDirectedEdge(adj, 0, 1);
    addDirectedEdge(adj, 0, 2);
    addDirectedEdge(adj, 1, 3);
    addDirectedEdge(adj, 2, 4);
    addDirectedEdge(adj, 3, 4);
    addDirectedEdge(adj, 3, 5);
    addDirectedEdge(adj, 4, 5);

    for (int i = 0; i < adj.size(); ++i) { // 遍历每个顶点
        cout << i << ": "; // 输出当前顶点编号
        for (int j : adj[i]) { // 遍历当前顶点的邻接点
            cout << j << " ";
        }
        cout << endl;
    }
    vector<int> parent(V, -1);
    BFS(adj, V, 0,parent);
    PRINT_PATH(parent, 0, 5);



    return 0;
}
