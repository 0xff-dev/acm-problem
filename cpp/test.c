#include <stdio.h>

void swap(int a, int b, void (*p)(int, int)) {
    p(a, b);
}

void q(int a, int b) {
    printf("%d %d\n, function pointer\n", a, b);
}
int main()
{
    int a=3, b=4;
    swap(a, b, &q);
    int* p = &a;
    int* q = &b;
    printf("%d %d\n", *p, *q);
    int *t = p;
    p = q;
    q = t;
    printf("%d %d\n", *p, *q);
    return 0;
}

