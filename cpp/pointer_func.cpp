
/***
 *  函数指针说明, 好好理解
 * 1. int (*p)(...);定义了一个指向函数的指针,p能指向参数相同，返回类型相同的函数
 * 2. int func(...); 当一个函数的名字被单独使用的时候，就是一个指向函数的指针,func被解释为 int (*)(...)
 * 3. int (*p)(...) = 0; 表示该指针不指向任何函数
 * 4. 调用函数不需要解引用 或者(*p)(...)
 * 5. 
 */

#include <iostream>
#include <string>


using namespace std;

int sizeCompare(const string& _s1, const string& _s2){
    return _s1.size() < _s2.size();
}

void func1(int x){
    cout << x << "\n";
}

typedef int (*p)(const string& _s1, const string& _s2);
typedef void (*pfuncs)(int); // typeder void (*funcs[2])(int); 也ok

/*使用函数指针*/
p poniter_func;

/*函数指针数组*/
pfuncs funcs[2] = {
    func1, func1
};


int main(){
    poniter_func = &sizeCompare;
    cout << poniter_func("123", "123") << endl;
    for( int i=0; i<2; i++){
        funcs[i](i);
    }
    /*指向函数指针数组的指针*/
    pfuncs (*pfs)[2] = &funcs;

    /*指针数组*/
    int i=1, j=2;
    int* res[2] = {&i, &j};
    int **pp = res;
    for( int i=0; i<2; i++ ){
        cout << *(res[i]) << endl;
        cout << *pp[i] << endl;
    }
    return 0;
}