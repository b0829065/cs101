#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n){
    int* ip = (int*)calloc(n,sizeof(int));
    return  ip;
}

void set_value(int* p, int v){
    *p = v;
}

void print_array(int* p,int n){
    int i = 1;
    printf("[%d",*p);
    while(i != n){
        printf(", %d",*(p+i));
        i++;
    }
    printf("]\n");
}

// typedef struct array_list {
//     int n;
//     typedef int (*T_get_int_array)(int) ;
//     typedef int (*T_set_value)(int*,int) ;
//     typedef int (*T_print_array)(int*,int) ;
// }array_list_t;

char func(char a,char b){
    return a+b;
}

int add_str_func(char a,char b, char (*func_ptr)(char,char)){
    return func(a,b)
}

int main()
{
    int n = 10;
    
    printf("No.1 -----------\n");
    int* ip =get_int_array(n);
    for (int i = 0; i < n; i++) {
        set_value(ip+i, i+1);
    }
    print_array(ip, n);
    free(ip);
{
    printf("No.2 -----------\n");
    n = 20;
    array_list_t no_2;
    no_2.T_get_int_array = get_int_array;
    no_2.T_set_value = set_value;
    no_2.T_print_array = print_array;
    
    int* ip2 =no_2.T_get_int_array(n);
    for (int i = 0; i < n; i++) {
        no_2.T_set_value(ip2+i, i+1);
    }
    no_2.T_print_array(ip, n);
    free(ip2);
    
    // int* ip =get_int_array(n);
    // for (int i = 0; i < n; i++) {
    //     set_value(ip+i, i+1);
    // }
    // print_array(ip, n);
}
    printf("No.3 -----------\n");
    char a[] = "IU!IU!";
    char b[] = "@CGU";
    printf("add_str_func = %s\n",add_str_func(a,b,func));

    return 0;
}
