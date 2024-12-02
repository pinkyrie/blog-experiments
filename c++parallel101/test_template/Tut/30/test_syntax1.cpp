#include <iostream>
#include <type_traits>
using namespace std;

template<typename RT = int, typename T1, typename T2>
RT max (T1 a, T2 b)
{
    return b < a ? a : b;
}

int main() {
    auto result = max<long>(1, 2.8);
    auto result1 = max(1.5,2.8);
    // auto result = max(1, 2.8);
    cout << result << endl;
    cout << result1 << endl;
}
