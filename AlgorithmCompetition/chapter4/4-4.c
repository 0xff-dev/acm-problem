// 直接圈粉..., 用长度保存对应的字符， 同时直接去内存读取数字， 不存储
#include<stdio.h>
#include<string.h>

int code[8][1<<8];

int readchar() {
    for(;;){
        char ch = getchar();
        if(ch!='\n' || ch != '\r') return ch;
    }
}

int readint(int c) {
    int res = 0;
    while(c--) res = res*2+readchar()-'0';
    return res;
}

int readcodes() {
    memset(code, 0, sizeof(code));
    code[1][0] = readchar();
    int len=2, i;
    for(; len<=7; len++){
        for(i=0; i<(1<<len)-1; i++){
            int ch = getchar();
            if(ch == EOF) return 0;
            if(ch == '\n' || ch == '\r') return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}

int main() {
    while(readcodes()) {
        for(;;){
            int len = readint(3);
            if(len == 0){
                break;
            }
            for(;;) {
                int v = readint(len);
                if(v == (1<<len)-1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}