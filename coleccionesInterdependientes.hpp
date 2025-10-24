/* Nombre, apellidos y NIP del (de los) autor(es).
*/

#ifndef _EVENTOS_HPP
#define _EVENTOS_HPP
using namespace std;

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
  friend void crear(colecInterdep<ident, val>& c);
  friend bool esVacia(const colecInterdep<ident, val>& c);
  friend bool existe(const colecInterdep<ident, val>& c, const ident& id);
  friend unsigned int tamanyo(const colecInterdep<ident, val>& c);
  friend bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id);
  friend bool existeIndependiente(const colecInterdep<ident, val>& c, const ident& id);
  friend bool anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v);
  friend bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super);
  friend bool hacerDependiente(colecInterdep<ident, val>& c, const ident& id, const ident& super);
  friend bool hacerIndependiente(colecInterdep<ident, val>& c, const ident& id);
  friend bool actualizarVal(colecInterdep<ident, val>& c, const ident& id, const val& nuevo);
  friend val obtenerVal(const colecInterdep<ident, val>& c, const ident& id);
  friend ident obtenerSupervisor(const colecInterdep<ident, val>& c, const ident& id);
  friend unsigned int obtenerNumDependientes(const colecInterdep<ident, val>& c, const ident& id);
  friend bool borrar(colecInterdep<ident, val>& c, const ident& id);
  friend void iniciarIterador( colecInterdep<ident, val>& c);
  friend bool existeSiguiente(const colecInterdep<ident, val>& c);
  friend ident siguienteIdent(const colecInterdep<ident, val>& c);
  friend val siguienteVal(const colecInterdep<ident, val>& c);
  friend bool siguienteDependiente(const colecInterdep<ident, val>& c);
  friend ident siguienteSuperior(const colecInterdep<ident, val>& c);
  friend unsigned int siguienteNumDependientes(const colecInterdep<ident, val>& c);
  friend void avanza(colecInterdep<ident, val>& c);

  private: 
    struct Nodo {
        ident id;
        val valor;
        ident identSup ;
        unsigned int numDepend = 0;
        Nodo* siguiente;
      
    };
      Nodo* primElmt;
      unsigned int numElem;
      Nodo* iter;
};


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
    typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
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
    typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
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
template<typename ident, typename val> bool anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v){
  if(esVacia(c)){
    typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
        auxN->id=id;
        auxN->valor=v;
        auxN->identSup=nullptr;
        auxN->numDepend = 0;
        auxN->siguiente=nullptr;
    c.primElmt = auxN;
    c.numElem=1;
    return true;
    }else{
    if (c.primElmt->id == id) {
        return false;//primero repetido
    }
    //Comprovamos si fuera en la primera posición
    else if (c.primElmt->id < id) {
        typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
        auxN->siguiente=c.primElmt;
        c.primElmt=auxN;
        auxN->id=id;
        auxN->valor=v;
        auxN->identSup=nullptr;
        auxN->numDepend=0;
        c.numElem++;
        return true;//primero repetido
    }
    //ya podemos empezar la busqueda real
    typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
    //vamos a jugar desde el nodo anterior para poder meterlo justo despues
    while(aux->siguiente != nullptr && aux->siguiente->id > id){
      aux = aux->siguiente;
    } 
      if(aux->siguiente != nullptr){//ya existe no podemos añadirlo
        if( aux->siguiente->id==id){return false;}
          
        }
     //hemos encontrado el hueco tanto si es final como si no
      typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
        auxN->siguiente=aux->siguiente;
        aux->siguiente=auxN;
        auxN->id=id;
        auxN->valor=v;
        auxN->identSup=nullptr;
        auxN->numDepend=0;
        c.numElem++;
        return true;
    }
}

//
template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super){
  if(id != super){
    if(!existe(c, id)){
      if(existe(c, super)){
        typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
        while(aux != nullptr && aux->ident != super){
          aux = aux->siguiente;
        }
        aux->numDepend += 1;
        typename colecInterdep<ident, val> ::Nodo* nuevo = new typename colecInterdep<ident, val>::Nodo;
        nuevo->id = id;
        nuevo->val = v;
        nuevo->identSup = aux;
        nuevo->numDepend = 0;
        nuevo->siguiente = nullptr;

        //id del nuevo es menor que el del primer nodo
        if(id < c.primElmt->id){
          nuevo->siguiente = c.primElmt;
          c.primElmt = nuevo;
          c.numElem += 1;
          return true;
        } else {
          aux = c.primElmt;
          while(aux->siguiente != nullptr && aux->siguiente->id < id){
            aux = aux->siguiente;
          }
          typename colecInterdep<ident, val> ::Nodo* temp = aux->siguiente;
          aux->siguiente = nuevo;
          nuevo->siguiente = temp;
          c.numElem += 1;
          return true;
        }
      }
    }
  }
  return false;
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

