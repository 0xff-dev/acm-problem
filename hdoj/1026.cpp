#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX=100;
int n, m;
char labyrithn[MAX+1][MAX+1];
int map_value[MAX+1][MAX+1];
int value[MAX+1][MAX+1];
int recall_step[MAX+1][MAX+1];
int next_direction[4][2] = { 
    {0, 1}, 
    {0, -1}, 
    {1, 0}, 
    {-1, 0}
};
int sum_time = 0;
struct node{
    int x, y, sum_step;
    friend bool operator < (node _x1, node _x2){
        return _x1.sum_step > _x2.sum_step;
    }
};

int bfs(){
    priority_queue<node> p_queue;
    node temp_node, next_node, result;
    temp_node.x = 0;
    temp_node.y = 0;
    temp_node.sum_step = 0;
    map_value[0][0] = -1; // 不要让程序在这里死掉，可能在下一个访问的时候回来，就死到这里了
    p_queue.push(temp_node);
    while(!p_queue.empty()){
        result = p_queue.top();
        p_queue.pop();
        if ( result.x == n-1 && result.y == m-1 )
            return result.sum_step;
        for( int i=0; i<4; i++ ){
            next_node.x = result.x + next_direction[i][0];
            next_node.y = result.y + next_direction[i][1];
            //判断边界以及是否是碰到陷阱
            if( next_node.x >=0 && next_node.x < n && next_node.y >=0 && next_node.y < m && map_value[next_node.x][next_node.y] !=-1 ){
                next_node.sum_step = result.sum_step + map_value[next_node.x][next_node.y] + 1;
                //是优先队列，所以在出来的肯定是step最小的
                map_value[next_node.x][next_node.y] = -1;// 封住回路.
                recall_step[next_node.x][next_node.y] = i+1; // 记录这个点是从哪个方向过来的
                p_queue.push(next_node);
            }
        }
    }
    return 0;
}

void print_out(int _x, int _y){
    if ( !recall_step[_x][_y] )
        return ;
    int father_x, father_y;
    father_x = _x - next_direction[recall_step[_x][_y]-1][0];
    father_y = _y - next_direction[recall_step[_x][_y]-1][1];
    print_out(father_x, father_y);
    printf("%ds:(%d,%d)->(%d,%d)\n", sum_time++, father_x, father_y, _x, _y);
    while(value[_x][_y]--){
        printf("%ds:FIGHT AT (%d,%d)\n",sum_time++, _x, _y);
    }
}

int main(){
    while( cin >> n >> m ){
        sum_time = 0;
        memset(map_value, 0, sizeof(map_value));
        memset(value, 0, sizeof(value));
        memset(recall_step, 0, sizeof(recall_step));
        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                cin >> labyrithn[i][j];
                if( labyrithn[i][j] == '.'){
                    map_value[i][j] = 0;
                }
                else if(labyrithn[i][j] == 'X'){
                    map_value[i][j] = -1;
                }
                else{
                    map_value[i][j] = value[i][j] = labyrithn[i][j] - '0';
                }
            }
        }
        int res = bfs();
        if( res ){
            sum_time = 1;
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", res);
            print_out(n-1, m-1);
        }
        else{
            printf("God please help our poor hero.\n");
        }
        printf("FINISH\n");
    }
    return 0;
}
