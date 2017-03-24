/*
Leonardo de Souza Vieira
24/03/2017
*/

#include <iostream>
#include <utility>
#include <iterator>

void troca(int *a, int *b)
{
   int tmp = *b;
   *b = *a;
   *a = tmp;
}
void ordena(int A[], int n)
{
   for(int j = 0; j < n - 1; ++j)
   {
      int m = j;
         for(int i = j + 1; i < n; ++i)
         {
            if(A[i] < A[m])
            m = i;
         }
      troca(&A[m], &A[j]);
   }
}

int main()
{
   int A[] = { 30, 12, 76, 28, 3, 78, 4, 3, 11 };

   const std::size_t n = sizeof(A) / sizeof(int);

   std::copy(A, A + n, std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   ordena(A, n);

   std::copy(A, A + n, std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   return EXIT_SUCCESS;

}
