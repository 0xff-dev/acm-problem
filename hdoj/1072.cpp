#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#define rows 10
#define cols 10
using namespace std;


int map[rows][cols];
int n, m;
struct point{
    int x, y;
    int number;
    int time;
};

const int direction[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};


int solve_func(point& start_point, point& end_point, int row, int col){
    queue<point> q;
    point Next;
    q.push(start_point);
    while( !q.empty() ){
        point tmp = q.front();
        q.pop();
        for( int i=0; i<4; i++ ){
            Next.x = tmp.x+direction[i][0];
            Next.y = tmp.y+direction[i][1];
            Next.number = tmp.number+1;
            Next.time = tmp.time-1;

            //判断出界
            if( Next.x>=1 && Next.x<=row && Next.y>=1 && Next.y<=col && map[Next.x][Next.y]!= 0){
                if( map[Next.x][Next.y] == 4 && Next.time >= 1){
                    Next.time = 6;
                    map[Next.x][Next.y] = 0;
                }
                if ( Next.x == end_point.x && Next.y == end_point.y && Next.time >= 1){
                    return Next.number;
                }
                if (Next.time >= 1){
                    q.push(Next);
                }
            }
        }
    }
    return -1;
}
int main(){
    int test_time;
    while( cin >> test_time ){
        while(test_time --){
            cin >> n >> m;
            point start, end;
            memset(map, 0, sizeof(map));
            for( int i=1; i<=n; i++ ){
                for( int j=1; j<=m; j++ ){
                    cin >> map[i][j];
                    if( map[i][j]==2 ){
                        start.x = i, start.y = j;
                        start.time = 6;
                        start.number = 0;
                    }
                    else if (map[i][j] == 3){
                        end.x = i, end.y = j;
                    }
                }
            }
            cout << solve_func(start, end, n, m) << endl;
        }
    }
    return 0;

}
