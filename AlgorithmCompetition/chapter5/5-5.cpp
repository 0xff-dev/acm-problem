// 遇到复杂的表示， 可以考虑给一个id， 用来存储. map映射， vector存储
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>
#include<set>

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

typedef std::set<int> Set;
std::map<Set, int> IDCache;
std::vector<Set> Setcache;

int ID(Set x) {
    if(IDCache.count(x)) return IDCache[x];
    Setcache.push_back(x);
    return IDCache[x] = Setcache.size()-1;
}

int main() {
    std::stack<int> s;
    int n;
    std::cin >> n;
    for( int i=0; i<n; i++) {
        std::string opt;
        std::cin >> opt;
        // 添加
        if(opt[0] == 'P') s.push(ID(Set()));
        else if (opt[0] == 'D') s.push(s.top());
        else {
            Set x1 = Setcache[s.top()]; s.pop();
            Set x2 = Setcache[s.top()]; s.pop();
            Set x;
            if(opt[0] == 'U') std::set_union(ALL(x1), ALL(x2), INS(x));
            if(opt[0] == 'I') std::set_intersection(ALL(x1), ALL(x2), INS(x));
            if(opt[0] == 'A') {x=x2; x.insert(ID(x1));}
            s.push(ID(x));
        }
        std::cout << Setcache[s.top()].size() << std::endl;
    }
    return 0;
}