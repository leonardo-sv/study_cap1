#include <iostream>
#include <string>

using namespace std;

void _start();

int leo()
{
  string nome;

  cout << "Qual o seu nome? ";

  cin >> nome;

  cout << "\nOlá " << nome.find('c') << "!" << endl;

 return 0;
}

void _start() {
  int ret = leo();
  exit(ret);
}
