#include<iostream>
#include<cstring>
#include<stack>

const int maxn = 1000;
int target[maxn];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++) {
            scanf("%d", &target[i]);
        }
        std::stack<int> s;
        for(int i=n-1; i>=0; i--) {
            s.push(target[i]);
        }
        std::stack<int> in;
        int index = 0;
        while(index <= n) {
            in.push(++index);
            while(!s.empty() && !in.empty() && s.top() == in.top()) {
                s.pop();
                in.pop();
            }
        }
        printf("%s\n", s.empty() ? "yes": "no");
    }
    return 0;
}