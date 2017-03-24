/*
Leonardo de Souza Vieira
24/03/2017
*/


#include <iostream>

using namespace std;


int main(int argc, char const *argv[]) {
   int l1 = 0, l2 = 0, l3 = 0;

   //Testa se o número de arguementos corresponde a 4. O primeiro argumento é o ./nomeprograma
   if (argc != 4) {
      cout << " [uso] ./triangulo_ex2 <int lado1> <int lado2> <int lado3>" << endl;
      return -1 ;
   }
   //converte a entrada char[posicao] em inteiro
   l1 = stoi(argv[1]);
   l2 = stoi(argv[2]);
   l3 = stoi(argv[3]);

   //Faz o teste de verificação se os valores dos lados formam um triangulo
   if(l1 + l2 >= l3 && l2 + l3 >= l1 && l1 + l3 >= l2){
      //verifica se todos os lados do triangulo são iguais. Neste caso os lados formam um triangulo Equilatero
      if ((l1 == l2) && (l1 == l3) && (l2 == l3))
         cout << "Equilatero" << endl;
      //verifiva se todos os lados do triangulo são diferentes. Neste caso os lados formam um triangulo Escaleno.
      else if ((l1 != l2) && (l1 != l3) && (l2 != l3))
         cout << "Escaleno"<< endl;
      //por default se o triangulo não é escaleno nem equilátero ele é isosceles
      else
         cout << "Isosceles" << endl;

   }else{
      cout << "Nao e um triangulo!" << endl;
   }

  return 0;
}
