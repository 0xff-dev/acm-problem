#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while (cin >> n && n){
        while(n--){
            double rows=0, cols=0;
            double tmp_x, tmp_y;
            for( int i=0; i<3; i++ ){
                cin >> tmp_x >> tmp_y;
                rows+=tmp_x;
                cols+=tmp_y;
            }
            printf("%.1lf %.1lf\n", rows*1.0/3, cols*1.0/3);
        }
    }
    return 0;
}
