// 包含使用地址交换， 函数指针
// char* const* (*next)() next是一个函数指针， 参数为空， 返回值是指向字符串的常量指针.
#include<iostream>

void testFuncPoint(int a, int b, void (*p)(int, int)) {
    p(a, b);
}

void p(int a, int b) {
    std::cout << a << "+" << b << "=" << a+b << std::endl;
}

int main() {
    int a=3, b=4;
    int* p1 =&a, *q = &b;
    int *tmp = p1;
    p1 = q;
    q = tmp;
    std::cout << "*p=" << *p1 << " *q=" << *q << std::endl; 
    testFuncPoint(a, b, &p);
}