#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 100001;
int sum[maxn];

void build(int pos) {
    int v; cin >> v;
    if(v == -1) return;
    sum[pos] += v;
    build(pos-1), build(pos+1);    
}

bool init() {
    int root; cin >> root;
    if(root == -1) return false;
    memset(sum, 0, sizeof(sum));
    int pos = maxn/2;
    sum[pos] = root;
    build(pos-1), build(pos+1);
    return true;
}

int main() {
    while(init()) {
        int index = 0;
        while(sum[index] == 0) index++;
        printf("Case: \n");
        while(sum[index] != 0) {
            cout << sum[index++] << " ";
        }
        cout << endl;
    }
    return 0;
}