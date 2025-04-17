//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include<queue>
#include<deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

ListNode* createList(vector<int> &nums) {
    ListNode *head = new ListNode();
    ListNode *p = head;
    for (auto &i : nums) {
        p->next = new ListNode(i);
        p = p->next;
    }
    return head->next;
}

void printList(ListNode *head) {
    ListNode *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}



ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<int> pq;
    for (auto &i : lists) {
        while (i) {
            pq.push(i->val);
            i = i->next;
        }
    }
    ListNode *res = new ListNode();
    ListNode *p = res;
    while (!pq.empty()) {
        p->next = new ListNode(pq.top());
        pq.pop();
        p = p->next;
    }
    return res->next;
}

int main() {
    // Creating a priority queue of integers
    // priority_queue<int> pq;
    // pq.push(9);
    // pq.push(10);
    // pq.push(6);
    // cout << pq.top() << " ";

    // test case
    vector<int> nums = {1, 2, 3, 4, 5};
    auto head = createList(nums);
    printList(head);

    vector<vector<int>> numsList = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode *> lists;
    return 0;
}
