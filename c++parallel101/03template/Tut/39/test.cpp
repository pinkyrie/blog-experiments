#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node * next;
    Node (T data): data(data), next(nullptr) {}
    void print() {
        cout << data << endl;
    }
};

struct normalNode {
    int data;
    normalNode (int data): data(data) {}
    void print() {
        cout << data << endl;
    }
};

int main() {
    //auto node1{1};
    //auto node2{2.8};
    Node node1{1};
    Node node2{2.8};
    cout << node1.data << endl;
    cout << node2.data << endl;
}
