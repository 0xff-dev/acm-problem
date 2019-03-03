// 环状序列

#include <stdio.h>
#include <string.h>

#define maxn 105

int less(char *str, int p1, int p2) {
    //比较从p1开始的串和从p2开始的串小
    int len = strlen(str);
    for( int i=0; i<len; i++){
        if(str[(p1+i)%len] != str[(p2+i)%len]) {
            return str[(p1+i)%len] < str[(p2+i)%len];
        }
    }
    return 0;
}

int main() {
    char s[maxn];
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        int index = 0;
        int len = strlen(s);
        for(int i=1; i<len; i++){
            if(less(s, i, index)) {
                index = i;
            }
        }
        for(int i=0; i<len; i++){
            printf("%c", s[(index+i)%len]);
        }
    }
    return 0;
    
}