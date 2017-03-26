/*
Leonardo de Souza Vieira
24/03/2017
*/

#include <iostream>
#include <random>

using namespace std;


int main(int argc, char const *argv[]) {
   size_t tam = 10;
   double v[tam], soma = 0;

   random_device rd;
   mt19937 gen(rd());
   uniform_real_distribution<> dis(0, 100);

   for (size_t i = 0; i < tam; i++) {
      v[i] = dis(gen);

   }
   for (size_t i = 0; i < tam; i++) {
         soma += v[i];
   }
   cout << soma << endl;
   return 0;
}
