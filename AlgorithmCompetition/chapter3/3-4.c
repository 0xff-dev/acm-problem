// 找到一个abd*de的竖式, 让计算范围的数字都属于一个集合

#include <stdio.h>
#include <string.h>

int main() {
    char nums[10];
    gets(nums);
    char bufs[1000];
    int count = 0;
    for(int abc=111; abc <= 999; abc++) {
        for(int de=11; de <= 99; de++) {
            int ok = 1;
            int x = abc*(de%10), y = abc*(de/10);
            sprintf(bufs, "%d%d%d%d%d", abc, de, x, y, abc*de);
            for(int i=0; i<strlen(bufs); i++) {
                if(strchr(nums, bufs[i]) == NULL) {
                    ok = 0;
                }
            }
            if (ok) {
                //存在, 打印
                printf("<%d>\n", count++);
                printf("%5d\n%5d\n-----\n%5d\n%-5d\n-----\n%5d\n", abc, de, x, y, abc*de);
            }
        }
    }
}