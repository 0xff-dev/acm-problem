// 猜数字, 这道题要整体的考虑. 

#include <stdio.h>
#include <string.h>

int main() {
    int as[1000], bs[1000];
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++)
            scanf("%d", &as[i]);
        int A = 0, B = 0;
        for(;;) {
            for(int i=0; i<n; i++){
                scanf("%d", &bs[i]);
                if (bs[i] == as[i]){
                    A++;
                }
            }
            //首位是0的情况认为出局
            if (bs[0] == 0)
                break;
            for( int i=1; i<10; i++){
                int c1 = 0, c2 = 0;
                for( int j=0; j<n; j++){
                    if(as[j] == i)
                        c1++;
                    if(bs[j] == i)
                        c2++;
                }
                B += (c1>c2?c2:c1);
            }
            printf("(%d, %d)\n", A, B-A);
        }
    }
    return 0;
}