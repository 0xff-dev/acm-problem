#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
    int x, y;
};

// 叉积
int xmult(point& p0, point& p1, point& p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}


void solve_func(vector<point>& vec_point, int len){
    // 做len次计算, 其中发现凹陷的直接 退出
    // 一组测试数据 1 0, 2 -1, 3 1, -8 4因为少了最后一次判断，wrong了好几次
    if( len == 2 ){
        cout << "concave" << endl;
        return;
    }
    bool flag = false;
    for( int i=0; i<len; i++ ){
        double tmp_xmult = xmult(vec_point[i], vec_point[(i+1)%len], vec_point[(i+2)%len]);
        if( tmp_xmult < 0 ){
            flag = true;
            break;
        }
    }
    if (flag){
        cout << "concave" << endl;
        return;
    }
    cout << "convex" << endl;
}

int main(){
    int len;
    vector<point> vec_point;
    while( cin >> len && len){
        for( int i=0; i<len; i++ ){
            point tmp;
            cin >> tmp.x;
            cin >> tmp.y;
            vec_point.push_back(tmp);
        }
        solve_func(vec_point, len);
        vec_point.clear();
    }
    return 0;
}
