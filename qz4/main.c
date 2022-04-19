#include <stdio.h>
#include <stdlib.h>

int swap(int* n, int* m){
    int temp = *n;
    *n = *m;
    *m = temp;
}

int swapArray(int* source, int* dest, int size){
    for(int i = 0; i < size; i++){
        swap(&source[i], &dest[i]);
    }
}

void printArray (int *source,int size) {
    int i = 1;
    printf("%d",*source);
    while(i != size){
        printf(", %d",source[i]);
        i++;
    }
    printf("]\n");
}
char* copy_string (char* str){
    int strsize = 0;
    while (*(str+strsize)!='\0') strsize++;
    char* cstr = (char*)calloc(strsize,sizeof(char));
    for(int i = 0; i<strsize; i++) {
        cstr[i] = *(str+i);
    }
    return cstr;
}
int main()
{
    int n, m;
    n = 1;
    m = 2;
    printf("No.1 -----------------------\n");
    swap(&n,&m);
    printf("after swap, n = %d, m = %d\n",n,m);
    
    printf("No.2 -----------------------\n");
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    swapArray(source,dest,size);
    printf("after swap array, source array = [");
    printArray(source,size);
    printf("after swap array, dest array = [");
    printArray(dest,size);
    
    printf("No.3 ----------------------\n");
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("copy string = %s\n", cp_str);
    free(cp_str);
    cp_str = NULL; 
  
    return 0;
}
