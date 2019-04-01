#include<iostream>
#include<cstdio>
#include<vector>

const int maxn = 30;
std::vector<int> pipe[maxn];
int n;

// 找到要操作的木块的位置(x, y)
void find_block(int a, int& p, int &h) {
    for(p=0; p<n; p++) {
        for(h=0; h<pipe[p].size(); h++){
            if(pipe[p][h] == a) return;
        }
    }
}

// 清理之上的数据
void clear_above(int p, int h) {
    for(std::size_t i=h; i<pipe[p].size(); i++){
        int b = pipe[p][i];
        pipe[b].push_back(b);
    }
    pipe[p].resize(h+1);
}

// 把高度h及h以上的数据放到p2上
void pipe_onto(int p, int h, int p2) {
    for(std::size_t i=h; i<pipe[p].size(); i++) {
        pipe[p2].push_back(pipe[p][i]);
    }
    pipe[p].resize(h);
}

void print() {
    for(std::size_t i=0; i<n; i++) {
        printf("%d: ", i);
        for(std::size_t j=0; j<pipe[i].size(); j++){
            printf(" %d", pipe[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a, b;
    std::string opt1, opt2;
    for(std::size_t i=0; i<n; i++) pipe[i].push_back(i);
    while(std::cin >> opt1 >> a >> opt2 >> b) {
        int pa, pah, pb, pbh;
        find_block(a, pa, pah);
        find_block(b, pb, pbh);
        if(opt2 == "onto") clear_above(pb, pbh);
        if(opt1 == "move") clear_above(pa, pah);
        pipe_onto(a, pah, pb);
    }
    print();
    return 0;
}