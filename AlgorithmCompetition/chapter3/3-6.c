// 回文词+镜像串
// 回文串,好判断, 首尾相应, 镜像就的看能否找到镜像, 知道ok

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mapChars[]= "A    3  HIL JM O   2TUVWXY51SE Z  8";

char r(char ch) {
    if(isalpha(ch)) {
        return mapChars[ch-'A'];
    } else {
        return mapChars[ch-'0'+25];
    }
}
int main() {
    //首先检查收尾是不是同样的, 然后在判断镜像.
    char cs[1000];
    int p = 1, q = 1;
    while(scanf("%s", cs)) {
        for(int i=0; i<strlen(cs)/2; i++) {
            if(cs[i] != cs[strlen(cs)-1-i])
                p = 0;
            if(r(cs[i]) == ' ')
                q = 0;
        }
        printf("%d -- %d\n", p, q);
    }
}