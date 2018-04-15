#include <iostream>
#include <cstring>

using namespace std;
/*最长有序子序列*/
int main(){
    int data[1000];
    int res[1000];
    int len;
    while(cin >> len){
        memset(data, 0, sizeof(data));
        for( int i=0;i<len; i++ )
            res[i]=1;
        for( int i=0; i<len; i++ )
            cin >> data[i];
        for( int i=1; i<len; i++ ){
            for( int j=0; j<i; j++ ){
                if( data[j]<=data[i] && res[i]<res[j]+1)
                    res[i]=res[j]+1;
            }
        }

        /*
        for( int i=1; i<len; i++ ){
            if( data[i]>data[i-1] ){
                res[i]=res[i-1]+1;
            }
            else{
                int tmp=i-1;
                while(data[i]<data[tmp]){
                    tmp--;
                }
                我这里忘了加一步判断, 就是res[i]是否大于res[tmp]+1;
                res[i]=res[tmp]+1;
            }
            */
        for( int i=0; i<len; i++ )
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
