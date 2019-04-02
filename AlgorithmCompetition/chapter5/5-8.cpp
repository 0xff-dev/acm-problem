// 在输入的过程找到最大的长度
// 按列打印
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
const int maxcols = 60;
const int maxn = 10001;
string filenames[maxn];

void print(string filename, int len, char extra) {
    cout << filename;
    for(int i=0; i<len-filename.length(); i++) cout << extra;
}

int main() {
    int n;
    while(cin >> n) {
        int max_len = -1;
        for(size_t i=0; i<n; i++) {
            cin >> filenames[i];
            max_len = max(max_len, (int)filenames[i].length());
        }
        sort(filenames, filenames+n);
        int cols = (maxcols - max_len) / (max_len+2)+1;
        int rows = (n-1)/cols + 1;
        print("", 60, '-');
        cout << endl;
        for(int j=0; j<rows; j++){
            for(int i=0; i<cols; i++) {
                // 横向打印 id = j*cols+i
                int id = i*rows + j;
                if(id < n) print(filenames[id], i==cols-1?max_len:max_len+2, ' ');
            }
            cout << endl;
        }
    }
    return 0;
}