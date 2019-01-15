#include <iostream>
#include <cstring>

using namespace std;


void deal(int* arrar, int num){
    for( int i=0; i<3; i++ ){
        arrar[num%10] += 1;
        num /= 10;
    }
}

int judge(int* array) {
    for( int i=1; i<10; i++ ){
        if (array[i] != 1)
            return 0;
    }
    return 1;
}

int main()
{
    int nums[10] = {0};
    for( int i=123; i<987/3; i++ ){
        int i2 = i * 2;
        int i3 = i * 3;
        memset(nums, 0, sizeof(nums));
        deal(nums, i);
        deal(nums, i2);
        deal(nums, i3);
        for( int i=1; i<10; i++ ){
            if (nums[i] != 1)
                break;
        }
        if (judge(nums)){
            printf("%d %d %d\n", i, i2, i3);
        }
    }
    return 0;
}

