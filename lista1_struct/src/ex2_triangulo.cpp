/*
Leonardo de Souza Vieira
24/03/2017
*/


#include <iostream>

using namespace std;


int main(int argc, char const *argv[]) {
   int l1 = 0, l2 = 0, l3 = 0;

   //Testa se o número de arguementos corresponde a entrada.
   if (argc != 4) {
      cout << " [uso] ./triangulo_ex2 <int lado1> <int lado2> <int lado3>" << endl;
      return -1 ;
   }
   //Converte a entrada char[posicao] em inteiro.
   l1 = stoi(argv[1]);
   l2 = stoi(argv[2]);
   l3 = stoi(argv[3]);

   //Faz o teste de verificação se os valores dos lados formam um triângulo
   if(l1 + l2 >= l3 && l2 + l3 >= l1 && l1 + l3 >= l2){
      //Verifica se todos os lados do triangulo são iguais. Neste caso os lados formam um triângulo Equilatero
      if ((l1 == l2) && (l1 == l3) && (l2 == l3))
         cout << "Equilátero" << endl;
      //Verifica se todos os lados do triângulo são diferentes. Neste caso os lados formam um triângulo Escaleno.
      else if ((l1 != l2) && (l1 != l3) && (l2 != l3))
         cout << "Escaleno"<< endl;
      //Se o triangulo não é escaleno nem equilátero ele é isosceles
      else
         cout << "Isosceles" << endl;

   }else{
      cout << "Nao é um triângulo!" << endl;
   }

  return 0;
}
