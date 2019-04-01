#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<map>
#include<vector>

std::string str2lower(const std::string& str) {
    std::string tmp = str;
    for(std::size_t i=0; i<str.size(); i++)
        tmp[i] = tolower(tmp[i]);
    std::sort(tmp.begin(), tmp.end());
    return tmp;
}

int main() {
    std::string s, buf;
    std::map<std::string, int> word_map; // 存储小写的
    std::vector<std::string> words;
    word_map.count("r");
    while(std::cin >> s && s != "#") {
        words.push_back(s);
        std::string tmp = str2lower(s);
        if(!word_map.count(tmp)) word_map[tmp] = 0;
        word_map[tmp]++;
    }
    std::vector<std::string> res;
    for(std::size_t i=0; i<words.size(); i++) {
        // 出现一次的
        if(word_map[str2lower(words[i])]==1) {
            res.push_back(words[i]);
        }
    }
    std::sort(res.begin(), res.end());
    for(std::size_t i=0; i<res.size(); i++){
        std::cout << res[i] << std::endl;
    }
    return 0;
}