// Tex 问题, 遇到", 进行转换
#include <stdio.h>
#include <string.h>

int main() {
    char c;
    int flag = 1;
    while((c =getchar()) != EOF) {
        if (c == '"') {
            printf("%s", flag?"“":"”");
            flag = !flag;
        } else {
            printf("%c", c);
        }
    }
    return 0;
}