//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    std::string longestCommonPrefix(std::vector<string>& strs) {
        map<char, int> letter_map;
        if (strs.size() == 1) {
            return strs[0];
        }

        // 初始化所有字母的值为 0
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            letter_map[ch] = 0;
        }

        // // 输出所有字母及其对应的值
        // for (auto& pair : letter_map) {
        //     std::cout << pair.first << ": " << pair.second << std::endl;
        // }
        // for(string str: strs){
        //     std::cout << str << endl;
        // }
        // 使用 max_element 来找到长度最大的字符串
        auto max_str_it =
            std::max_element(strs.begin(), strs.end(),
                             [](const std::string& a, const std::string& b) {
                                 return a.size() < b.size(); // 比较字符串的长度
                             });

        // 输出最大长度的字符串
        if (max_str_it != strs.end()) {
            std::cout << "The longest string is: " << *max_str_it << std::endl;
            string longest_str = *max_str_it;
            int max_size = longest_str.size();
            std::cout << longest_str << std::endl;
            // ab
            int left = 0;                        // 0 0 1 // 0
            int right = max_size - 1;            // 5 2 2 // 1
            int mid = left + (right - left) / 2; // 2 1 1 // 0
            bool is_same = true;
            while (left <= right && mid < max_size) {
                for (string str : strs) {
                    if (str[mid] != longest_str[mid]) {
                        if(mid == 0) {
                            return "";
                        }
                        is_same = false;
                        right = mid;
                        mid = left + (right - left) / 2;
                        break;
                    }
                    is_same = true;
                }
                if(!is_same) {
                    continue;
                }
                left = mid;
                if(mid == left + (right - left) / 2) {
                    mid = min(left + (right - left) / 2 + 1, max_size);
                    break;
                }
                mid = left + (right - left) / 2;
            }

            std::cout << "pivot :" << mid << std::endl;
            string subres = longest_str.substr(0, mid + 1);
            std::cout << subres << std::endl;
            return subres;
        } else {
            std::cout << "The vector is empty." << std::endl;
        }
        return "";
    }
};
int main() {
    Solution test;
    vector<string> teststrs = {"flower","flower","flower","flower"};
    // vector<string> teststrs = {"flower","flow","flight"};
    cout << "res:" << test.longestCommonPrefix(teststrs) <<endl;
}