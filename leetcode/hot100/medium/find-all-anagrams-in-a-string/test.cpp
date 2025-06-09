//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
class Solution {
private:
    void backtrack(const unordered_map<char,string>& phoneMap,
        const string& digits, int index, string& current, vector<string>& result) {
        if(index == digits.size()) {
            result.push_back(current);
            return;
        }
        char digit = digits[index];
        const string& letters = phoneMap.at(digit);
        for(char letter: letters) {
            current.push_back(letter);
            backtrack(phoneMap, digits, index + 1, current, result);
            current.pop_back(); // 回溯
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map <char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> result;
        if(digits.empty()) {
            return result; // 如果输入为空，直接返回空结果
        }
        string current;
        backtrack(phoneMap, digits, 0, current, result);
        return result;

    }
};


int main() {
    Solution test;
    string digits = "23";
    vector<string> result = test.letterCombinations(digits);
    for (const string& str : result) {
        cout << str << " ";
    }
}