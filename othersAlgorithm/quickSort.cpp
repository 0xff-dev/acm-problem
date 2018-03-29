#include <iostream>
#include <algorithm>

#define LEN 1000

using namespace std;

void quickSort(int* array, int low, int heigh){
    int first_data = array[low];
    int i=low, j=heigh;
    if( i<j ){
        while(i<j){
            while(array[j]>first_data && i<j)
                j--;
            while(array[i]<first_data && i<j)
                i++;
            if(i<j){
                swap(array[i], array[j]);
            }
        }
        quickSort(array, low, i);
        quickSort(array, i+1, heigh);
    }
}

int main(){
    int array[LEN];
    int len;
    while( cin >> len ){
        for( int i=0; i<len; i++ )
            cin >> array[i];
        quickSort(array, 0, len-1);
        for( int i=0; i<len; i++ )
            cout << array[i] << " ";
        cout << endl;
    }
    return 0;
}
