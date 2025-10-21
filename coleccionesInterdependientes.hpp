/* Nombre, apellidos y NIP del (de los) autor(es).
*/

#ifndef EVENTOS_HPP
#define EVENTOS_HPP

#include "colecInterdep.hpp"

//
template<typename ident, typename val> struct colecInterdep;

//
template<typename ident, typename val> void crear(colecInterdep<ident, val>& c);

//
template<typename ident, typename val> unsigned int tamanyo(const colecInterdep<ident, val>& c);

//
template<typename ident, typename val> bool esVacia(const colecInterdep<ident, val>& c);


//
template<typename ident, typename val> bool existe(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool existeIndependiente(const colecInterdep<ident, val>& c, const ident& id);


//
template<typename ident, typename val> bool anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v);

//
template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super);

//
template<typename ident, typename val> bool hacerDependiente(colecInterdep<ident, val>& c, const ident& id, const ident& super);

//
template<typename ident, typename val> bool hacerIndependiente(colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool actualizarVal(colecInterdep<ident, val>& c, const ident& id, const val& nuevo);

//
template<typename ident, typename val> val obtenerVal(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> ident obtenerSupervisor(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> unsigned int obtenerNumDependientes(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool borrar(colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> void iniciarIterador( colecInterdep<ident, val>& c);

//
template<typename ident, typename val> bool existeSiguiente(const colecInterdep<ident, val>& c);

// 
template<typename ident, typename val> ident siguienteIdent(const colecInterdep<ident, val>& c);

// 
template<typename ident, typename val> val siguienteVal(const colecInterdep<ident, val>& c);

// 
template<typename ident, typename val> bool siguienteDependiente(const colecInterdep<ident, val>& c);

//
template<typename ident, typename val> ident siguienteSuperior(const colecInterdep<ident, val>& c);

//
template<typename ident, typename val> unsigned int siguienteNumDependientes(const colecInterdep<ident, val>& c);

//
template<typename ident, typename val> void avanza(colecInterdep<ident, val>& c);
// FIN predeclaracion del TAD GENERICO colecInterdep (Fin INTERFAZ)

// DECLARACION DEL TAD GENERICO colecInterdep

template<typename ident, typename val>
struct colecInterdep{
  friend template<typename ident, typename val> void crear(colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> bool esVacia(const colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> bool existe(const colecInterdep<ident, val>& c, const ident& id);
  friend template<typename ident, typename val> unsigned int tamanyo(const colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id);
  friend template<typename ident, typename val> bool existeIndependiente(const colecInterdep<ident, val>& c, const ident& id);
  friend template<typename ident, typename val> bool anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v);
  friend template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super);
  friend template<typename ident, typename val> bool hacerDependiente(colecInterdep<ident, val>& c, const ident& id, const ident& super);
  friend template<typename ident, typename val> bool hacerIndependiente(colecInterdep<ident, val>& c, const ident& id);
  friend template<typename ident, typename val> bool actualizarVal(colecInterdep<ident, val>& c, const ident& id, const val& nuevo);
  friend template<typename ident, typename val> val obtenerVal(const colecInterdep<ident, val>& c, const ident& id);
  friend template<typename ident, typename val> ident obtenerSupervisor(const colecInterdep<ident, val>& c, const ident& id);
  friend template<typename ident, typename val> unsigned int obtenerNumDependientes(const colecInterdep<ident, val>& c, const ident& id);
  friend template<typename ident, typename val> bool borrar(colecInterdep<ident, val>& c, const ident& id);
  friend template<typename ident, typename val> void iniciarIterador( colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> bool existeSiguiente(const colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> ident siguienteIdent(const colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> val siguienteVal(const colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> bool siguienteDependiente(const colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> ident siguienteSuperior(const colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> unsigned int siguienteNumDependientes(const colecInterdep<ident, val>& c);
  friend template<typename ident, typename val> void avanza(colecInterdep<ident, val>& c);

  private: 
    struct Nodo {
        ident id;
        val valor;
        ident identSup;
        unsigned int numDepend = 0;
        Nodo* siguiente;
      
    };
      Nodo* primElmt;
      unsigned int numElem;
      Nodo* iter;
};


// IMPLEMENTACION DE LAS OPERACIONES DEL TAD GENERICO agrupacion

//
template<typename ident, typename val> void crear(colecInterdep<ident, val>& c){
    c.primElmt = nullptr;
    c.numElem=0;
}

//
template<typename ident, typename val> unsigned int tamanyo(const colecInterdep<ident, val>& c){
  //Devolvemos la variable asignada que denife el tamaño
    return c.numElem;
}

//
template<typename ident, typename val> bool esVacia(const colecInterdep<ident, val>& c){
  //En función al numero de elementos sabremos si esta vacia.
    return (c.numElem==0);
}


//(Divide y venceras en lista ordenada no se debe de poder, pararemos cuando el id actual sea mayor al que estamos buscando o si ya no quedan elementos que explorar. Intentar jugar con como recorrer el orden de la lista o busquedas bidireccionales para reducir coste en tiempo no tiene sentido al no ser ni doble enlazada.)
template<typename ident, typename val> bool existe(const colecInterdep<ident, val>& c, const ident& id){
  if(esVacia(c)){
    return false;
  }else{
    colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
    while(aux != nullptr && aux->id <= id){
      if(aux->id == id){
        return true;
      }
      aux = aux->siguiente;
    }
    return false;
  }
}

//
template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id){
  if(esVacia(c)){
    return false;
  }else{
    colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
    while(aux != nullptr && aux->id <= id){
      if(aux->id == id && existe(c, aux->identSup)){
        return true;
      }
      aux = aux->siguiente;
    }
    return false;
  }
}

//
template<typename ident, typename val> bool existeIndependiente(const colecInterdep<ident, val>& c, const ident& id);


//
template<typename ident, typename val> void anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v){
  if(existe(c, id)){
    return false; // ya existe, no lo hemos añadido, habrá que modificar el valor
  } else{
    c.primElmt = new typename colecInterdep<ident, val>::Nodo;
    primElmt
  }
}

//
template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super);

//
template<typename ident, typename val> bool hacerDependiente(colecInterdep<ident, val>& c, const ident& id, const ident& super);

//
template<typename ident, typename val> bool hacerIndependiente(colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool actualizarVal(colecInterdep<ident, val>& c, const ident& id, const val& nuevo);

//
template<typename ident, typename val> val obtenerVal(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> ident obtenerSupervisor(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> unsigned int obtenerNumDependientes(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool borrar(colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> void iniciarIterador( colecInterdep<ident, val>& c);

//
template<typename ident, typename val> bool existeSiguiente(const colecInterdep<ident, val>& c);

// 
template<typename ident, typename val> ident siguienteIdent(const colecInterdep<ident, val>& c);

// 
template<typename ident, typename val> val siguienteVal(const colecInterdep<ident, val>& c);

// 
template<typename ident, typename val> bool siguienteDependiente(const colecInterdep<ident, val>& c);

//
template<typename ident, typename val> ident siguienteSuperior(const colecInterdep<ident, val>& c);

//
template<typename ident, typename val> unsigned int siguienteNumDependientes(const colecInterdep<ident, val>& c);

//
template<typename ident, typename val> void avanza(colecInterdep<ident, val>& c);
#endif //fin de agrupacion.hpp

