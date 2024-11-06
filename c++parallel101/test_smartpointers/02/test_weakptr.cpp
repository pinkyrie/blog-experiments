//
// Created by Matoka on 2024/11/6.
//
#include <iostream>
#include <memory>
struct Node : std::enable_shared_from_this<Node>{
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    int value;
    explicit Node(int val) {
        value = val;
    }

    void insert(int val) {
        auto node = std::make_shared<Node>(val);
        node->prev = shared_from_this();
        node->next = next;
        this->next = node;
    }

    void erase() {
        if (next)
            next->prev = prev;
        if (!prev.expired()) {
            prev.lock()->next= next;
        }
    }

    ~Node() {
        printf("~Node()\n");
    }
};
int main(){
    auto node1 = std::make_shared<Node>(1);
    auto node_weak = std::weak_ptr<Node>();
    node_weak = node1;
    std::cout << node_weak.lock()->value << std::endl;
 }
