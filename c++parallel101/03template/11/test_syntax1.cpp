#include <iostream>
using namespace std;

template<typename T1, typename T2>
T1 max (T1 a, T2 b)
{
	return b < a ? a : b;
}
int main() {
	auto m = ::max(4, 7.2); // OK, but type of first argument defines return type
	cout << m << endl;
}
// 7