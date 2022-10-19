/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

void permute(char a[], int i, int n)
{
   int j;
   if (i == n)
     cout << a << endl;
   else
   {
       for (j = i; j <= n; j++)
       {
          swap(a[i], a[j]);          
          permute(a, i+1, n);
          swap(a[i], a[j]);
       }
   }
} 

int main()
{
   char a[] = "ABC";
   permute(a, 0, 2);
   getchar();
   return 0;
}
