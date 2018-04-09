#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char data[1002];
    while(scanf("%d", &n)!=EOF){
        getchar();
        while(n--){
            gets(data);
            int len=strlen(data);
            int index=0, i, j;
            for( i=0; i<len; i++ ){
                if( data[i]==' ' ){
                    for( j=i-1; j>index; j--, index++ ){
                        char tmp=data[index];
                        data[index]=data[j];
                        data[j]=tmp;
                    }
                    index=i+1;
                }
                else if( i==len-1 && data[i]!=' '){
                    for( j=i; j>index;j--,index++ ){
                        char tmp=data[index];
                        data[index]=data[j];
                        data[j]=tmp;
                    }
                }
            }
            printf("%s\n", data);
        }
    }
    return 0;
}
