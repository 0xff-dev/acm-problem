#include<cstdio>
#include<algorithm>
#include<cstring>

// const int maxn = 1<<20;
// int nodes[maxn];

int main() {
    int height, n;
    while(scanf("%d %d", &height, &n) != EOF) {
        // memset(nodes, 0, sizeof(nodes));
        // int index, status;
        // while(n--) {
        //     index = 1;
        //     for(;;) {
        //         nodes[index] = !nodes[index];
        //         status = nodes[index];
        //         index *= 2;
        //         index = status?index:index+1;
        //         if(index > (1<<height)-1) break;
        //     }
        // }
        int index = 1;
        for(int i=0; i<height-1; i++){
            if(n%2) {index *=2, n=(n+1)/2;}
            else { index = index*2+1, n /= 2;}
        }
        printf("%d\n", index);
    }
}