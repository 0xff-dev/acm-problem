#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char SID[10];
    char CID[20];
    char name[11];
    int  chinese, math, english, program;
}student;

void Menu(int* opt) {
    printf("Welcome to student Performance Management system (SPMS)\n");
    printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n0 - Exit\nSelect opt");
    scanf("%d", opt);
}

void QueryOrDelete(student* students, int* index, int opt) {
    // opt 指删除还是查询 1 删除， 0查询
    // return:
    char s[21];
    int start = 0;
    for(;;) {
        printf("Please Enter SID or name.\n");
        scanf("%s", s);
        if(strcmp(s, "0") == 0) break;
        for(; start<*index; start++) {
            if(strcmp(students[start].SID, s)==0 || strcmp(students[start].name, s)==0) {
                // 找到
                printf("SID: %s, CID: %s, name: %s, chinese: %d, math: %d, english: %d, program: %d\n",
                    students[start].SID, students[start].CID, students[start].name, students[start].chinese, 
                    students[start].math, students[start].english, students[start].program);
                if(opt==1) {
                    int next = start+1;
                    for(; next<*index; next++){
                        students[next-1] = students[next];
                    }
                    --*index;
                    printf("%s has been removed\n", s);
                }
                return;
            }
        }
    }
}

int cmp(const void* a, const void* b) {
    //  比较的时候先看数学分数
    student* ta = (student*)a;
    student* tb= (student*)b;
    if(ta->math == tb->math) {
        int res = strcmp(ta->name, tb->name);
        if(res == 0) {
            return strcmp(ta->SID, tb->SID);
        }
        return res;
    }
    return (ta->math - tb->math);
}

void Sort(student* students, int* index) {
    qsort(students, *index, sizeof(student), cmp);
    int walk;
    for(walk=0; walk<*index; walk++){
        printf("SID: %s, CID: %s, name: %s, chinese: %d, math: %d, english: %d, program: %d\n",
            students[walk].SID, students[walk].CID, students[walk].name, students[walk].chinese,
            students[walk].math, students[walk].english, students[walk].program);
    }
}

int Judge(char* sid, student* studetns, int* index){
    int i = 0;
    for(; i < *index; i++) {
        if(strcmp(studetns[i].SID, sid)==0){
            return 1;
        }
    }
    return 0;
}

void input(student* st) {
    printf("SID: ");scanf("%s", st->SID);
    printf("CID: ");scanf("%s", st->CID);
    printf("NAME: ");scanf("%s", st->name);
    printf("CHINESE: ");scanf("%d", &st->chinese);
    printf("MATH: ");scanf("%d", &st->math);
    printf("ENGLISH: ");scanf("%d", &st->english);
    printf("PROGRAM: ");scanf("%d", &st->program);
}

void Add(student* students,int* index) {
    student st;
    for(;;){
        printf("Please enter SID CID NAME and chinese math englisg program\n");
        input(&st);
        if(!Judge(st.SID, students, index)) {
            // 应该增加index>100的判断
            students[*index] = st;
            ++*index;
            return;
        }
    }
}

int main() {
    int index = 0; // 最大是100
    int opt; // 用户操作的选择
    student students[101];
    for(;;) {
        Menu(&opt);
        if(opt == 0) break;
        switch(opt) {
        case 1:
            Add(students, &index);
            break;
        case 2:
            QueryOrDelete(students, &index, 1);
            break;
        case 3:
            QueryOrDelete(students, &index, 0);
            break;
        case 4:
            Sort(students, &index);
            break;
        }
    }
    return 0;
}