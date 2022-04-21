#include <stdio.h>
int mp3(int n, int m, int x){
        return n*m*x;
}
    
int main()
{
    int n = 10, m = 1,a = 5;
    int (*funcP)(int, int, int);
    funcP = mp3;
    printf("n*m*a = %d",funcP(n,m,a));
    return 0;
}
