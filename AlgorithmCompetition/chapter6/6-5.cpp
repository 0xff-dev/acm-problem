#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int left[1000], right[1000];

void link(int l, int r ) {
    right[l] = r, left[r] = l;
}

int main() {
    
    int n, tests;
    while(scanf("%d %d", &n, &tests) != EOF) {
        for(int i=1; i<=n; i++) {
            left[i] = i-1;
            right[i] = (i+1) % (n+1);
        }
        left[0] = n, right[0] = 1;
        int op, x, y, inv = 0;
        while(tests--) {
            scanf("%d", &op);
            if(op == 4) inv = !inv;
            else {
                scanf("%d %d", &x, &y);
                if(op == 3 && right[y] == x) swap(x, y);
                if(op != 3 && inv) op = 3-inv;
                if(op == 1 && left[y] == x) continue;
                if(op == 2&& right[y] ==x) continue;
                int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
                if( op == 1) {
                    link(lx, rx), link(x, y), link(ly, x);
                } else if (op == 2) {
                    link(lx, rx), link(y, x), link(x, ry);
                } else {
                    //  是否相邻
                    if(right[x]==y) {link(lx, y), link(y, x), link(x, ry);}
                    else {link(lx, y), link(y, rx), link(ly, x), link(x, ry);}
                }
            }
        }
        int b = 0;
        long long ans = 0;
        for( int i=1; i<=n; i++) {
            b = right[b];
            if(i%2 == 1) ans += b;
        }
        // 是奇数的情况， 不需要做修改， 是偶数， 就是计算另一半.
        if(inv && n%2 == 0) ans = (long long)n*(n+1)/2-ans;
        printf("%lld\n", ans);
    }
    return 0;
}