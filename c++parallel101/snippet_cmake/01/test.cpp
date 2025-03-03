//
// Created by Matoka on 2025/3/3.
//
/* cmake 版本信息管理 */
#include<iostream>
#include"TutorialConfig.h"
using namespace std;
int func() {
    return 42;
}

int main() {
    int a = func();
    cout << VERSION_INFO << endl;
}
