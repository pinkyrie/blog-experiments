#include<iostream>
#include <type_traits>

/*template<typename T1, typename T2,
typename RT = std::decay_t<decltype(true ? T1() : T2())>> //use decay_t for c++14*/
template<typename T1, typename T2,
typename RT = typename std::decay<decltype(true ? T1() : T2())>::type >//use this for c++11
RT max (T1 a, T2 b)
{
    return b < a ? a : b;
}
int main(){
  std::cout << max(1, 2.5) << '\n';
}