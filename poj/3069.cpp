#include <iostream>
#include <cstring>
#include <algorithm>

using namespace  std;

int data[10001];
int main(){
    int r, len, ans;
    while(cin >> r >> len && r!=-1 && len!=-1){
        memset(data, 0, sizeof(data));
        ans=0;
        for(int i=0; i<len; i++)
            cin >> data[i];
        sort(data, data+len);
        int index=0;
        while(index<len){
            int tmp=data[index++];
            while(index<len && tmp+r>=data[index]){
                index++;
            }
            tmp=data[index-1];
            while(index<len && tmp+r>=data[index])
                index++;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
