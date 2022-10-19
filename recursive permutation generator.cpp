/******************************************************************************
https://stackoverflow.com/questions/7537791/understanding-recursion-to-generate-permutations
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
