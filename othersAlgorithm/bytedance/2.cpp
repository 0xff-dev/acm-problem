#include<iostream>
using namespace std;

int main() {
    int N;
    int money[4]={1,4,16,64};
    while(cin >> N) {
        int result = 1024-N;
        int cnt = 0;
        if(result == 0){
            cout << 0 << endl;
        } else {
            for(int i=3; i>=0; i--){
                if(result>=money[i]){
                    cnt += (result/money[i]);
                    result %= money[i];
                }
            }
            cout << cnt << endl;
        }
    }
}