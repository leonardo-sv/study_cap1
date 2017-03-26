/*
Leonardo de Souza Vieira
25/03/2017

São José dos Campos
Latitude: 23º 10' 46" S   Latitude: -23.223701°
Longitude: 45º 53' 13" O  Longitude:-45.900907399999994°

Londres
Latitude: 51°30′30″ N   Latitude: 51.5085300°
Longitude: 0°07′32″ O   Longitude: -0.1257400°

*/
#include "struct_space2D.hpp"

using namespace std;

void texto_entrada(point&,point&);

int main(int argc, char const *argv[]) {

   point pt1;
   point pt2;
   texto_entrada(pt1, pt2);
   double d =  distance_haversine(pt1, pt2);

   cout << "A distância entre os pontos é:" << d << " km" << endl;

   return 0;
}

void texto_entrada(point& pt1, point& pt2){
   double aux = 0;
   cout << "Digite  a longitude e latitude de dois pontos do globo." << endl;
   cout << "Longitude ponto1:" << endl;
   cin >> aux;
   pt1.x = degrees_to_radians(aux);
   cout << "Latitude ponto1:" << endl;
   cin >> aux;
   pt1.y = degrees_to_radians(aux);
   cout << "Longitude ponto2:" << endl;
   cin >> aux;
   pt2.x = degrees_to_radians(aux);
   cout << "Latitude ponto2:" << endl;
   cin >> aux;
   pt2.y = degrees_to_radians(aux);
}
