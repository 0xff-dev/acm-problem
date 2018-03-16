#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MIN 1e-9

using namespace std;

struct segment {
    double start_x, start_y;
    double end_x, end_y;
};

double xmult(segment& seg, double  x, double y){
    //根据返回值的正负确实点(x, y)在线段的位置
    return (seg.end_x-seg.start_x)*(y-seg.end_y)-(x-seg.end_x)*(seg.end_y-seg.start_y);
}

bool point_in_line(segment& seg, double x, double y){
    if( x>=min(seg.start_x, seg.end_x) && x<=max(seg.start_x, seg.end_x) &&
        y>=min(seg.start_y, seg.end_y) && y<=max(seg.start_y, seg.end_y))
        return true;
    return false;
}
//判断直线相交?
//两种情况, AB两点分别在线段CD的两端, CD两点分别在AB线段两边
//点在线段上
bool segment_is_intersection(segment& s1, segment& s2){
    double res1 = xmult(s1, s2.start_x, s2.start_y);
    double res2 = xmult(s1, s2.end_x, s2.end_y);
    double res3 = xmult(s2, s1.start_x, s1.start_y);
    double res4 = xmult(s2, s1.end_x, s1.end_y);
    if( (res1 == 0 && res2 ==0))
        return true;
    if( (res1*res2<=0)&& (res3*res4<=0))
        return true;
    if( fabs(res1)==MIN && point_in_line(s1, s2.start_x, s2.start_y) ) return true;
    if( fabs(res2)==MIN && point_in_line(s1, s2.end_x, s2.end_y)) return true;
    if( fabs(res3)==MIN && point_in_line(s2, s1.start_x, s1.start_y) ) return true;
    if( fabs(res4)==MIN && point_in_line(s2, s1.end_x, s1.end_y) ) return true;
    return false;
}

int solve_func(segment* segments, int n){
    int sum = 0;
    for( int i=0; i<n-1; i++ )
        for(int j=i+1; j<n; j++){
            if(segment_is_intersection(segments[i], segments[j]))
                sum++;
        }
    return sum;
}
int main(){
    segment segments[101];
    int n;
    while( cin >> n && n){
        for( int i=0; i<n; i++ ){
            cin >> segments[i].start_x >> segments[i].start_y;
            cin >> segments[i].end_x >> segments[i].end_y;
        }
        cout << solve_func(segments, n) << endl;
    }
    return 0;
}
