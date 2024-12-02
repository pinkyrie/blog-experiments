#include <iostream>
using namespace std;

template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(true ? a : b) {
	return a > b ? a : b;
}

int main() {
	int x = 10;
	double y = 20.5;

	// 调用 max 函数，自动推导返回类型
	auto result = max(x, y);  // 这里会根据 `a` 和 `b` 的类型推导返回类型

	cout << "The max value is: " << result << endl;  // 输出：20.5

	return 0;
}