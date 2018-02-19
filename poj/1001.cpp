#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define max_size 200

int main(){
    char R[25];
    int base, cf, n, fg;
    while(cin >> R >> n){
        int len = strlen(R);
        base = 0, cf = 0, fg = 0;
        for( int i=0; i<len; ++i ){
            if (R[i] == '.'){
                fg = len -i -1;
                continue;
            }
            base = base*10 + R[i] - '0';
        }
        if(fg){
            for( int i=len-1; R[i] == '0'; --i, --fg ){
                base /= 10;
            }
        }
        fg *= n;
        int result[max_size]={0}, index = max_size-1;
        for( int i=0, t_base = base; i<max_size; i++, t_base/=10){
            result[i] = t_base % 10;
        }
        for( int j=0; j<n-1; ++j){
            for( int i=0; i<max_size; ++i ){
                result[i] = base * result[i] + cf;
                cf = result[i] / 10;
                result[i] = result[i] % 10;
            }
        }
        for( ; index>=0; --index ){
            if (result[index] != 0)
                break;
        }
        if(fg > index){
            cout << ".";
            for( int tmp = fg-1; tmp>=0; --tmp ){
                cout << result[tmp];
            }
        }
        else{
            for(; index>fg-1; --index)
                cout << result[index];
            if(index >= 0)
                cout << ".";
            while(index >= 0){
                cout << result[index--];
            }
        }
        cout << endl;
    }
    return 0;
}
