// 生成元, 考虑打表

#include <stdio.h>
#include <string.h>
#define maxn 10000

int ans[maxn+1];

int main() {
    memset(ans, 0, sizeof(ans));
    for(int m=1; m<=maxn; m++){
        int x=m, y = m;
        while(x>0) {
            y += (x%10);
            x /= 10;
        }
        if (ans[y] == 0 || ans[y] > m) {
            ans[y] = m;
        }
    }
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", ans[n]);
    }
    return 0;
}