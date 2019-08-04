// dfs搜索
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int maxn = 10001;

char map[maxn][maxn];
int visited[maxn][maxn];
int m, n;

// 把相同的联通值记录id
void dfs(int row, int col, int& id) {
    if(row < 0 || row > m || col < 0 || col > n) return;
    if(map[row][col] == '@' || visited[row][col] != 0) return;
    for( int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++){
            if(i!=0 || j!=0) dfs(row+i, col+j, id);
        }
    }
}

int main() {
    while(cin >> m >> n){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }
        memset(visited, 0, sizeof(visited));
        // 找到@的位置开始递归， 并且标记。
        int id = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0 && map[i][j] == '@') dfs(i, j, id);
            }
        }
        cout << id << endl;
    }
    return 0;
}
