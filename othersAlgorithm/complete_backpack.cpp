#include <iostream>
#include <cstring>

using namespace std;

//完全背包, 考虑物品的重用

int dp[101][101];
int w[101], v[101];
int res[101];  //记录被选中的物品
void find_items(int i, int j){
    //从末尾开始选择
    while(i){
        if( dp[i][j]==dp[i][j-w[i]]+v[i] ){
            res[i]++;
            j-=w[i];
        }
        i--;
    }
}

int main(){
    int _max_size, _len;
    cout << "Input _max_size capability: ";
    cin >> _max_size;
    cout << "Input _len of array: ";
    cin >> _len;
    for( int i=1; i<=_len; i++ )
        cin >> w[i] >> v[i];
    for( int i=1; i<=_max_size; i++ ){
        for( int j=1; j<=_len; j++ ){
            if( i>=w[j] ){
                dp[j][i]=max(dp[j-1][i], dp[j][i-w[j]]+v[j]);
            }
            else{
                dp[j][i]=dp[j-1][i];
            }
        }
    }
    cout << "MAX: " << dp[_len][_max_size] << endl;
    for( int i=0; i<=_len; i++ ){
        for( int j=0; j<=_max_size; j++ )
            cout << dp[i][j] << " ";
        cout << endl;
    }
    find_items(_len, _max_size);
    for( int i=1; i<=_len; i++ )
        cout << res[i] << " ";
    cout << endl;
    cout << "一维数组解决问题, 考虑01背包在使用一维数组解决问题需要的反向遍历就是避免重复使用,\n所以正向遍历" << endl;
    int tmp[101];
    memset(tmp, 0, sizeof(tmp));
    for( int i=1; i<=_len; i++ ){
        for( int j=_max_size; j>=w[i]; j-- ){
            if( tmp[j]<tmp[j-w[i]]+v[i] )
                tmp[j]=tmp[j-w[i]]+v[i];
        }
    }
    cout << "MAX: " << tmp[_max_size] << endl;
    for( int i=1; i<=_max_size; i++ )
        cout << tmp[i] << "  ";
    cout << endl;
    return 0;
}
