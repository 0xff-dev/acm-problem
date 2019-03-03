#include <stdio.h>
#include <string.h>
#define MAX 20

int main() {
    int n;
    int a[MAX][MAX];
    while(scanf("%d", &n) != EOF) {
        memset(a, 0, sizeof(a));
        int x = 0, y = n-1, count = 1;
        int i, j;
        a[x][y] = count;
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++)
                printf("%3d", a[i][j]);
            printf("\n");
        } 
        // 逆时针走
        while(count < n*n) {
            while((x+1)<n && !a[x+1][y])
                a[++x][y] = ++count;
            while((y-1)>=0 && !a[x][y-1])
                a[x][--y] = ++count;
            while((x-1)>=0 && !a[x-1][y])
                a[--x][y] = ++count;
            while((y+1)<n && !a[x][y+1])
                a[x][++y] = ++count;
        }
        
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++)
                printf("%3d", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}