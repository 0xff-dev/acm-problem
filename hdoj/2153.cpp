#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int result[11][11];

int main(){
    int n;
    while(cin >> n && n!=0){
        if (n==1){
            printf("1  \n");
        }
        else{
            int i=0, j=0;
            int index=1;
            memset(result, 0, sizeof(result));
            //向右
            while(j<n){
                result[i][j]=index++;
                j++;
            }
            j--;
            i++;
            while(i<n){
                result[i][j]=index++;
                i++;
            }
            j--, i--;
            while(j>=0){
                result[i][j]=index++;
                j--;
            }
            j++, i--;
            while(i>0){
                result[i][j]=index++;
                i--;
            }
            for( int i=0; i<n; i++ ){
                for( int j=0; j<n; j++ ){
                    if( result[i][j] == 0){
                        printf("%3c", ' ');
                    }
                    else{
                        printf("%3d", result[i][j]);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
