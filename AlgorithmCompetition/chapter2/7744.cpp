// 输出所有形如 aabb的4为完全平方数

#include <iostream>
#include <cstdio>

int main()
{
    for( int i=0; ; i++ ){
        int x = i * i;
        if(x < 1000)
            continue;
        if (x>9999)
            break;
        int h2 = x / 100;
        int l2 = x % 100;
        if ((h2/10 == h2%10) && (l2/10 == l2%10))
            printf("%d\n", x);
    }
    int nums[9]={1,2,3,4,5,6,7,8,9};
    for( int i=0; i<9; i++ )
        printf("%d\n", nums[i]);
    return 0;
}

