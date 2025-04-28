/* created by Matoka in 2025-03-26 00:19:46 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res; // 存储所有的合法结果

        // 初始条件：如果字符串为空，则直接返回一个空字符串
        if (s.empty()) {
            res.push_back("");
            return res;
        }

        // 初始化 BFS 的队列和已访问的集合
        queue<string> q;
        q.push(s);
        unordered_set<string> visited; // 用于存储已经检查过的字符串，防止重复检查
        visited.insert(s);

        bool found = false;  // 是否已找到至少一个合法的字符串

        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> currentLevel; // 当前层级的所有字符串

            for (int i = 0; i < size; ++i) {
                string curr = q.front(); q.pop();

                // 使用辅助函数检查当前字符串是否为合法的括号组合
                if (isValid(curr)) {
                    res.push_back(curr);
                    found = true;  // 找到合法组合，后续就不再生成新的子串
                }

                // 如果已找到合法的组合，跳过当前循环
                if (found) continue;

                // 对当前字符串的每一个字符尝试删除，并生成新的子串
                for (int j = 0; j < curr.size(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue; // 跳过非括号字符
                    string next = curr.substr(0, j) + curr.substr(j + 1); // 生成子串

                    // 如果新的子串没有被访问过，加入到当前层级的集合
                    if (visited.find(next) == visited.end()) {
                        currentLevel.insert(next);
                    }
                }
            }

            // 如果已经找到合法的组合，停止 BFS
            if (found) break;

            // 将当前层级的所有未访问的子串加入队列
            for (const string& str : currentLevel) {
                q.push(str);
                visited.insert(str);
            }
        }

        return res;
    }

private:
    // 辅助函数，用于检查一个字符串是否为合法的括号组合
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;         // 左括号计数+1
            else if (c == ')') count--;   // 右括号计数-1

            // 如果右括号数量多于左括号，这是不合法的，可以直接返回false
            if (count < 0) return false;
        }
        return count == 0;  // 检查左右括号数量是否相等，相等则是合法的
    }
};



int main() {
    Solution test;
    string s = "()())()";
    auto res = test.removeInvalidParentheses(s);
    cout << "res: " << endl;
    for (const auto& str : res) {
        cout << str << endl;
    }
}
