#include "evento.hpp"
#include "coleccionesInterdependientes.hpp"
#include <string>
#include <iostream>
using namespace std;

// void escribirColeccion(colecInterdep<string, Evento>& c){
//   for(int i = 0; i < c.numElem; i++){
//     cout << 
//   }
// }



int main(){
  Evento a = crearEvento("Aevento", 8);
  Evento b  = crearEvento("Bevento", 10);
  Evento d  = crearEvento("Devento", 7);
  Evento e  = crearEvento("Cevento", 22);
  // escribir(a);

  // cout << descripcion(a) << endl << prioridad(a) << endl;
  // cambiarDescripcion(a, "cambiio");
  // escribir(a);
  // cambiarPrioridad(a, 7);
  // escribir(a);
  string id = "st1";
  string id1 = "st2";
  string id2 = "st3";
  string id3 = "st4";

  colecInterdep<string, Evento> c;
  crear(c);
  cout << tamanyo(c) << endl;
  bool okA = anadirIndependiente(c, id, a);
  bool okB = anadirDependiente(c, id1, b, id);
  bool okC = anadirIndependiente(c, id2, e);
  bool okD = anadirIndependiente(c, id3, d);
  cout << okA << " " <<okB << " "<< okC << " "  << okD << " " << endl;
  cout << "Tamaño de coleccion "<< tamanyo(c) << endl;

  Evento aux =  obtenerVal(c, id1);
  cout << "identificador del evento: "<< id1 << " " <<descripcion(aux) << " su numero de dependencias: "<<obtenerNumDependientes(c, id1)<<  endl;
  cout << obtenerNumDependientes(c, id);
}