#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

char char_arrray[100];
char _str1[201], _str2[201], result[201];

int main(){
    char start='A';
    /*一个规定数值和字母的映射*/
    for( int i=0; i<26; i++ ){
        char_arrray[i]=start++;
    }
    while( cin >> _str1 ){

        cin >> _str2;
        int _len1=strlen(_str1), _len2=strlen(_str2);
        int max_len=max(_len1, _len2);
        bool _str1_is_all_A=true, _str2_is_all_A=true;
        for( int i=0; i<_len1; i++ )
            if( _str1[i]!='A' )
                _str1_is_all_A=false;
        for(int i=0; i<_len2; i++)
            if( _str2[i]!='A' )
                _str2_is_all_A=false;
        if( _str1_is_all_A && _str2_is_all_A ){
                cout << 'A';
        }
        else{
            if( _len1!=max_len ){
                //_str1需要向后移动
                int tmp=max_len-1;
                for(int i=_len1-1; i>=0; i--){
                    _str1[tmp--]=_str1[i];
                }
                for( int i=0; i<max_len-_len1; i++ )
                    _str1[i]='A';
            }
            if( _len2!=max_len ){
                int tmp=max_len-1;
                for(int i=_len2-1; i>=0; i--){
                    _str2[tmp--]=_str2[i];
                }
                for( int i=0; i<max_len-_len2; i++ )
                    _str2[i]='A';
            }
            int cf=0;
    
            for( int i=max_len-1; i>=0; i-- ){
                int tmp_res=_str1[i]-'A'+_str2[i]-'A'+cf;
                if( tmp_res<26 ){
                    result[i]=char_arrray[tmp_res];
                    cf=0;
                }
                else{
                    cf=tmp_res/26;
                    result[i]=char_arrray[tmp_res-26];
                }
            }
            if( cf!=0 )
                cout << char_arrray[cf];
            int i=0;
            for( ; i<max_len; i++){
                if( cf!=0 )
                    break;
                if(cf==0&&result[i]!='A')
                    break;
            }
            for( ; i<max_len; i++ )
                cout << result[i];
        }
        cout << endl;
        //在计算的时候，-A，保证0-25的映射
    }
    return 0;
}
