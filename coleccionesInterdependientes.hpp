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

template<typename T>
struct cola{
    friend void crear(cola<T>& c);
    friend void encolar(cola<T>& c, const T& e);
    friend bool esVacía?(const cola<T>& c);
    friend void primero(cola<T>& c,  T& p);
    friend void desencolar(cola<T>& c);
    friend int longitud(const cola<T>& c);
    //COMPLETAR OPERACIONES ITERADOR
    //....
    friend void iniciarIterador (cola<T>& c);
    friend bool existeSiguiente (const cola<T>& c);
    friend bool siguiente (cola<T>& c);
    friend bool avanza (cola<T>& c, T& c);
    
  private: 
     //campos
    struct Nodo {
      //ident que se usaremos para saber donde posicionar el nodo
        ident id;
      //valor del nodo
        val valor;
      //Puntero que apuntara a su 
        Nodo* sup;
      //Puntero que apunta al siguiente integrante
        Nodo* siguiente;
      //Cantidad de nodos dependientes a este
        unsigned int NumDepend;
    };
    //Puntero que apunta al primer integrante de la colección
      Nodo* primElmt;
    //Entero con la cantidad total de elementos de la colección
      unsigned int numElem;
    //Puntero que sirve como el cursor del iterador
      Nodo* iter;
};


// IMPLEMENTACION DE LAS OPERACIONES DEL TAD GENERICO agrupacion

Nodo* buscarPredecesor(const colecInterdep<ident, val>& c, const ident& id) {
    Nodo* anterior = c.lista; // Empezamos en el centinela (o la cabeza)
    // Avanzamos 'anterior' mientras el SIGUIENTE nodo exista y sea MENOR que 'id'
    while (anterior->siguiente != nullptr && anterior->siguiente->id < id) {
        anterior = anterior->siguiente;
    }
    return anterior;
}

//
template<typename ident, typename val> void crear(colecInterdep<ident, val>& c){
  //Este tampoco apuntara a nada
    c.primElmt=nullptr;
  //Definimos la variable de numero de elementos de la colección a 0
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
  // Primero de todo comprovamos que no sea vacia, para en caso de serlo salir con el minimo coste, puesto que sera seguro que no este el dato.
    if (esVacia) {return false}
  //Generamos un puntero auxiliar para recorrer el lista
    typename colecInterdep<ident, val>::Nodo* aux = buscarPredecesor(c,id);
    Nodo* anterior = c.lista; // Empezamos en el centinela (o la cabeza)

    // Avanzamos 'anterior' mientras el SIGUIENTE nodo exista y sea MENOR que 'id'
    while (anterior->siguiente != nullptr && anterior->siguiente->id < id) {
        anterior = anterior->siguiente;
    }
    
    return anterior;
};
    //Y lo dejamos apuntando al primer elemento para empezar la busqueda
    aux = c.primElmt;
  //Empezamos el bucle, lo continuaremos mientras sigan quedando datos por encontrar y no veamos un id mayor al que buscamos puesto que esta ordenada
    while (aux.sig!=nullptr && aux.id<id){
      if (id == aux.id){
        delete aux;
        return true;
      }
      aux = aux->sig;
    }
    delete aux;
    return (id == aux.id);
}
//
template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id){
  // Primero de todo comprovamos que no sea vacia, para en caso de serlo salir con el minimo coste, puesto que sera seguro que no este el dato.
    if (esVacia) {return false}
  //Generamos un puntero auxiliar para recorrer el lista
    typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
    //Y lo dejamos apuntando al primer elemento para empezar la busqueda
    aux = c.primElmt;
  //Empezamos el bucle, lo continuaremos mientras sigan quedando datos por encontrar y no veamos un id mayor al que buscamos puesto que esta ordenada
    while (aux.sig!=nullptr && aux.id<id){
      if (id == aux.id){
        if(aux.sup==nullptr){
         delete aux;
          return false;
        }else{
        delete aux;
          return true;
        }
      }
      aux = aux->sig;
    }
    if (id == aux.id){
        if(aux.sup==nullptr){
        delete aux;
          return false;
        }else{
        delete aux;
          return true;
        }
        
    } delete aux; return false;
}

//
template<typename ident, typename val> bool existeIndependiente(const colecInterdep<ident, val>& c, const ident& id){
  // Primero de todo comprovamos que no sea vacia, para en caso de serlo salir con el minimo coste, puesto que sera seguro que no este el dato.
    if (esVacia) {return false}
  //Generamos un puntero auxiliar para recorrer el lista
    typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
    //Y lo dejamos apuntando al primer elemento para empezar la busqueda
    aux = c.primElmt;
  //Empezamos el bucle, lo continuaremos mientras sigan quedando datos por encontrar y no veamos un id mayor al que buscamos puesto que esta ordenada
    while (aux.sig!=nullptr && aux.id<id){
      if (id == aux.id){
        if(aux.sup==nullptr){
          delete aux;
          return true;
        }else{
          delete aux;
          return false;
        }
      }
      aux = aux->sig;
    }
    if (id == aux.id){
        if(aux.sup==nullptr){
          delete aux;
          return true;
        }else{
          delete aux;
          return false;
        }
      
    } delete aux; return false;
}


//
template<typename ident, typename val> bool anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v){
  //si ya existe el dato fallara la escritura
      // Primero de todo comprovamos que no sea vacia, para en caso de serlo salir con el minimo coste, puesto que sera seguro que no este el dato.
    if (esVacia) {return false}
  //Generamos un puntero auxiliar para recorrer el lista
    typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
    //Y lo dejamos apuntando al primer elemento para empezar la busqueda
    aux = c.primElmt;
  //Empezamos el bucle, lo continuaremos mientras sigan quedando datos por encontrar y no veamos un id mayor al que buscamos puesto que esta ordenada
    while (aux.sig!=nullptr && aux.id<id){
      if (id == aux.id){
        if(aux.sup==nullptr){
          delete aux;
          return true;
        }else{
          delete aux;
          return false;
        }
      }
      aux = aux->sig;
    }
    if (id == aux.id){
        if(aux.sup==nullptr){
          delete aux;
          return true;
        }else{
          delete aux;
          return false;
        }
      
    } delete aux; return false;
}


    if (esVacia) {
      typename colecInterdep<ident, val>::Nodo* aux = new typename       colecInterdep<ident, val>::Nodo;
      aux.id=id;
      aux.valor=v;
      aux->sup=super;
      aux->sig = nullptr;
      c.primElmt=aux;
      return true;
    }
    typename colecInterdep<ident, val>::Nodo* aux = new typename       colecInterdep<ident, val>::Nodo;
    aux.id=id;
    aux.valor=v;
    aux->sup=super;
    aux->sig = nullptr;
    c.primElmt=aux;
}

//
template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super){
  //no puede depender de algo si la lista es vacia.
    if (esVacia) {return false;}
  //filtramos que si que exista el dato al que queremos que dependa
  if (!existe(c, super)){return false;}
    typename colecInterdep<ident, val>::Nodo* aux = new typename       colecInterdep<ident, val>::Nodo;
    aux.id=id;
    aux.valor=v;
    aux->sup=super;
    aux->sig = nullptr;
    c.primElmt=aux;
}

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

