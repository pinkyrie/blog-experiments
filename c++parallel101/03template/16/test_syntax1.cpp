#include<iostream>
#include <type_traits>
template<typename T1, typename T2>
std::common_type_t<T1,T2> max (T1 a, T2 b)
{
    return b < a ? a : b;
}
int main(){
  std::cout << max(1, 2.3) << '\n';
}