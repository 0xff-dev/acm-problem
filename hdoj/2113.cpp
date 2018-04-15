#include <iostream>
#include <cstdio>

using namespace std;

bool is_oushu(char c){
    if( int(c-'0')%2==0 )
        return true;
    return false;
}

int main(){
    string s;
    bool first=true;
    while( cin >> s ){
        int sum=0;
        for( int i=0; i<s.size(); i++ ){
            if( is_oushu(s[i]) )
                sum+=int(s[i]-'0');
        }
        if(first){
            printf("%d\n", sum);
            first=false;
        }
        else{
            printf("\n");
            printf("%d\n", sum);
        }
    }
    return 0;
}
