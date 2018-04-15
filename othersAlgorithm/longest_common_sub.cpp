#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*最长公共子序列*/
int dp[1001][1001];
char _str1[1001], _str2[1001];

int main(){
    string s1, s2;
    while( cin >> s1 ){
        cin >> s2;
        for(int i=1; i<=s1.size(); i++)
            _str1[i]=s1[i-1];
        for(int i=1; i<=s2.size(); i++)
            _str2[i]=s2[i-1];

        memset(dp, 0, sizeof(dp));
        int result=0;
        for( int i=1; i<=s1.size(); i++ ){
            for( int j=1; j<=s2.size(); j++ ){
                if( _str1[i]==_str2[j] ){
                    dp[j][i]=dp[j-1][i-1]+1;
                }
                else{
                    /*当这两个字符不相等的时候，需要考虑的是以_str1[:i-1]的字串和
                     * _str2[:i], _str1[:i]和_str2[:i-1]这两个字符串的最长公共字串的长短
                     * */
                    dp[j][i]=max(dp[j-1][i], dp[j][i-1]);
                }
                if( result<dp[j][i] )
                    result=dp[j][i];
            }
        }
        cout << result << endl;
    }
}
