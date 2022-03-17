#include <stdio.h>
#include <string.h>
typedef struct Employee{
    int em_id;
    char em_name[64];
    int em_age;
    char em_phone[9];
    int em_salary;
   
}Employee_t;

int main()
{
    Employee_t em_01;
    em_01.em_id = 1;
    strcpy(em_01.em_name,"Andy");
    em_01.em_age = 22;
    strcpy(em_01.em_phone,"0929855307");
    em_01.em_salary = 1000000;

    printf("id = #%02d\n", em_01.em_id);
    printf("name = %s\n", em_01.em_name);
    printf("age = %d\n", em_01.em_age);
    printf("phone = %s\n", em_01.em_phone);
    printf("salary = %d\n", em_01.em_salary);
    return 0;
}
