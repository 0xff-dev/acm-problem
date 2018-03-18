#include <iostream>
#include <cstring>
#include <queue>

#define ROWS 300
#define COLS 300
using namespace std;

struct node {
    int x, y, step;
    friend bool operator < (node n1, node n2){
        return n1.step > n2.step;
    }
};

const int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

char lay[ROWS][COLS];
int map[ROWS][COLS];
int solve_func(node& start_node, int n, int m) {
    priority_queue<node> q;
    node tmp, next_node;
    q.push(start_node);
    lay[start_node.x][start_node.y] = '#';
    while(!q.empty()){
        tmp = q.top();
        q.pop();
        if( lay[tmp.x][tmp.y]== 'r')
            return tmp.step;
        else{
            for( int i=0; i<4; i++ ){
                next_node.x = tmp.x + dir[i][0];
                next_node.y = tmp.y + dir[i][1];
                if( lay[next_node.x][next_node.y] == 'r' )
                    return tmp.step+1;
                if ( next_node.x>=0 && next_node.x<n && next_node.y>=0 && next_node.y<m && lay[next_node.x][next_node.y]!='#'){
                    next_node.step = tmp.step+map[next_node.x][next_node.y];
                    lay[next_node.x][next_node.y] = '#';
                    q.push(next_node);
                }
            }
        }
    }
    return -1;
}

int main(){
    int n, m;
    node start;
    while( cin >> n >> m ){
        memset(map, 0, sizeof(int));
        memset(lay, ' ', sizeof(lay));
        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                cin >> lay[i][j];
                if( lay[i][j] =='#' )
                    map[i][j] = 0;
                if( lay[i][j] == '.' )
                    map[i][j] = 1;
                if( lay[i][j] == 'r')
                    map[i][j] = 1;
                if( lay[i][j] == 'x')
                    map[i][j] = 2;
                if( lay[i][j] =='a' ){
                   start.x = i;
                   start.y = j;
                   start.step = 0;
                }
            }
        }
        int res = solve_func(start, n, m);
        if( res != -1){
            cout << res << endl;
        }
        else{
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        }
    }
    return 0;
}
