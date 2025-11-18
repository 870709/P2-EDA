//*****************************************************************
// File:    main.cpp
// Authors: Anastasia Shlyk (NIP: 931807)
//          Enrique José Guaras Lacasta (NIP: 870709)
// Date:    Noviembre 2025
// Coms:    Practica 3 (EDA)
//*****************************************************************

#include "coleccionesInterdependientes.hpp"
#include "evento.hpp"
#include "coleccionesInterdependientes.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const string ID_VACIO = "-.-.-.-.-";


// Inicializa la colección y gestiona el flujo de lectura de instrucciones.
// Abre los ficheros "entrada.txt" y "salida.txt" y procesa línea a línea las instrucciones.
// Llama a las funciones anteriores según la instrucción: añadir, cambiar, borrar, listar, etc.
int main(){
  colecInterdep<string, Evento> coleccion;
  crear(coleccion);
  
  Evento aEvento = crearEvento("bsegundo", 8);
  Evento bEvento  = crearEvento("cTercero", 10);
  Evento cEvento  = crearEvento("Devento", 7);
  Evento dEvento  = crearEvento("Aevento", 22);

  string a ="a", b="b", c="c", d="d";

  anadirIndependiente(coleccion, b, bEvento);
  cout << tamanyo(coleccion);
  anadirIndependiente(coleccion, c, cEvento);
  cout << tamanyo(coleccion);
  anadirDependiente(coleccion, a, cEvento, b);
  cout << tamanyo(coleccion);
  hacerDependiente(coleccion, c, a);
  escribir(coleccion);
  hacerIndependiente(coleccion, c);
   escribir(coleccion);
}
