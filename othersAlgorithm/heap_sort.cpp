#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;


const int LEN=1000;


inline int LEFT(int i){
    return i*2;
}


inline int RIGHT(int i){
    return 1+i*2;
}


void max_heapify(int* array, int index, int heap_size){
    //只是作为下标, 俩孩子
    int l=LEFT(index);
    int r=RIGHT(index);
    int largest_index;
    if(l<=heap_size && array[l]>array[index]){
        largest_index=l;
    }
    else{
        largest_index=index;
    }
    if( r<=heap_size && array[r]>array[largest_index] ){
        largest_index=r;
    }
    if (largest_index != index){
        swap(array[largest_index], array[index]);
        max_heapify(array, largest_index, heap_size);
    }
}

void build_heap(int* array, int len){
    for(int i=len/2; i>=1; i--){
        max_heapify(array, i, len);
    }
    /*
    cout << "建立大根堆..." << endl;
    for( int i=1; i<=len; i++ )
        cout << array[i] << " ";
    cout << endl;
    */
}


void heap_sort(int* array, int len){
    build_heap(array, len);
    for(int i=len; i>=2; i--){
        swap(array[i], array[1]);
        len--;
        max_heapify(array, 1, len);
    }
}

void print(int* array, int len){
    cout << "打印排序结果" << endl;
    for( int i=1; i<=len; i++ )
        cout << array[i] << " ";
    cout << endl;
}
int main(){
    int array[LEN];
    int heap_size;
    while(cin >> heap_size){
        memset(array, 0, sizeof(array));
        for(int i=1; i<=heap_size; i++)
            cin >> array[i];
        heap_sort(array, heap_size);
        print(array, heap_size);
    }
}
