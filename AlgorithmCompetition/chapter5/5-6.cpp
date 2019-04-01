#include<cstdio>
#include<map>
#include<queue>

const int maxn = 10001;

int main() {
    int t, kcase;
    while(scanf("%d", &t)==1 && t) {
        printf("Scenario %d:\n", ++kcase);
        std::map<int, int> team; // 存储用户对应的队号
        for(int i=0; i<t; i++){
            int n, x;
            scanf("%d", &n);
            while(n--){
                scanf("%d", &x);
                team[x] = i;
            }
        }
        std::queue<int> qs, team_queue[maxn];
        for(;;){
            int x;
            char opt[10];
            scanf("%s", opt);
            if(opt[0] == 'S') break;
            else if (opt[0] == 'D') {
                int tmp = qs.front(); //最前的队列编号
                printf("%d\n", team_queue[tmp].front()); team_queue[tmp].pop();
                if(team_queue[tmp].empty()) qs.pop();
            } else if(opt[0] == 'E'){
                scanf("%d", &x);
                int team_code = team[x];
                if(team_queue[team_code].empty()) qs.push(team_code);
                team_queue[team_code].push(x);
            }
        }
        printf("\n"); 
    }
    return 0;
}