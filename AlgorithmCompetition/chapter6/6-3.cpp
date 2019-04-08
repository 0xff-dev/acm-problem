#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<stack>

using namespace std;


struct matrix {
    int row, col;
    matrix(int a=0, int b=0):row(a), col(b){}
}m[26];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++) {
            string name;
            cin >> name;
            cin >> m[name[0]-'A'].row >> m[name[0]-'A'].col;
        }
        string expr;
        stack<matrix> s;
        bool err = false;
        int cnt = 0;
        cin >> expr;
        int len = expr.length();
        for(int i=0; i<len; i++) {
            if(isalpha(expr[i])) s.push(m[expr[i]-'A']);
            else if (expr[i] == ')') {
                matrix a = s.top(); s.pop();
                matrix b = s.top(); s.pop();
                if(b.col != a.row) {err = true; break;}
                cnt += (b.row * b.col * a.col);
                s.push(matrix(b.row, a.col));
            }
        }
        if(err)
            printf("error\n");
        else{
            printf("%d\n", cnt);
        }
    }
    return 0;
}