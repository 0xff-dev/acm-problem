#include<string>
#include<iostream>
#include<sstream>
#include<cstring>

using namespace std;

int len;

int findMaxIndex(int* array, int length) {
    int index = 0;
    for(int i=1; i<length; i++) {
        if(array[i] > array[index]) {
            index = i;
        }
    }
    return index;
}

// 看描述并没有对长度作输入
bool readList(int *arr) {
    string str;
    if(!getline(cin, str)) return false;
    len = 0;
    int x;
    stringstream ss(str);
    while(ss >> x) arr[len++] = x;
    return len > 0;
}

void solve(int* array, int index, int length) {
    int cnt = 0;
    int leftTop = 0;
    for( int i=1; i<index; i++) {
        if(array[i] > array[leftTop]) {
            leftTop = i;
        } else {
            cnt += (array[leftTop]-array[i]);
        }
    }
    int rightTop = length-1;
    for(int i=length-1; i>index; i--) {
        if(array[i]>array[rightTop]) {
            rightTop = i; 
        } else {
            cnt += (array[rightTop]-array[i]);
        }
    }
    cout << cnt << endl;
}

int main() {
    int array[10001];
    while(readList(array)) {
        int maxIndex = findMaxIndex(array, len);
        solve(array, maxIndex, len);
    }
}