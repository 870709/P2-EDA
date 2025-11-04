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
  string id = "id";
  string id1 = "id1";
  string id2 = "id2";
  string id3 = "id3";

  colecInterdep<string, Evento> c;
  crear(c);
  cout << tamanyo(c) << endl;
  bool okA = anadirIndependiente(c, id, a);
  bool okB = anadirDependiente(c, id1, b, id);
  bool okC = anadirIndependiente(c, id2, e);
  bool okD = anadirDependiente(c, id3, b, id);
  escribir(c);
  
  cout << "Tamaño de coleccion "<< tamanyo(c) << endl;

  Evento aux =  obtenerVal(c, id1);
  //string sup = obtenerSupervisor(c, id1);
  cout << "identificador del evento: "<< id1 << " " <<descripcion(aux) << " su numero de dependencias: "<<obtenerNumDependientes(c, id1)<<  " id de supervisor " <<endl;


  cout << obtenerNumDependientes(c, id);

  cout << "Compruebo las funciones de existencia:"<<endl;

  cout << "Existe dependiente? " << existeDependiente(c,id1)<<endl;
    cout << "Existe dependiente? " << existeDependiente(c,id3)<<endl;
      cout << "Existe independiente? " << existeIndependiente(c,id2)<<endl;

  cout << "Hacer id2 dependiente de id " << hacerDependiente(c, id2, id)<< endl;
  escribir(c);

cout << "Existe independiente? " << existeIndependiente(c,id2)<<endl;
cout << "Existe dependiente? " << existeDependiente(c,id2)<<endl;

cout << "Hacer id2 independiente de id " << hacerIndependiente(c, id2)<< endl;
  escribir(c);
}