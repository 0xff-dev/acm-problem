#include<iostream>
#include<algorithm>
#include<sstream>
#include<map>
#include<vector>

int main() {
    int n, m;
    std::string str;
    std::map<std::string, int> keys;
    std::map<std::string, int> mark; // 给字符串一个标记.
    std::vector<std::string> words;  // 存储单词
    std::ostringstream buf;
    while(std::cin >> n >> m) {
        int c1, c2;
        for( int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                std::cin >> str;
                words.push_back(str);
                mark[str] = i*m+j;
            }
        }
        for(c1=0; c1 < m-1; c1++){
            for(c2=c1+1; c2 < m; c2++){
                for(int row=0; row<n; row++){
                    int cell1 = row*m+c1, cell2 = row*m+c2;
                    buf.clear();                
                    buf<< words[cell1] << words[cell2];
                    std::string key = buf.str();
                    if(keys.count(key) != 0) {
                        return true;
                    } else{
                        keys[key] = row;
                    }
                }
            }
        }
    }
    return 0;
}