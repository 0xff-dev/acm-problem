#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

const string consecutives="aeiou";

bool is_consecutive(char c){
    for( unsigned int i=0; i<consecutives.size(); i++ )
        if( c==consecutives[i] )
            return true;
    return false;
}

bool has_no_consective(string& s){
    for( unsigned i=0; i<s.size(); i++ )
        if(is_consecutive(s[i]))
            return false;
    return true;
}

bool solve_func(string& s){
    if (has_no_consective(s))
        return false;
    if (s.size() == 1){
        if(is_consecutive(s[0]))
            return true;
        else
            return false;
    }
    if( s.size() == 2){
        if( is_consecutive(s[0])&&is_consecutive(s[1])&&s[0]==s[1]&&(s[0]!='e'&&s[0]!='o') )
            return false;
        if (!is_consecutive(s[0])&&!is_consecutive(s[1])&&s[0]==s[1])
            return false;
        else
            return true;
    }
    for( unsigned i=0; i<s.size()-2; i++ ){
        //三元音, 三辅音相连
        if((is_consecutive(s[i])&&is_consecutive(s[i+1])&&is_consecutive(s[i+2])) || (!is_consecutive(s[i])&&!is_consecutive(s[i+1])&&!is_consecutive(s[i+2])))
            return false;
        if(is_consecutive(s[i])&&is_consecutive(s[i+1])&&s[i]==s[i+1]&&s[i]!='e'&&s[i]!='o')
            return false;
        if(is_consecutive(s[i+1])&&is_consecutive(s[i+2])&&s[i+1]==s[i+2]&&s[i+1]!='e'&&s[i+1]!='o')
            return false;
        if( !is_consecutive(s[i])&&!is_consecutive(s[i+1])&&s[i]==s[i+1] )
            return false;
        if( !is_consecutive(s[i+1])&&!is_consecutive(s[i+2])&&s[i+1]==s[i+2] )
            return false;

    }
    return true;
}

int main(){
    string password;
    while(cin >> password && password != "end"){
        if(solve_func(password)){
            printf("<%s> is acceptable.\n", password.c_str());
        }
        else{
            printf("<%s> is not acceptable.\n", password.c_str());
        }
    }
    return 0;
}
