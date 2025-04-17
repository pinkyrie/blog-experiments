#include <iostream>
using namespace std;

template<typename T1, typename T2>
auto max (T1 a, T2 b)
{
	return b < a ? a : b;
}
int main() {
	cout << max(1, 2.1) << endl;
}
//2.1