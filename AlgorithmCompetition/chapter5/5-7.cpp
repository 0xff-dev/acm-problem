//丑数
#include<algorithm>
#include<iostream>
#include<cstdio>

typedef long long ll;

ll _min(ll a, ll b, ll c) {
    return a>b ? b<c?b:c : a>c?c:a;
}

int main() {
    ll ugly_num[1501];
    int p2=0, p3=0, p5=0;
    ugly_num[0] = 1;
    int index = 1;
    for(; index<1501; index++) {
        ll tmp = _min(ugly_num[p2]*2, ugly_num[p3]*3, ugly_num[p5]*5);
        std::cout << index << ": " << tmp << std::endl;
        ugly_num[index] = tmp;
        while(ugly_num[p2]*2 <= tmp) p2++;
        while(ugly_num[p3]*3 <= tmp) p3++;
        while(ugly_num[p5]*5 <= tmp) p5++;
    }
    return 0;
}