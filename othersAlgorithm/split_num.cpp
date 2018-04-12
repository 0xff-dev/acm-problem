#include <iostream>

using namespace std;

int get_result(int n, int m){
    if( n<1 || m<1 ) return 0;
    if( n==1||m==1 ) return 1;
    if( n<m ) return get_result(n, n);
    if(n==m) return get_result(n, m-1)+1;
    return get_result(n-m, m)+get_result(n, m-1);
}

int main(){
    int n;
    cin >> n;
    int res=get_result(n, n);
    cout << res << endl;
    return 0;
}
