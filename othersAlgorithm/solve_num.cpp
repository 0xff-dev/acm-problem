
/*
 *  输入分子，分母都是正整数，求小数的表示形式，
 *  如果遇到循环，就用()将循环部分圈起来。
 *  Such as
 *  8/5=1.6
 *  80/10 =8.0
 *  8/11=.(72)
 * 
 * */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAX=65536;

void func(int numerator, int denominator){

    int cf_arrray[MAX] = {0};
    int quotient[MAX] = {0};
    //先检查整除
    if ( numerator % denominator == 0 ){
        printf("%d.0\n", numerator / denominator);
        return ;
    }
    //不整除的情况.
    cf_arrray[0] = numerator % denominator;
    quotient[0] = numerator / denominator;
    
    //处理循环部分.
    for( int i=0; i<denominator-1; i++ ){
        int tmp_num = (cf_arrray[i] * 10) % denominator;
        quotient[i+1] = (cf_arrray[i] * 10) / denominator;

        //小数除的开.
        if ( tmp_num == 0){
            printf("%d.", quotient[0]);
            for( int j=1; j<=i+1; j++ ){
                printf("%d", quotient[j]);
            }
            printf("\n");
            return;
        }
        cf_arrray[i+1] = tmp_num;
        if ( cf_arrray[i+1] == cf_arrray[0]){
            //找到重复的部分
            if (quotient[0])
                printf("%d.(", quotient[0]);
            else
                printf(".(");
            for( int k=1; k<=i+1; k++ )
                printf("%d", quotient[k]);
            printf(")\n");
            return ;
        }
    }
    return ;
}
int main(){
    int num, num1;
    char split;
    while(cin >> num >> split >> num1)
        func(num, num1);
    return 0;
}
