#include <iostream>
#include <cstring>
#include <cstdio>

#define MAX 1005
using namespace std;

const int table[10] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
const int gt_ten[10] = {6, 6, 2, 6, 4, 4, 4, 8, 4, 6};
const int cycle[4] = {2, 6, 8 ,4};
int str2num[MAX];
char str[MAX];
int find_cycle_data(int  x, int cycle_times){
    int i;
    for( i=0; i<4; i++ )
        if ( x == cycle[i] )
            break;

    return cycle[(i+cycle_times)%4];
}

int solve_func(char* str){
    int index, tmp_data;
    int res = 1;
    int len = strlen(str);
    if ( len == 1 )
        return table[str[0]-'0'];
    else{
        for( index=0; index<len; index++)
            str2num[len-index-1] = str[index] - '0';
        int cf;
        while( len > 1 ){
            cf = 0;
            tmp_data = str2num[0];//因为现在至少是两位数, 先根据G(n)来确定gt_ten的开始位置
            str2num[len] = 0;
            //一会解释
            for( index=0; index<=len; index++ ){
                str2num[index] = str2num[index]*2+cf;
                cf = str2num[index] / 10;
                str2num[index] %= 10;
            }
            for( index=1; index<=len; index++ )
                str2num[index-1] = str2num[index];
            if ( str2num[len]==0 )
                //无多出来的进位
                len--;
            res = res * find_cycle_data(gt_ten[tmp_data], str2num[0]+str2num[1]*10) % 10;
        }
        res = res* table[str2num[0]] % 10;
        return res;
    }
}

int main(){
    while( scanf("%s", str) != EOF){
        printf("%d\n", solve_func(str));
    }
    return 0;
}
