/*
 * Problem Description
As we all know the Train Problem I, the boss of the Ignatius Train Station want to know if all the trains come in strict-increasing order, how many orders that all the trains can get out of the railway.
 

Input
The input contains several test cases. Each test cases consists of a number N(1<=N<=100). The input is terminated by the end of file.
 

Output
For each test case, you should output how many ways that all the trains can get out of the railway.
 

Sample Input
1
2
3
10
 

Sample Output
1
2
5
16796

Hint

The result will be very large, so you may not process it by 32-bit integers.
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX=55;

void X(int n, int* res){
    int index=MAX-1;
    //找到第一个不为0的index
    while( !res[index] )
        index--;
    int cf = 0, k=0;
    for(; k<=index; k++){
        res[k] = res[k]*n + cf;
        cf = res[k] / 10000;
        res[k] %= 10000;    
    }
    res[k] = cf;
}

void devision(int n, int* res){
    int index=MAX-1;
    while( !res[index] )
        index--;
    int cf = 0;
    for(; index>=0; index--){
        res[index] = res[index] + cf * 10000;
        cf = res[index] % n;
        res[index] = res[index] / n;
    }
}


void calculate( int n, int* res ){
    for( int i=n+2; i<=2*n; ++i )
        X(i, res);
    for( int i=1; i<=n; ++i )
        devision(i, res);
}

int main(){
    int num;
    int res[MAX];
    while( cin >> num ){
        memset(res, 0, sizeof(int)*MAX);
        res[0] = 1;
        calculate(num, res);
        int index = MAX-1;
        while( !res[index] )
            index--;
        printf("%d", res[index]);
        while(--index>=0)
            printf("%04d", res[index]);
        printf("\n");
    }
    return 0;
}
