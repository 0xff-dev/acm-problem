#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_NUM 600000
using namespace std;

long long  res_arr[MAX_NUM]={0};
int result[1001]={0};

void init(){
    for( int i=1; i<MAX_NUM/2; i++ ){
        for( int j=i+i; j<MAX_NUM; j+=i ){
            res_arr[j] += i;
        }
    }
    for( int i=2; i<=MAX_NUM; i++ ){
        if( res_arr[i] <= 1000 )
            result[res_arr[i]] = 1;
    }
}

int main(){
    init();
    int n, m;
    while( scanf("%d", &m) != EOF){
        while( m-- ){
            scanf("%d", &n);
            if( result[n] == 1)
                printf("no\n");
            else
                printf("yes\n");
        }
    }
    return 0;
}
