#include <iostream>
#include <type_traits>
using namespace std;

template<typename T1, typename T2>
auto max (T1 a, T2 b)
{
    cout << "template 1 "<< endl;
    return b < a ? a : b;
}
template<typename RT, typename T1, typename T2>
RT max (T1 a, T2 b)
{
    cout << "template 2 "<< endl;
    cout<< typeid(T1).name() << endl;
    return b < a ? a : b;
}
int main()
{
    auto a = ::max(4, 7.2); // uses first template
    auto b = ::max<long double>(7.2, 4); // uses second template
    cout<< b<<endl;
}