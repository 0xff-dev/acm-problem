#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX 10001
#define FOR(x, y) for (int x=0; x<y; ++x)

using namespace std;


int main(){
    int n, m;
    while( cin >> n >> m ){
        int res[MAX] = {0};
        FOR(i, n) res[i] = i+1;
        m--;
        while( m-- ){
            next_permutation(res, res+n);
        }
        FOR(i, n-1) printf("%d ", res[i]);
        printf("%d\n", res[n-1]);
    }
    return 0;
}
