#include <iostream>
using namespace std;

template<typename T1, typename T2, typename RT>
RT max (T1 a, T2 b) {
   return a > b ? a : b;
}
int main() {
   auto res =  ::max<int,double,double>(4, 7.2);
   cout << res << endl;
}

