#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;
const int LENGTH=8005;

int main(){
    int conins[3]={1, 2, 5};
    int nums[3];
    int c1[LENGTH], c2[LENGTH];
    while(cin >> nums[0] >> nums[1] >> nums[2]){
        if (nums[0]+nums[1]+nums[2] == 0)
            break;
        int max_value=nums[0]+2*nums[1]+5*nums[2];
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for(int i=0; i<=nums[0]; i++){
            //初始化1+x+x^2+x^3.....
            c1[i]=1;
        }
        for(int i=1; i<3; i++){
            for(int j=0; j<=max_value; j++){
                for(int k=0; (k+j<=max_value)&&(k<=conins[i]*nums[i]); k+=conins[i]){
                    c2[j+k]+=c1[j];
                }
            }
            for(int i=0; i<=max_value; i++){
                c1[i]=c2[i];
                c2[i]=0;
            }
        }
        for(int i=0; i<=max_value+1; i++){
            if(c1[i]==0){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
