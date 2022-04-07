#include <stdio.h>

void rec_dec(char *s){
    if (!*s) printf ("\n");
    else {
        printf("%c,",*s);
        rec_dec(s + 1);
    }
}

void hanoi_tower(int i ,char A, char B, char C ) {
    FILE* fp;
    fp = fopen("hanoi.txt","a");
    if (i == 1){
        fprintf(fp,"Move disk 1 form %c to %c\n", A, C);
    }
    else {
        hanoi_tower(i-1, A, C, B);
        hanoi_tower(1, A, B, C);
        hanoi_tower(i-1, B, A, C);
    }
    fclose(fp);
}

int multiplication(int i,int j){
    if (i == 10) {
        return 0;    
    } else if (j == 10){
        multiplication(i+1, 1);
    } else {
        printf("%d*%d=%d\t", i, j, i*j);
        multiplication(i, j+1);
    }
}

int main()
{
    char s[] = "1234567890";
    printf ("func#1-------------------\n");
    rec_dec(s);
    printf ("func#2-------------------\nhanoi.txt\n");
    hanoi_tower(16,'A','B','C');
    printf ("func#3-------------------\n");
    multiplication(1,1);
    return 0;
}
