#include<iostream>
#include<queue>
#include<vector>


using namespace std;
#include <iostream>
#include <string>

void removeTrailingCommaAndReplace(std::string& str) {
    if (!str.empty() && str.back() == ',') {  // 检查末尾是否是逗号
        str.back() = ']';  // 直接替换最后一个字符为 ']'
    }
}
void fillBrackets(std::string& str, const std::string& content) {
    if (str.size() >= 2 && str.front() == '[' && str.back() == ']') {
        str.insert(1, content); // 在 '[' 之后插入字符串
    }
}


int main() {
    // queue<int> pq;
    // pq.push(3);
    // pq.push(5);
    // pq.push(1);
    // pq.push(2);
    // pq.push(4);
    // while(!pq.empty()) {
    //     cout << pq.front() << " ";
    //     pq.pop();
    // }
    vector<int> vec;
    // int num = 1;
    // for (int i = 0; i < 5; i++) {
    //     cout << num << " ";  // 输出当前值
    //     num = num << 1;  // 左移 1 位，相当于乘以 2
    // }
    // for(int i = 0; i < 5; i++) {
    //     vec.push_back(i);
    //     cout << "size:" << vec.size() << endl;
    //     cout << "capacity:" << vec.capacity() << endl;
    // }
    // int to char
    // int a = 1;
    // char b = a + '0';
    std::string test1 = "1,2,3,4,";
    std::string test2 = "hello,world,";
    std::string test3 = "noComma";

    removeTrailingCommaAndReplace(test1);
    removeTrailingCommaAndReplace(test2);
    removeTrailingCommaAndReplace(test3);

    std::cout << "Result 1: " << test1 << std::endl;
    std::cout << "Result 2: " << test2 << std::endl;
    std::cout << "Result 3: " << test3 << std::endl;    std::string str = "[]"; // 初始字符串
    fillBrackets(str, "1,2,3,4"); // 填充内容
    std::cout << str << std::endl; // 输出: [1,2,3,4]



    return 0;
}