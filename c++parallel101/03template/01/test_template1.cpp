//
// Created by Matoka on 2024/11/7.
//
#include<iostream>
template<int N>
struct Factorial{
  static constexpr int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0>{
  static constexpr int value = 1;
};
int main(){
  std::cout<<Factorial<0>::value<<std::endl;
  std::cout << Factorial<10>::value << std::endl;
}