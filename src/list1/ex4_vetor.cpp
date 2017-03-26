/*
Leonardo de Souza Vieira
24/03/2017
*/

#include <iostream>
#include <random>

using namespace std;

double random_num();

int main(int argc, char const *argv[]) {
   size_t tam = 0;
   double soma = 0, media = 0;

   cout << "Digite um número:" << '\n';
   cin >> tam;

   vector<double> v(tam);

   for (size_t i = 0; i < tam; i++) {
      v.insert(v.begin(), random_num()) ;
      soma += v[i];
   }

   media = soma/tam;

   cout << soma << endl;
   cout << media<< endl;

   return 0;
}

double random_num(){
   random_device rd;
   mt19937 gen(rd());
   uniform_real_distribution<> dis(0, 100);
   return dis(gen);
}
