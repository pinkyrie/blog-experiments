#include<iostream>
#include<queue>
#include<vector>
#include <algorithm> // 用于 std::max 函数
#include<sstream>
#include <climits> // For INT_MIN
using namespace std;

/* 二叉树的层序遍历 */

// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

string serialize(TreeNode *root) {
    // 层次遍历
    string res = "[";
    if (root == nullptr) {
        return "[]";
    }
    queue<TreeNode *> q;
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
            if (!res.empty() && res.back() == ',') {
                // 检查末尾是否是逗号
                res.back() = ']'; // 直接替换最后一个字符为 ']'
            }
            // cout << " res1: " << res;
            return res;
        }
        for (int i = 0; i < currentSize; i++) {
            TreeNode *node = q.front();
            q.pop();
            if (node != nullptr) {
                // res += (node->val + '0');
                res += (std::to_string(node->val));
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
    if (!res.empty() && res.back() == ',') {
        // 检查末尾是否是逗号
        res.back() = ']'; // 直接替换最后一个字符为 ']'
    }
    return res;
}

TreeNode *deserialize(string data) {
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
    TreeNode *root = nullptr;;
    queue<TreeNode *> q;
    if (nodes[0] != "null") {
        root = new TreeNode(stoi(nodes[0]));
        q.push(root);
    }

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode *cur = q.front();
        q.pop();

        // 为当前节点的左子树构建节点
        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left); // 左子节点加入队列
        }
        i++;

        // 为当前节点的右子树构建节点
        if (i < nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right); // 右子节点加入队列
        }
        i++;
    }

    return root;
}

std::pair<int,int> reGetSum(TreeNode *root, int & res) {
    if(root == nullptr) {
        return {0, res};
        // 0, res ?
    }
    int leftVal = reGetSum(root->left, res).first;
    int rightVal = reGetSum(root->right, res).first;
    int longerLen = std::max(std::max(leftVal, rightVal) + root -> val,root ->val);
    int r1 = root -> val;
    int r2 = leftVal + root -> val;
    int r3 = rightVal + root -> val;
    int r4 = leftVal + rightVal + root -> val;
    res = std::max(res, std::max(std::max(r1, r2), std::max(r3, r4)));
    // res = std::max(leftVal + rightVal + root -> val,res);
    return {longerLen, res};


}

// stack
int maxPathSum(TreeNode *root){
    int res = INT_MIN;
    return reGetSum(root, res).second;
}


int main() {
    // string str = "[-10,9,20,null,null,15,7]";
    // string str= "[2,-1]";
    string str = "[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]";
    auto tree = deserialize(str);
    auto result = maxPathSum(tree);
    cout << "res:" << result << endl;

}
