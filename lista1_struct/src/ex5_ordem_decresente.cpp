/*
Leonardo de Souza Vieira
24/03/2017
*/

#include <iostream>

using namespace std;

void ordena(int A[], int n)
{
   for(int j = 0; j < n - 1; ++j)
   {
      int m = j;

      for(int i = j + 1; i < n; ++i)
      {
         //Trocar < por > para ordenar em ordem decrescente.
         if(A[i] > A[m])
         m = i;
      }
      swap(A[m], A[j]);
   }
}

int main(int argc, char const *argv[]) {
   int vet[10] =  { 10, 9, 8, 7, 6, 3, 20, 4, 3, 100 };
   ordena(vet,10);
   for (size_t i = 0; i < 10; i++) {
      cout << vet[i] << endl;
   }

   return 0;
}
