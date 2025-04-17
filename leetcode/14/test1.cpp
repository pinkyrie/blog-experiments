//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
class Solution {
public:
    std::string longestCommonPrefix(std::vector<string>& strs) {
        std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {
       return std::strcmp(a.c_str(), b.c_str()) < 0;  // 返回 a < b 以按字典序排序
   });

        // 打印排序后的结果
        std::cout << "Sorted vector: \n";
        for (const auto& str : strs) {
            std::cout << str << " ";
        }
        std::cout << std::endl;

        // 获取字典序最小和最大的字符串
        std::cout << "First (smallest) element: " << strs.front() << std::endl;
        std::cout << "Last (largest) element: " << strs.back() << std::endl;
        string res = "";
        for(int i = 0; i < strs.front().length(); i++) {
            if(strs.front()[i] == strs.back()[i]) {
                res += strs.front()[i];
            } else {
                break;
            }
        }
        return res;
    }

};
int main() {
    Solution test;
    vector<string> teststrs = {"flower","flow","flight"};
    // vector<string> teststrs = {"flower","flow","flight"};
    cout << "res:" << test.longestCommonPrefix(teststrs) <<endl;
}