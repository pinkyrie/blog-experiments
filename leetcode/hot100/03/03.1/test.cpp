//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nums = {-10,9,20,0,0,15,7};
        stringstream ss(data);
        TreeNode *root = new TreeNode(nums[0]);
        TreeNode *cur = root;
        for(int i = 0; i < nums.size(); i++) {
            TreeNode* left = new TreeNode(nums[2*i+1]);
            TreeNode* right = new TreeNode(nums[2*i+2]);
            cur -> left = left;
            cur -> right = right;
       }
    }
};

int main() {
    std::string str = "1,2,3,4";  // 输入的字符串
    std::stringstream ss(str);     // 将字符串转换为字符串流
    std::string temp;
    std::vector<int> result;

    // 按照逗号分割字符串并将每个部分转换为整数
    while (std::getline(ss, temp, ',')) {
        result.push_back(std::stoi(temp));  // 使用 stoi 将字符串转换为整数并添加到 vector 中
    }

    // 打印结果
    std::cout << "Vector contents: ";
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}