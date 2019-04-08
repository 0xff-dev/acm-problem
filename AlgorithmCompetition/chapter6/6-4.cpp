#include<cstdio>
#include<cstring>

int cur, last, _next[10001];
char str[10001];

int main() {
    while(scanf("%s", str+1) == 1) {
        int len = strlen(str+1);
        last = cur = 0;
        _next[0] = 0;
        for( int i=1; i<=len; i++ ){
            if(str[i] == '[') cur = 0;
            else if (str[i] == ']') cur = last;
            else {
                _next[i] = _next[cur];
                _next[cur] = i;
                if(cur == last) last = i;
                cur = i;
            }
        }
        for( int i=_next[0]; i!=0; i=_next[i]) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}