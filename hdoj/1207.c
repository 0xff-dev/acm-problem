#include <stdint.h>
#include <stdio.h>

int main() {
    double a[65], b[65];
    int i,j;
    double tmp, _min;
    a[1] = 1;
    // 3根柱子
    for(i=2; i<=64; i++) a[i] = 2*a[i-1]+1;
    
    b[1]=1, b[2]=3;
    for(i=3; i<=64; i++) {
         _min = a[i];
        for(j=1; j<i; j++) {
            tmp = 2*b[j]+a[i-j];
            if(tmp < _min) {
                _min = tmp;
            }
        }
        b[i] = _min;
    }
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", (int)b[n]);
    }
    return 0;
}
