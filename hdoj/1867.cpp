#include <iostream>
#include <cstring>
#include <string>
#include <cstring>
#define MAX 1000001
using namespace std;


void getNext(const string& str, int* next){
    next[0] = -1;
    unsigned int i=0;
    int j=-1;
    while( i< str.size()){
        if( j==-1 || (str[i] == str[j]) ){
            i++;
            j++;
            next[i] = j;
        }
        else{
            j = next[j];
        }
    }
}

int kmp(const string& str1, const string& str2){
    int* next = new int[MAX];
    int len_s1 = str1.size();
    int len_s2 = str2.size();
    int index_s1=0, index_s2=0;
    if (len_s1>len_s2){
        index_s1=len_s1-len_s2;
    }
    getNext(str2, next);
    while( index_s1 < len_s1 && index_s2 < len_s2 ){
        if (index_s2==-1 || str1[index_s1] == str2[index_s2]){
            index_s1++;
            index_s2++;
        }
        else{
            index_s2 = next[index_s2];
        }
    }
    delete []next;
    if ( index_s1 == len_s1 ){
        return index_s2;
    }
    else
        return 0;
}

int main(){
    string base_str, test_str;
    while( cin >> base_str >> test_str ){
        int b_t = kmp(base_str, test_str);
        int t_b = kmp(test_str, base_str);
        if ( b_t == t_b ){
            if (base_str>test_str){
                cout << test_str;
                cout << base_str.substr(t_b, base_str.size()+1) << endl;
            }else{
                cout << base_str;
                cout << test_str.substr(b_t, test_str.size()+1) << endl;
            }
        }
        else if(b_t>t_b){
            cout << base_str;
            cout << test_str.substr(b_t, test_str.size()+1) << endl;
        }
        else{
            cout << test_str;
            cout << base_str.substr(t_b, base_str.size()+1) << endl;
        }
    }
    return 0;
}
