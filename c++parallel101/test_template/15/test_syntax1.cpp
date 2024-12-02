#include <iostream>
using namespace std;

// 模板函数 max，返回 T 类型的引用
template<typename T>
auto max(T&& a, T&& b) -> decltype(a > b ? a : b) {
    return a > b ? a : b;  // 返回 a 或 b 的引用
}

int main() {
    int x = 10;
    int y = 20;
    int& result = max(x, y);

    cout << result << endl;  // 输出 20
    result = 100;  // 修改 result
    cout << x << endl; //10
    cout << y << endl;  //100

    return 0;
}