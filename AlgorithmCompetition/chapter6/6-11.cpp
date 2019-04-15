#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int len = 32;
const int maxn = 1024+10;
char s[maxn];
int buf[maxn][maxn];
int cnt;

void draw(const char* s, int& p, int r, int c, int w) {
    char tmp = s[p++];
    // 该节点可以构建
    if(tmp == 'p') {
        draw(s, p, r, c+w/2, w/2);
        draw(s, p, r, c, w/2);
        draw(s, p, r+w/2, c, w/2);
        draw(s, p, r+w/2, c+w/2, w/2);
    } else if(tmp =='f') {
        for( int j=r; j< r+w; j++) {
            for( int i=c; i<c+w; i++) {
                if(buf[j][i] == 0) {buf[j][i]=1; cnt++;}
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cnt = 0;
        memset(buf, 0, sizeof(buf));
        for(int i=0; i<2; i++) {
            scanf("%s", s);
            int index = 0;
            draw(s, index, 0, 0, len);
        }
        cout << cnt << endl;
    }
    return 0;
}