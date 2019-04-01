// 对自定义的类型， set集合使用要定义<操作
#include<iostream>
#include<string>
#include<sstream> // 这个流的库， 很强..学到
#include<set>

int main(){
    std::string s, buf;
    std::set<std::string> words;
    while(std::cin >> s) {
        for(std::size_t i=0; i<s.size(); i++){
            if(isdigit(s[i])) { 
                s[i] = tolower(s[i]);
            } else{
                s[i] = ' ';
            }
        }
        std::stringstream buffer(s);
        while(buffer>>buf) words.insert(buf);
    }
    std::set<std::string>::iterator iter = words.begin();
    while(iter != words.end()) {
        std::cout << *iter << " ";
        iter++;
    }
    return 0;
}