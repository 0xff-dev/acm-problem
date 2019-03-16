#include<iostream>
#include<string>
using namespace std;


int main() {
    int n;
    while(cin >> n){
        string *strs = new string[n];
        for( int i=0; i<n; i++) {
            cin >> strs[i];
        }
        for( int i=0; i<n; i++){
            int s=0, e=1;
            while(e < strs[i].size()) {
                while(e < strs[i].size() && strs[i][s]!=strs[i][e]) {
                    s++;
                    e++;
                }
                int end1=e+1, end2=e+2;
                while(end1 < strs[i].size() && strs[i][e] == strs[i][end1]) {
                    strs[i].erase(end1, 1);
                }
                while(end1<strs[i].size() && end2 < strs[i].size() && strs[i][end1]==strs[i][end2]) {
                    strs[i].erase(end2, 1);
                }
                s++;
                e++;
            }
            cout << strs[i] << endl;
        }
        delete []strs;
    }
}