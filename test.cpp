#include "evento.hpp"
#include "coleccionesInterdependientes.hpp"
#include <string>
#include <iostream>
using namespace std;



int main(){
  Evento a = crearEvento("evento", 8);
  // escribir(a);

  // cout << descripcion(a) << endl << prioridad(a) << endl;
  // cambiarDescripcion(a, "cambiio");
  // escribir(a);
  // cambiarPrioridad(a, 7);
  // escribir(a);
  string id = "st1";
  colecInterdep<string, Evento> c;
  crear(c);
  cout << tamanyo(c) << endl;
  bool ok = anadirIndependiente(c, id, a);
  cout << ok << "  "<< tamanyo(c) << endl;

  
}