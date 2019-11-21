#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int Id;
    char Name[50];
    double Score;
} student;



int cmp_name(const void* a, const void* b) {
    return strcmp(((student*)a)->Name, ((student*)b)->Name);
}

int cmp_score(const void* a, const void* b) {
    return ((student*)b)->Score > ((student*)a)->Score;
}

void print(student* stu, int* visited, int num) {
    int index = 0;
    for(; index < num; index++) {
        if(visited[stu[index].Id-1] == 0) {
            printf("id: %d --- name: %s --- score: %lf\n", stu[index].Id, stu[index].Name, stu[index].Score);
        }
    }
}


void sort_student(student* stu, int* visited, int num) {
    int index = 0;
    student* new_array = (student*)malloc(num);
    for(; index < num; index++){
        new_array[index] = stu[index];
    }
    printf("sort by name\n");
    qsort(new_array, num, sizeof(student), cmp_name);
    print(new_array, visited, num);
    printf("sort by score\n");
    qsort(new_array, num, sizeof(student), cmp_score);
    print(new_array, visited, num);
}

int walk(int start, int step, int num, int* all_human, int* pre, int* visited) {
    int cnt = 0;
    for(; cnt < step; cnt++) {
        *pre = start;
        do {
            start = (start+1) % num;
        }while(visited[start]);
    }
    visited[*pre] = 1;
    (*all_human)--;
    return start;
}


void start() {
    int num;
    printf("humans: ");scanf("%d", &num);
    int index = 0, step, all_human = num, next=0, pre=0;
    student* stus = (student*)malloc(num);
    int* visited = (int*)malloc(num);
    for(; index < num; index++) {
        visited[index] = 0;
        stus[index].Id = index+1;
        printf("name, score:");scanf("%s %lf", stus[index].Name, &stus[index].Score);
    }
    printf("students\n");
    print(stus, visited, num);
    // 输入走的步数
    printf("input m:");scanf(" %d", &step);
    if(step == 0) {
        printf("can not run ....\n");
        return;
    }
    while(all_human > 1) {
        next = walk(next, step, num, &all_human, &pre, visited);
        printf("delete: --- id: %d --- name: %s --- score: %lf all huamn:%d\n", stus[pre].Id, stus[pre].Name, stus[pre].Score, all_human);
        sort_student(stus, visited, num);
    }
    free(stus);
    free(visited);
}

int main()
{
    start();
    printf("Hello world\n");
    return 0;
}

