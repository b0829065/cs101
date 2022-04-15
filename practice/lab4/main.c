#include <stdio.h>

// int findnum(int** pp,int find){
//     int i = 0;
//     while((*((*pp)+i)) != find){
//         i++;
//     }
//     return i;
// }

static int count;

int* find(int* n,int findnum,int n_max){
    count = 0;
    while (*(n+count) != findnum){
        count++;
        if(count > n_max) return NULL; //return 0
    }
    return (n+count);
}

int main()
{
    int n[]={6,4,7,12,11,8,1,5,3,14,54,20,77,15};
    int n_max = sizeof(n)/sizeof(int);
    int* p ;
    int* ap[n_max]; 
    
    printf("No.1 -------------------\n");
    int findnum = 11;
    p = find(n,findnum,n_max);
    printf("&n[%d]->%p,n[%d]=%d; p->%p, *p=%d\n",count,&n[count],count,n[count],p,*p);

    printf("No.2 -------------------\n");
    int min = 0;
    for (int i = 0; i < n_max;) {
        if (find(n,min,n_max)) {
            ap[i] = find(n,min,n_max);
            printf("&n[%d] -> %p, n[%d] = %d; ap[%d] -> %p, *ap[%d] = %d\n", count, &n[count], count, n[count], i, ap[i], i, *ap[i]);
            min++;
            i++;
        } else {
            min++;
        }
    }
    return 0;
}
