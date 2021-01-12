#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;
int main() {
    int n;
    while(cin >> n) {
        long long total=0, x, result=0;
        vector<long long> vec;
        for(int index=0; index<n; index++) {
            cin >> x;
            total += x;
            vec.push_back(x);
        }
        unsigned length = vec.size();
        while(length>1) {
            unsigned l=0, r=1;
            if(vec[l]>vec[r]) swap(l, r);
            for(unsigned i=2; i<length; i++) {
                if(vec[l] > vec[i]) {
                    r = l;
                    l = i;
                } else if (vec[i] < vec[r]) {
                    r = i;
                }
            }
            // two min num
            long long tmp  = vec[l] + vec[r];
            result += tmp;
            if(l==length-1) swap(l, r);
            vec[l] = tmp, vec[r]=vec[length-1];
            length--;
        }
        cout << result << endl;
    }
}
