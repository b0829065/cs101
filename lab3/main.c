#include <stdio.h>
int my_strlen (char* s) {
    int n = 0; 
    while (*s++) n++;
    return n;
}


int rec_strlen (char* s) {
    if (*s == '\0') return 0;
    else return rec_strlen(s+1)+1;
}

int my_sort(char* s){
    
}

int main()
{
    char s[] = "IU is a girl!";
    printf("len = %d\n", my_strlen(s));
    printf("len = %d\n", rec_strlen(s));
    printf("len = %d\n", my_sort(s));
    return 0;
}
