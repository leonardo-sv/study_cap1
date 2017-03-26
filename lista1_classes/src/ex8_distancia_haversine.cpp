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
#include "space2D.hpp"
#include <iostream>

using namespace std;

void texto_entrada(double&, double&, double&, double&);

int main(int argc, char const *argv[]) {
   double pt1x, pt1y, pt2x, pt2y;
   texto_entrada(pt1x, pt1y, pt2x, pt2y);
   Point pt1(pt1x, pt1y);
   Point pt2(pt2x, pt2y);

   double d =  distance_haversine(pt1, pt2);

   cout << "A distância entre os pontos é:" << d << " km" << endl;

   return 0;
}

void texto_entrada(double& pt1x, double& pt1y, double& pt2x, double& pt2y){
   double aux = 0;
   cout << "Digite  a longitude e latitude de dois pontos do globo." << endl;
   cout << "Latitude ponto1:" << endl;
   cin >> aux;
   pt1y = degrees_to_radians(aux);
   cout << "Longitude ponto1:" << endl;
   cin >> aux;
   pt1x = degrees_to_radians(aux);
   cout << "Latitude ponto2:" << endl;
   cin >> aux;
   pt2y = degrees_to_radians(aux);
   cout << "Longitude ponto2:" << endl;
   cin >> aux;
   pt2x = degrees_to_radians(aux);

}
