#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define CITYS 10


using namespace std;


int** road=NULL;
int city_ids[CITYS];    //0, 1, 2, 3, ...
int len;    //城市的数量, 在主函数做好, 在这个函数直接传
int best_length = 0;
int res = 0;    //全局的最佳路径长度计算


void TSP(int** road, int len, int start){
    if( len == start ){
        //全排列到了最后一位
        // 最后一座城市和第一座可以联通
        if( (road[city_ids[len-1]][city_ids[0]]!=0 && (res+road[city_ids[len-1]][city_ids[0]]) < best_length) || 
            best_length == 0){
            cout << "当前的最佳路径是: " << best_length << endl;
            for(int i=0; i<len; i++){
                cout << city_ids[i] << " ";
            }
            best_length = res+road[city_ids[len-1]][city_ids[0]];
        }
    }
    else{
        //不在最后就是继续排列中
        for( int i=start; i<len; i++ ){
            if( (road[city_ids[i]][city_ids[i-1]] && res+road[city_ids[i]][city_ids[i-1]]<best_length)|| 
                best_length == 0 ){
                swap(city_ids[i], city_ids[start]);
                res+=road[city_ids[start-1]][city_ids[start]];
                TSP(road, len, start+1);
                res-=road[city_ids[start-1]][city_ids[start]];
                swap(city_ids[i], city_ids[start]);
            }
        }
    }
}

int main(){
    cout << "输入城市数量: ";cin >> len;
    //初始化城市标号
    for( int i=0; i<len; i++ )
        city_ids[i]=i;
    int roads;
    road = new int*[CITYS];
    for(int i=0; i<CITYS; i++){
        road[i] = new int[CITYS];
        memset(road[i], 0, sizeof(int)*CITYS);
    }
    cout << "输入有多少条线路: ";cin >> roads;
    for( int i=0; i<roads; i++ ){
        cout << "输入两座城市的标号:小于" << len << endl;
        int c1, c2;
        cin >> c1 >> c2;
        cin >> road[c1][c2];
        road[c2][c1] = road[c1][c2];
    }
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if( i==j )
                road[i][j]=0;
            cout << road[i][j] << " ";
        }
        cout << endl;
    }
    best_length = 0;
    TSP(road, len, 1);
    cout << "最佳路径长度是: " << best_length << endl;
    for( int i=0; i<CITYS; i++ ){
        delete[] road[i];
    }
    delete[] road;
    return 0;
}
