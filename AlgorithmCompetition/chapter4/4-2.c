// 怕是以后要指针满天飞啊
#include<stdio.h>
#include<string.h>


void guess(char* input, char* ans, int* win, int* lose, int* left, int*chance) {
    int out_index = 0, in_index;
    for(; out_index < strlen(ans); out_index++) {
        int error = 1;
         for(in_index=0; in_index<strlen(input); in_index++) {
            if(input[in_index] == ans[out_index]) {
                *left = *left-1;
                input[in_index] = ' ';
                error = 0;
            }
        }
        if(error) --*chance;
        if(!(*chance)) *lose = 1;
        if(!(*left)) *win = 1;
        if(*win || *lose) {
            break;
        }
    }
}

int main() {
    int test_case;
    char input[10000], ans[10000];
    int view[27];
    while(scanf("%d%s%s", &test_case, input, ans)==3 && test_case!=-1) {
        printf("Round %d\n", test_case);
        int win=0, lose=0, chance=7, left=strlen(input);
        guess(input, ans, &win, &lose, &left, &chance);
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chicked out.\n");
    }
    return 0;
}