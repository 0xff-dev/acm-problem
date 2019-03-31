#include<cstdio>
#include<algorithm>

const int len=10000;

int main() {
    int n, q, x, arr[len], _case=0;
    while(scanf("%d %d", &n, &q)==2 && n) {
        printf("CASE: %d\n", ++_case);
        for(int s=0; s<n; s++) scanf("%d", &arr[s]);
        std::sort(arr, arr+n);
        while(q--) {
            scanf("%d", &x);
            // lower_bound 查找第一个符合的目标)
            int p = std::lower_bound(arr, arr+n, x) - arr;
            if(arr[p] == x) printf("%d found at %d\n", x, p+1);
            else printf("%d not found!\n", x);
        }
    }
    return 0;
}