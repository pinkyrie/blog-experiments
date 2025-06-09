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
public:
    int leastInterval(vector<char>& tasks, int n) {
        // a a a b b b
        // a b a b a b
        int len = tasks.size();

        vector<int> freq(26, 0); // 26个字母的频率数组
        for(char c : tasks) {
            freq[c - 'A'] += 1; // 统计每个字母的频率
        }
        sort(freq.begin(), freq.end(), greater<int>()); // 按频率降序排序

        int cnt = 1;
        while (cnt < freq.size() && freq[cnt] == freq[0]) cnt++;

        int slot_size = n + 1;
        // slot num不能用除法算，因为不能计算最后一个桶，
        // int slot_num = len / slot_size;
        int slot_num = freq[0] - 1; // 最多的任务数减1
        cout << "slot num:" << slot_num << endl;
        cout << "freq[0] - 1:" << freq[0] - 1 << endl;
        int res1 = slot_size * slot_num + cnt;
        int res2 = len;
        return max(res1, res2); // 返回两种情况的最大值
        // for(int i : freq) {
        //     cout << i << " ";
        // }

        // unordered_map<char, int> freq;
        // for (char task : tasks) {
        //     freq[task]++;
        // }
    }
};


int main() {
    Solution test;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B', 'C'};
    // "A","C","A","B","D","B"
    // vector<char> tasks = {'A','C','A','B','D','B'};
    int n = 2;
    // int n = 1;
    cout << test.leastInterval(tasks, n) << endl; // 输出 8
}