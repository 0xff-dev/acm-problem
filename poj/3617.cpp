#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    int _len;
    char result[10001];
    char tmp[10001];
    while( cin >> _len ){
        //输入数据
        for(int i=0; i<_len; i++){
            cin >> result[i];
            tmp[_len-i-1]=result[i];
        }
        int index_left=0, index_right=_len-1;
        string _str="";  
        while(index_left<=index_right){
            if( result[index_left]<result[index_right] ){
                _str+=result[index_left];
                index_left++;
            }
            else if ( result[index_left]> result[index_right] ){
                _str+=result[index_right];
                index_right--;
            }
            else{
                int l=index_left, r=index_right;
                while(l<=r && result[l]==result[r]){
                    l++, r--;
                }
                if( l<r ){
                    if( result[l]<result[r] ){
                        _str+=result[index_left++];
                    }
                    else{
                        _str+=result[index_right--];
                    }
                }
                else {
                    _str+=result[index_right];
                    index_left++;
                }
            }
        }
        int ans=0;
        for(int i=0; i<_str.size(); i++){
            cout << _str[i];
            ans++;
            if( ans%80==0 && i<_str.size()-1 )
                cout << endl;
        }
    }
    return 0;
}
