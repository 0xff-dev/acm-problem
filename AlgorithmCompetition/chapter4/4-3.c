#include<stdio.h>
#include<string.h>

int go(int start, int step, int dir, int length, int* res) {
    while(step--) {
        do { start=(start+length+dir-1)%length+1;} while(res[start]==0);
    }
    return start;
}

int main() {
    int res[21];
    int m, k, n, walk;
    while(scanf("%d %d %d", &n, &k, &m)!=EOF){
        memset(res, 0, sizeof(int)*21);
        for(walk=1; walk<=n; walk++) res[walk] = walk;
        int left = n, A=n, B=1;
        while(left) {
            A = go(A, k, 1, n, res);
            B = go(B, m, -1, n, res);
            printf("%3d", A); left--;
            if(B != A){
                printf("%3d", B);
                left--;
            }
            if(left){
                res[A] = res[B] = 0;
            }
        }
        printf("\n");
    }
    return 0;
}