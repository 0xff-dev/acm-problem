#include <iostream>

#define LEN 1000

using namespace std;
void merge(int* array, int low, int heigh){
    int index=0;
    int aid_array[LEN];
    int mid=(low+heigh)/2;
    int arr_low=low, arr_heigh=mid+1;
    while(arr_low<=mid&&arr_heigh<=heigh){
        if(array[arr_low]<array[arr_heigh])
            aid_array[index++] = array[arr_low++];
        else
            aid_array[index++] = array[arr_heigh++];
    }
    while(arr_low<=mid)
        aid_array[index++] = array[arr_low++];
    while(arr_heigh<=heigh)
        aid_array[index++] = array[arr_heigh++];
    for( int k=0; k<index; k++ )
        array[low+k] = aid_array[k];
}

void merge_sort(int* array, int low, int heigh){
    if ( low < heigh ){
        int mid=(low+heigh)/2;
        merge_sort(array, low, mid);
        merge_sort(array, mid+1, heigh);
        merge(array, low, heigh);
    }
}

int main(){
    int array[LEN];
    int len;
    while(cin >> len){
        for( int i=0; i<len; i++ )
            cin >> array[i];
        merge_sort(array, 0, len-1);
        for( int i=0; i<len; i++ )
            cout << array[i] << " ";
        cout << endl;
    }
}
