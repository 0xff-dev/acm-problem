#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    int n;
    long long value, result;
    while( cin >> n ){
        map<long long, long long> dict;
        for( int i=0; i<n; i++ ){
            scanf("%lld", &value);
            auto iter = dict.find(value);
            if ( iter != dict.end() ){
                dict[value] ++;
                if ( dict[value] >= (n+1)/2 ){
                    result = value;
                }
            }else{
                dict[value] = 1;
            }
        }
        printf("%lld\n", result);
    }
}
