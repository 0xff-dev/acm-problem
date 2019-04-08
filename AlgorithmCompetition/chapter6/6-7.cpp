#include<iostream>
#include<sstream>
#include<string>

using namespace std;

const int maxn = 100001;
int in_order[maxn], post_order[maxn], lch[maxn], rch[maxn];
int n;

int buildTree(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return 0;
    int root = post_order[r2];
    int index = l1;
    while(in_order[index] != root) index ++;
    int cnt = index-l1;
    lch[root] = buildTree(l1, index-1, l2, l2+cnt-1);
    rch[root] = buildTree(index+1, r1, l2+cnt, r2-1);
    return root;
}

bool readList(int *arr) {
    string line;
    if(!getline(cin, line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while(ss >> x) arr[n++] = x;
    return n > 0;
}

int location, path;

void dfs(int node, int sum) {
    sum += node;
    if(!lch[node] && !rch[node]) {
        if(sum < path || (sum==path && node < location)) {location = node, path = sum;}
    }
    if(lch[node]) dfs(lch[node], sum);
    if(rch[node]) dfs(rch[node], sum);
}

int main() {
    // 3214576 3125674, 255 255 测试数据
    while(readList(in_order)) {
        readList(post_order);
        int root = buildTree(0, n-1, 0, n-1);
        path = 1000000;
        dfs(root, 0);
        cout << location << endl;
    }
    return 0;
}