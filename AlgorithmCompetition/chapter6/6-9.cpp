#include<iostream>
#include<cstdio>

using namespace std;

// 左右子树相等的基础之上， 计算当前节点.
bool solve(int& w) {
    int w1, d1, w2, d2;
    cin >> w1 >> d1 >> w2 >> d2;
    bool r1=true, r2=true;
    // 当左子树不为空的时候，
    if(!w1) r1 = solve(w1);
    if(!w2) r2 = solve(w2);
    w = w1 + w2;
    return r1 && r2 && (w1*d1 == w2*d2);
}

int main() {
    int T;
    int res;
    cin >> T;
    while(T--){
        if(solve(res)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
