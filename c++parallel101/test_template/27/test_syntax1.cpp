#include <iostream>
using namespace std;

template<typename RT, typename T1, typename T2>
RT max (T1 a, T2 b){
  return a > b ? a : b;
}

int main() {
   auto res = ::max<double>(4, 7.2); // OK: return type is double, T1 and T2 are deduced
   cout << res << endl;
}

