#include <iostream>
#include <utility>
using namespace std;

template<typename RT = int, typename T1, typename T2>
RT max (T1 a, T2 b)
{
    return b < a ? a : b;
}


int main() {
    auto result = max(1, 2.8);
    cout << result << endl;

}