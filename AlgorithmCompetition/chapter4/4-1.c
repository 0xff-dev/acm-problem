// 两个长度相同的字符串， 判断一个字符串能否通过变换， 然后对26个字母一个映射得到另一个字符串
// 核心在排序　qsort使用， 理解函数指针.
#include<stdlib.h>
#include<stdio.h>

int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int main() {
    char a1[]={'J', 'W', 'P', 'U', 'D', 'J', 'S', 'T', 'V', 'P'};
    char a2[]={'W', 'J', 'D', 'U', 'P', 'S', 'J', 'P', 'V', 'T'};
    qsort(a1, 10, sizeof(char), cmp);
    qsort(a2, 10, sizeof(char), cmp);
    int index = 0;
    int flag = 0;
    for(; index<10; index++) {
        printf("%c == %c\n", a1[index], a2[index]);
        if(a1[index]!=a2[index]){
            flag = 1;
            break;
        }
    }
    if(flag) {
        printf("FALSE\n");
    } else{
        printf("TRUE\n");
    }
    return 0;
}