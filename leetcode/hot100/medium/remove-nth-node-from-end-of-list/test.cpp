//
// Created by Admini    strator on 25-2-8.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>


using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    if(values.size() == 1)
        return new ListNode(values[0]);
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

class Solution {
public:
    // region naive
    /*
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1, 2, 3, 4, 5
        int len = 0;
        for (ListNode* cur = head; cur != nullptr;) {
            cur = cur->next;
            len += 1;
        }
        // len 5
        cout << "len = " << len << endl;
        // 链表dummy结点
        int idx = len - n;
        // idx 3
        ListNode* p = head;
        ListNode* prev = head;
        for (int i = 0; i < idx; i++) {
            prev = p;
            p = p->next;
        }
        if(idx == 0) {
            head = head -> next;
            delete p;
            return head;
        }
        cout << "prev = " << prev->val << endl;
        cout << "p = " << p->val << endl;
        // cout << p -> next << endl;
        // cout << p -> next ->val << endl;
        prev->next = p->next;
        delete p; // 删除指针和清空内存顺序
        return head;
    }
    */
    // endregion

    // region two pointers
    /*ListNode* removeNthFromEnd(ListNode* head, int n) {
        // n = 2
        // {1, 2, 3, 4, 5}
        ListNode * fast = head;
        ListNode * slow = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next; // fast 指针先走 n 步
        }
        // fast = 3
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next; // fast 指针走到末尾
            slow = slow->next; // slow 指针和 fast 指针一起走
        }
        // fast = 5
        // slow = 3
        if(slow == head && fast == nullptr) {
            // 删除头结点
            ListNode* temp = head;
            head = head->next; // 头结点指向下一个节点
            delete temp; // 删除原来的头结点
            return head;
        }
        cout << "slow = " << slow->val << endl;
        cout << "fast = " << (fast ? to_string(fast->val) : "nullptr") << endl;
        // 删除 slow 的下一个节点
        ListNode* temp = slow -> next;
        slow -> next = slow -> next -> next; // slow 指针的下一个节点指向下下个节点
        delete temp; // 删除原来的下一个节点
        return head;
    }*/
    // endregion

    // region dummy node
    /*ListNode* removeNthFromEnd(ListNode* head, int n) {
        // {1, 2, 3, 4, 5} 0 ->1,2,3,4,5
        // n = 2
        ListNode * dummy = new ListNode(0); // 创建一个虚拟头结点
        dummy->next = head; // 虚拟头结点指向原头结点
        ListNode * fast = dummy; // 快指针从虚拟头结点开始
        ListNode * slow = dummy; // 慢指针也从虚拟头结点开始
        for(int i = 0; i < n; i++) {
            fast = fast -> next; // 快指针先走 n 步
        }
        // fast = 2
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next; // 快指针走到末尾
            slow = slow->next; // 慢指针和快指针一起走
        }
        // fast = 5
        // slow = 3
        ListNode* temp = slow->next; // 保存要删除的节点
        slow -> next = slow -> next -> next; // 慢指针的下一个节点指向下下个节点
        delete temp; // 删除原来的下一个节点
        ListNode* result = dummy->next; // 返回虚拟头结点的下一个节点
        delete dummy; // 删除虚拟头结点
        return result; // 返回新的头结点
    }*/
    // endregion
};

int main() {
    Solution test;
    // vector<int> values = {1, 2, 3, 4, 5};
    vector<int> values = {1}; // 测试用例
    ListNode* head = createLinkedList(values);
    int n = 1; // 删除倒数第2个节点
    ListNode* result = test.removeNthFromEnd(head, n);
    printLinkedList(result);
    cout << "test";
}