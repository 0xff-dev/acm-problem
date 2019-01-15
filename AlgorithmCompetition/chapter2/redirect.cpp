#define LOCAL
#include <iostream>
#include <cstdio>

#define INF 10000000

int main()
{
    #ifdef LOCAL
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    // TODO
    
    // 禁用重定向的方式
    int res;
    FILE *fin = fopen("test.in", "rb");
    FILE *fout = fopen("test.out", "wb");
    while(fscanf(fin, "%d", &res) == 1){
        // TODO
    }
    fprintf(fout, "%d", res);
    return 0;
}

