#include <iostream>
#include <type_traits>
using namespace std;

template<typename T1, typename T2>
std::common_type_t<T1,T2> max (T1 a, T2 b)
{
    return b < a ? a : b;
}
int main() {
   auto res = ::max<double>(4, 7.2); // OK: return type is double, T1 and T2 are deduced
   cout << res << endl;
}

