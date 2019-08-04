/*
 * 在保证全是非负的情况使用，并且最大的数字不是特别大
 * 
 * */

#include <iostream>
#include <algorithm>

typedef int (*compare)(int, int);


int get_n_number(int number, int n) {
    int res = 0;
    for(;n > 0; n--) {
        res = number % 10;
        number /= 10;
    }
    return res;
}

void count_sort(int* array, int len, int times, compare cmp) {
    int* output = new int[len+1];
    //int max_n = *std::max_element(array, array+len);
    //int* store = new int[max_n+1]();
    int* store = new int[10]();
    int max_n = 9;
    for(int i=0; i<len; i++) {
        store[cmp(array[i], times)]++;
    }
    for(int i=1; i<=max_n; i++) {
        store[i] += store[i-1];
    }
    for(int i=len-1; i>=0; i--) {
        output[store[cmp(array[i], times)]] = array[i];
        store[cmp(array[i], times)] --;
    }
    for(int walker=1; walker<=len; walker++) {
        array[walker-1] = output[walker];
        //std::cout << output[walker] << " ";
    }
    //std::cout << std::endl;
    delete []store, delete []output;
}

void cardinality_sort(int* array, int len, int size, compare cmp) {
    // 基数排序针对拥有相同的位数的排序, 首先确定每一项的位数，然后在进行n次的计数排序。
    // 基数排序需要稳定的算法
    for(int times=1; times<=size; times++) {
        count_sort(array, len, times, cmp);
    }
}

int main()
{
    //int arrar[] = {2,5,3,0,2,3,0,3};
    //count_sort(arrar, 8);
    //int arr[] = {4,1,9,10};
    //count_sort(arr, 4);
    int test_case[] = {329,457,657,839,436,720,355};
    cardinality_sort(test_case, 7, 3, get_n_number);
    for(int i=0; i<7; i++){
        std::cout << test_case[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

