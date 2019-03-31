/*
    计算组合数
*/

#include<iostream>

// C(n, m)
long long CNM(int n, int m) {
    if (m < n-m) m = n-m;
    long long ans = 1;
    for(int i=m+1; i<=n; i++) ans *= i;
    for(int i=1; i <=n-m; i++) ans /= i;
    return ans;
}

int main() {
    std::cout << CNM(9, 4) << std::endl;
    return 0;
}