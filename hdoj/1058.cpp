#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 5842

using namespace std;

long long HumbleNumber[5845];

long long min_num(int x1, int x2, int x3, int x4){
    int _xx1=min(x1, x2), _xx2=min(x3, x4);
    return _xx1>_xx2?_xx2:_xx1;
}

void init(){
    HumbleNumber[0]=1;
    int index=1;
    long long* p2=HumbleNumber;
    long long* p3=HumbleNumber;
    long long* p5=HumbleNumber;
    long long* p7=HumbleNumber;

    while( index<LEN ){
        long long min_humble_number=min_num(*p2*2, *p3*3, *p5*5, *p7*7);
        HumbleNumber[index]=min_humble_number;
        while(*p2*2<=HumbleNumber[index])
            ++p2;
        while(*p3*3<=HumbleNumber[index])
            ++p3;
        while(*p5*5<=HumbleNumber[index])
            ++p5;
        while(*p7*7<=HumbleNumber[index])
            ++p7;
        ++index;
    }
}

int main(){
    int n;
    init();
    while(cin >> n &&n!=0){
        int tmp=n%10;
        cout << "The " << n;
        if( tmp==1 && n%100!=11 ) cout << "st";
        else if(tmp==2 && n%100!=12) cout << "nd";
        else if(tmp==3 && n%100!=13) cout << "rd";
        else cout << "th";
        cout << " humble number is " << HumbleNumber[n-1]<<"." << endl;
    }
    return 0;
}
