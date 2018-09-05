#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int len=12;
int data[len], n;
long count;   //多少种情况

void solve_func(int row){
    //某一行
    if(row == n)
        count++;
    else{
        for( int i=0; i<n; i++){
            bool flag = true;
            data[row] = i;    // 第row行的皇后放到i列
            // 判断
            for(int j=0; j<row; j++){
                // 满足的条件 统一列, y=-x平行的轴， y=x平行的轴
                if( (data[row]==data[j]) || (row+data[j]==j+data[row]) || (row+data[row]==j+data[j] )){
                    flag = false;
                    break;
                }
            }
            if(flag)
                solve_func(row+1);
        }
    }
}

int main(){
    while( cin >> n) {
        count = 0;
        solve_func(0);
        cout << count << endl;
    }
    return 0;
}