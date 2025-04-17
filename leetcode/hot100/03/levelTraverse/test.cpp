#include<iostream>
#include<queue>
#include<vector>
#include <algorithm> // 用于 std::max 函数
using namespace std;

/* 二叉树的层序遍历 */

// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 计算二叉树的层数（深度）
int getTreeDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;  // 空节点深度为 0
    }
    // 递归计算左子树和右子树的深度，返回更大的那个深度 + 1
    int leftDepth = getTreeDepth(root->left);
    int rightDepth = getTreeDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

// 该方法会导致leetcode爆内存
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    TreeNode* p = root;
    queue<TreeNode*> qu;
    qu.push(p);
    int layers = getTreeDepth(root);
    int cnt = 1;

    for (int i = 0; i < layers; i++) {
        cnt = 1 << i;
        vector<int> layer_nodes;
        while (cnt > 0) {
            TreeNode* node = qu.front();
            qu.pop();
            cnt -= 1;
            if(node == nullptr) {
                qu.push(nullptr);
                qu.push(nullptr);
                continue;
            }
            layer_nodes.push_back(node->val);
            qu.push(node->left);
            qu.push(node->right);
            // if (node->left != nullptr) {
            //     qu.push(node->left);
            // }
            // if (node->right != nullptr) {
            //     qu.push(node->right);
            // }
        }
        res.push_back(layer_nodes);
    }
    return res;
}

// 该方法是官方解
vector<vector<int>> levelOrder_final(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentSize = q.size();
        vector<int> layer;
        for (int i = 0; i < currentSize; i++) {
            TreeNode* node = q.front();
            if (node != nullptr) {
                layer.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            q.pop();
        }
        if(layer.size() > 0){
            res.push_back(layer);
        }
    }
    return res;
}

int main() {
    // 构建一个简单的二叉树
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);

    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);

    // 计算并输出二叉树的层数
    // cout << "The depth of the binary tree is: " << getTreeDepth(root) << endl;
    // int num1 = 1<<2;
    // int num2 = 3<<4;
    // int num3 = 1<<2+3<<4;
    // cout << num1 << endl;
    // cout << num2 << endl;
    // cout<<num3<<endl;
    vector<vector<int>> res = levelOrder_final(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}