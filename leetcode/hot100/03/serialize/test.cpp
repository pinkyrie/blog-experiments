#include<iostream>
#include<queue>
#include<vector>
#include <algorithm> // 用于 std::max 函数
#include<sstream>
using namespace std;

/* 二叉树的层序遍历 */

// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root) {
    // 层次遍历
    string res = "[";
    if (root == nullptr) {
        return "[]";
    }
    queue<TreeNode*> q;
    q.push(root);
    int endCnt = 0;
    while (q.size() > 0) {
        int currentSize = q.size();
        if (currentSize > endCnt) {
            endCnt = 0;
        }
        if (currentSize == endCnt) {
            // cout << "cur size:" << currentSize << endl;
            // cout << "endcnt:" << endCnt << endl;
            if (!res.empty() && res.back() == ',') { // 检查末尾是否是逗号
                res.back() = ']'; // 直接替换最后一个字符为 ']'
            }
            // cout << " res1: " << res;
            return res;
        }
        for (int i = 0; i < currentSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node != nullptr) {
                // res += (node->val + '0');
                res += (std::to_string(node -> val));
                q.push(node->left);
                q.push(node->right);
                if (node->left == nullptr) {
                    endCnt += 1;
                }
                if (node->right == nullptr) {
                    endCnt += 1;
                }
            } else {
                res += "null";
            }
            res += ',';
        }
    }
    // cout << " res2: " << res;
    if (!res.empty() && res.back() == ',') { // 检查末尾是否是逗号
        res.back() = ']'; // 直接替换最后一个字符为 ']'
    }
    return res;
}


// std::make_pair<TreeNode*,int> reDeserialize(int nodeIndex, vector<string>& vec) {
//     TreeNode* node;
//     int vecSize = vec.size();
//     //  cout << "cur node index:" << nodeIndex << endl;
//     // cout << "cur vec size:" << vecSize << endl;
//     if (nodeIndex >= vecSize) {
//         return nullptr;
//     }
//     // cout << "cur node index:" << nodeIndex << endl;
//     // cout << "cur node str:" << vec[nodeIndex] << endl;
//     if (vec[nodeIndex] == "null") {
//         return nullptr;
//     }
//     node = new TreeNode(stoi(vec[nodeIndex]));
//
//     TreeNode* leftChild = reDeserialize(nodeIndex * 2 + 1, vec);
//     TreeNode* rightChild = reDeserialize(nodeIndex * 2 + 2, vec);
//     node->left = leftChild;
//     node->right = rightChild;
//     return node;
// }

// std::pair<TreeNode*, int> reDeserialize(TreeNode * root, int nodeIndex, const vector<string>& vec) {
//     TreeNode * root = nullptr;;
//     int leftPivot = 0;
//     int RightPivot = 0;
//     if(nodeIndex == 0) {
//         root = new TreeNode(stoi(vec[nodeIndex]));
//         leftPivot = 1;
//         RightPivot = 2;
//     }
//     root -> left = reDeserialize(root -> left, leftPivot, vec).first;
//
//     root -> right = reDeserialize(root -> right, RightPivot, vec).first;
//     return std::make_pair(root, RightPivot);
// }

// TreeNode* deserialize(string data) {
//     // left:2*i +1 right: 2*i +2
//     if (data == "[]") {
//         return nullptr;
//     }
//
//     // string to vector
//     data = data.substr(1, data.size() - 2);
//     stringstream ss(data);
//     string item;
//     vector<string> nodes;
//
//     // 分割字符串
//     while (getline(ss, item, ',')) {
//         nodes.push_back(item);
//     }
//     size_t nodesSize = nodes.size();
//     TreeNode* root = reDeserialize(0, nodes);
//     return root;
// }

TreeNode* deserialize(string data) {
    // left:2*i +1 right: 2*i +2
    if (data == "[]") {
        return nullptr;
    }

    // string to vector
    data = data.substr(1, data.size() - 2);
    stringstream ss(data);
    string item;
    vector<string> nodes;

    // 分割字符串
    while (getline(ss, item, ',')) {
        nodes.push_back(item);
    }

    //level order traverse
    TreeNode* root = nullptr;;
    queue<TreeNode*> q;
    if (nodes[0] != "null") {
        root = new TreeNode(stoi(nodes[0]));
        q.push(root);
    }

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        // 为当前节点的左子树构建节点
        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);  // 左子节点加入队列
        }
        i++;

        // 为当前节点的右子树构建节点
        if (i < nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);  // 右子节点加入队列
        }
        i++;
    }

    return root;
}



int main() {
    // string str = "[5,2,3,null,null,2,4,3,1]";
    string str = "[1,2,3,null,null,4,5]";
    auto res = deserialize(str);
    // levelorder traverse the tree
    auto resStr = serialize(res);
    cout << "res:" << resStr << endl;
    return 0;
}