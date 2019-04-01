/**
 * define sort func with cmp function
 * 
*/

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

/* define func pointer */
typedef int (*PIF)(const string&, const string&);


/**
 * Compare functions define
*/
void _srot(string*, string*, PIF);
int lexicoCompare(const string&, const string&);
int sizeCompare(const string&, const string&);
void display(const string*, int);


int lexicoCompare(const string& _s1, const string& _s2){
    return _s1.compare(_s2);
}

int sizeCompare(const string& _s1, const string& _s2){
    return _s1.size() - _s2.size();
}

void _sort(string* s1, string* s2, PIF compare=lexicoCompare){
    if(s1 < s2){
        string ele = *s1;
        string* left = s1;
        string* right = s2;
        while(left<right){
            /* 相同的顺序不变，稳定的排序 */
            while(left<right && compare(*right, ele)>=0)
                right--;
            while(left<right && compare(*left, ele)<0)
                left++;
            if(left<right){
                /* 别交换成指针，指针的位置不能变 */
                swap(*left, *right);
            }
        }
        _sort(s1, left-1, compare);
        _sort(left+1, s2, compare);
    }
}

void display(const string* res, int size){
    for( int i=0; i<size; i++){
        cout << res[i] << " ";
    }
    cout << "\n";
}


int main()
{
    string str[5] = {
        "asdf", "hhhh", "tttt",
        "ew","yuyuy"
    };
    _sort(str, str+4);
    cout << "asc sort: ";
    display(str, 5);
    _sort(str, str+4, sizeCompare);
    cout << "size sort: ";
    display(str, 5);
    return 0;
}
