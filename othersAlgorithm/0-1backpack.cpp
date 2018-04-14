#include <iostream>
#include <cstring>

using namespace std;

int dp[100][100];
int w[100], v[100];
int result[100]; //用来记录那些被选中了
void find_result(int j, int i){
    if( j>=0 ){
        if( dp[j][i]==dp[j-1][i] ){
            //就是没有选这个
            result[j]=0;
            find_result(j-1, i);
        }
        else if(i-w[j]>=0  && dp[j][i]==dp[j-1][i-w[j]]+v[j]){
            result[j]=1;
            find_result(j-1, i-w[j]);
        }
    }
}
int main(){
    int max_value, len;
    cout << "Input Max value:<100" << endl;
    cin >> max_value;
    cout << " Input len: <100" << endl;
    cin >> len;
    memset(dp, 0, sizeof(dp));
    memset(result, 0, sizeof(result));
    //先输入重量在输入价值
    for( int i=1; i<=len; i++ )
        cin >> w[i] >> v[i];
    for( int i=1; i<=max_value; i++ ){
        //外层是背包的重量
        for( int j=1; j<=len; j++ ){
            //内曾是物品
            if( i>=w[j] ){
                dp[j][i]=max(dp[j-1][i], dp[j-1][i-w[j]]+v[j]);
            }
            else{
                dp[j][i]=dp[j-1][i];
            }
        }
    }
    cout << "MAX: " << dp[len][max_value] << endl;
    find_result(len, max_value);
    for( int i=0; i<=len; i++ ){
        for( int j=0; j<=max_value; j++ )
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << " 选中的物品是:" << endl;
    for( int i=0; i<=len; i++ )
        if( result[i]!=0 )
            cout << "第[" << i << "]件物品选中" << "weight: " << w[i] << " value: " << v[i] << endl;
    cout << "一维数组解决: " << endl;
    int tmp[100];
    memset(tmp, 0, sizeof(tmp));
    for( int i=1; i<=len; i++ ){
        for ( int v1=max_value; v1>=w[i]; v1-- ){
            if( tmp[v1]<tmp[v1-w[i]]+v[i])
                tmp[v1]=tmp[v1-w[i]]+v[i];
        }
    }
    for( int i=1; i<=max_value; i++)
        cout << tmp[i] << " ";
    cout << "max: " << tmp[max_value] << endl;
    return 0;
}
