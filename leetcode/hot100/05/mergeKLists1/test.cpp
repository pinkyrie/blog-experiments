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



int main() {
    // Creating a priority queue of integers
    priority_queue<int> pq;
    pq.push(9);
    pq.push(10);
    pq.push(6);

    cout << pq.top() << " ";
    return 0;
}
