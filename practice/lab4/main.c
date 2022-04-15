#include <stdio.h>

// int findnum(int** pp,int find){
//     int i = 0;
//     while((*((*pp)+i)) != find){
//         i++;
//     }
//     return i;
// }

static int count;

int* find(int* n,int findnum){
    count = 0;
    while (*(n+count) != findnum) count++;
    return (n+count);
}

int main()
{
    int n[]={6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
    int* p ;
    int* ap[10]; 
    // int position=findnum(&p,find);
    
    printf("No.1 -------------------\n");
    int findnum = 3;
    p = find(n,findnum);
    printf("&n[%d]->%p,n[%d]=%d; p->%p, *p=%d\n",count,&n[count],count,n[count],p,*p);

    printf("No.2 -------------------\n");
    int n_max = sizeof(n)/sizeof(int);
    int min = 0;
    for (int i = 0; i < n_max; i++) {
        if (find(n,min)) {
            ap[i] = find(n,min);
            printf("&n[%d] -> %p, n[%d] = %d; ap[%d] -> %p, *ap[%d] = %d\n", count, &n[count], count, n[count], i, ap[i], i, *ap[i]);
            min++;
        } else {
            min++;
        }
    }
    
    return 0;
}
