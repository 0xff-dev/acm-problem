#include <stdio.h>
#include <string.h>

#define maxn 1001

int main() {
    char t[maxn], s[maxn];
    int i, j;
    while(scanf("%s", s+1)) {
        getchar();
        scanf("%s", t+1);
        int dp[maxn][maxn] = {0};
        int lenS = strlen(s+1), lenT = strlen(t+1);
        for( i=1; i<=lenT; i++) {
            for( j=1; j<=lenS; j++){
                if(t[i] == s[j]){
                    dp[j][i] = dp[j-1][i-1]+1;
                } else {
                    dp[j][i] = dp[j-1][i] > dp[j][i-1]?dp[j-1][i]:dp[j][i-1];
                }
            }
        }
        if (dp[lenS][lenT]==lenS) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        getchar();
    }
    return 0;
}