#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Max = 100;

int main() {
    int n, k;
    int array[Max];
    while(cin >> n >> k) {
        for(int i=0; i<n+1; i++) {
            array[i] = 1;
        }
        for(int i = 2; i <= k; i++){
            for(int j = i; j <= n; j+=i)
            array[j] = !array[j];
        }
        for(int i = 1; i <= n; i++) {
            if (array[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}