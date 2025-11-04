#include "coleccionesInterdependientes.hpp"
#include "evento.hpp"
#include "coleccionesInterdependientes.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const string ID_VACIO = "-.-.-.-.-";

bool anadirNuevoEvento(ifstream &f,ofstream &g, colecInterdep<string, Evento>& coleccion ){
  string id, desc, dep, idSup, salto;
  int prioridad=0;
  getline(f, id);
  getline(f, desc);
  f >> prioridad;
  getline(f, salto);
  getline(f, dep);
  getline(f, idSup);
  Evento evento = crearEvento(desc, prioridad);
  if(dep == "INDependiente"){
    if(anadirIndependiente(coleccion, id, evento)){
      g << "INTRODUCIDO: " << "[ "<< id <<" ] --- "<< desc << " --- ( "<<prioridad<<" )" << endl;
      return true;
    }else{
      g << "NO INTRODUCIDO: " << "[ "<< id <<" ] --- "<< desc << " --- ( "<<prioridad<<" )" << endl;
      return false;
    }
  } else {
    if(anadirDependiente(coleccion, id, evento, idSup)){
      g << "INTRODUCIDO: " << "[ "<< id <<" -de-> "<< idSup <<" ] --- "<< desc << " --- ( "<<prioridad<<" )" << endl;
      return true;
    } else {
      g << "INTRODUCIDO: " << "[ "<< id <<" -de-> "<< idSup <<" ] --- "<< desc << " --- ( "<<prioridad<<" )" << endl;
      return false;
    }
  }
}

bool cambiarInfo(ifstream &f,ofstream &g, colecInterdep<string, Evento>& coleccion){
  string nombre, descrip, salto;
  int prioridad = 0;
  getline(f, nombre);
  getline(f, descrip);
  f >> prioridad;
  getline(f, salto);
  Evento evento = crearEvento(descrip, prioridad);
  if(existeDependiente(coleccion, nombre)){
    
  }
  if(actualizarVal(coleccion, nombre, evento)){
    g << "Cambiado: " << "[ "<< id <<" -de-> "<< idSup <<" ] --- "<< desc << " --- ( "<<prioridad<<" )" << endl;
    return true;
  }else{

    return false;
  }
}

int main(){
  colecInterdep<string, Evento> coleccion;
  crear(coleccion);


  ifstream f;
  ofstream g;
  f.open("entrada.txt");
  g.open("salida.txt");
  string instruccion;
  string salto;
  if(f.is_open()){
    if(g.is_open()){
      while (f >> instruccion) {
        getline(f,salto);
        if (instruccion == "A"){
          anadirNuevoEvento(f, g, coleccion);
        }else if (instruccion == "C"){
          cambiarInfo(f,g,coleccion);
        }else if (instruccion == "D"){
          
        }else if (instruccion == "O"){
          
        }else if (instruccion == "E"){
          
        }else if (instruccion == "I"){
          
        }else if (instruccion == "B"){
          
        }else if (instruccion == "LD"){
          
        }else if (instruccion == "LT"){
          
        }
      } 
    }else{
      cout << "Error al crear el fichero de salida."<<endl;
    }
  }else{
    cout << "Error al abrir fichero de entrada."<< endl;
  }
  
}