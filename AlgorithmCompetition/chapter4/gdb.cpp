// 用于gdb调试使用
#include<iostream>


void swap(int a, int b) {
    int t=a; a=b; b=t;
}

int main() {
    int a=3, b=4;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}