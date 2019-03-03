#include <stdio.h>
#include <string.h>

#define maxn 82

int main() {
    char str[maxn];
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", str);
        int sum = 0, O = 1;
        for( int i=0; i<strlen(str); i++) {
            if(str[i] == 'O') {
                sum += O;
                O += 1;
            } else {
                O = 1;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}