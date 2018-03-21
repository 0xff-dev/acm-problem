#include <iostream>
#include <string>
#include <map>

#define MAX_STR 1000
using namespace std;

int main(){
    string str;
    map<string, int> mmp;
    while( getline(cin, str, '\n')){
        if( str.size()  == 0)
            break;
        for( int i=str.size(); i>0; i-- ){
            mmp[str.substr(0, i)] ++;
            str[i-1] = '\0';
        }
    }
    while( cin >> str){
        cout << mmp[str] << endl;
    }
    return 0;
}
