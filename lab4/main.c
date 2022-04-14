#include <stdio.h>

void abc() {
    int n[] = {6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
    int* p;
    int x = 0;
    for (x = 0; n[x] != 9; x++);
    p = n + x;
    printf("&n[%i]->%p, n[%i]=%i; p->%p, *p=%i\n", x, &n[x], x, n[x], p, *p);
}

void cj() {
    int n[] = {6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
    int* ap[10];
    for (int i = 0; i < sizeof(n) / sizeof(n[0]); i++) {
    ap[n[i]] = n + i;
    }
    for (int i = 0; i < sizeof(ap) / sizeof(ap[0]); i++) {
    int x = 0;
    for (x = 0; n[x] != *ap[i]; x++);
    printf("&n[%i]->%p, n[%i]=%i; ap[%i]->%p, *ap[%i]=%i\n", x, &n[x], x, n[x], i, ap[i], i, *ap[i]);
    }
}

int main() {
    printf("No.1 -------------------\n");
    abc();
    printf("No.2 -------------------\n");
    cj();
    return 0;
}
