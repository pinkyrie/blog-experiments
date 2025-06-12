//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
private:
    void dfs(const string & digits,  const unordered_map<int, string> &phoneMap,
        int idx, string & current_group, vector<string> &result) {
        cout <<"idx:" << idx << "digits size:" <<  digits.size() << endl;

        if(idx == digits.size()) {
            result.push_back(current_group);
            return;
        }
        int digit = digits[idx] - '0';
        cout << "digit:" << digit << endl;
        string letters = phoneMap.at(digit);
        for (char letter : letters) {
            current_group.push_back(letter);
            dfs(digits, phoneMap, idx + 1, current_group, result);
            current_group.pop_back(); // backtrack
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> phoneMap = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        string combination = "";
        dfs(digits, phoneMap, 0, combination, result);
        return result;

    }
};


int main() {
    Solution test;
    string digits = "23";
    vector<string> result = test.letterCombinations(digits);
    for (const string &s : result) {
        cout << s << " ";
    }
}