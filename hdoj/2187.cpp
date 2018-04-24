#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;


struct dami{
    int price, value;
    friend bool operator <(dami d1, dami d2){
        if ( d1.price < d2.price )
            return true;
        return false;
    }
};

int main(){
    int times;
    int n, m;
    while(cin >> times){
        while(times--){
            cin >> n >> m;
            dami *dms=new dami[m];
            for( int i=0; i<m; i++ ){
                cin >> dms[i].price >> dms[i].value;
            }
            //单价小的放前面
            sort(dms, dms+m);
            float dm=0.0;
            for( int i=0; i<m; i++ ){
                //一次把小价格的大米买足
                if( n >= dms[i].price * dms[i].value ){
                    dm += dms[i].value;
                    n -= dms[i].price*dms[i].value;
                }
                else{
                    dm += n*1.0/dms[i].price;
                    break;
                }
            }
            printf("%.2f\n", dm);
            delete []dms;
        }
    }
    return 0;
}
