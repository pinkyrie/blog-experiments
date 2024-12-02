#include <iostream>
using namespace std;

template<typename T1, typename T2>
T1 max (T1 a, T2 b)
{
	return a > b ? a : b;
}
int main() {
	auto m = ::max(7.2,4 ); // OK, but type of first argument defines return type
	cout << m << endl;
}
// 7.2