#include <iostream>
#include <string>

using namespace std;

bool is_number(char c){
    int tmp = c-'0';
    if( tmp>=0 && tmp<=9 )
        return true;
    return false;
}

string str;
int len;
int solve_func(int pos){
    while( str[pos]!=')' && pos<len ){
        int k = 0, p = -1;
        while( is_number(str[pos]) ){
            k = k*10+str[pos]-'0';
            pos++;
        }
        if( k == 0 ) k =1;
        while(k--){
            if( str[pos] == '('){
                p = solve_func(pos+1);
            }
            else{
                cout << str[pos];
            }
        }
        //递归结束，回到上一层
        if( p != -1 ) pos=p;
        pos++;
    }
    return pos;
}

int main(){
    int num;
    while( cin >> num ){
        while( num-- ){
            cin >> str;
            len = str.size();
            solve_func(0);
            cout << endl;
        }
    }
    return 0;
}
