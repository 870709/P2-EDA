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
        Nodo* identSup;
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
    while(aux != nullptr && aux->id >= id){
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
    while(aux != nullptr && aux->id >= id){
      if(aux->id == id){
        if (aux->identSup == nullptr){
          return false;
        }else{
          return true;
        }
      }
      aux = aux->siguiente;
    }
    return false;
  }
}

//
template<typename ident, typename val> bool existeIndependiente(const colecInterdep<ident, val>& c, const ident& id){
  if(esVacia(c)){
    return false;
  }else{
    colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
    while(aux != nullptr && aux->id >= id){
      if(aux->id == id){
        if (aux->identSup == nullptr){
          return true;
        }else{
          return false;
        }
      }
      aux = aux->siguiente;
    }
    return false;
  }
}


//
template<typename ident, typename val> bool anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v){
  //Si es vacia la implementaremos como primer elemento.
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
    colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
    //vamos a jugar desde el nodo anterior para poder meterlo justo despues
    while(aux->siguiente != nullptr && aux->siguiente->id > id){
      aux = aux->siguiente;
    } 
      if(auxP->siguiente == nullptr && auxP->siguiente->id==id){return false;}
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


//fadsfdsafdsafdsafdsafd
template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super){
  //no hay padre
  if(esVacia(c)||(id==super)){
    return false; 
  }else{
    //optimizar generación de punteros. Los meto aqui por conveniencia
      //colecInterdep<ident, val> ::Nodo* auxP = c.primElmt;
      //colecInterdep<ident, val> ::Nodo* auxH = c.primElmt;
    if (c.primElmt->id == id) {
        return false;//primero repetido
    }
    //Encontramos al padre
    else if (c.primElmt->id == super) {
      if(id<super){//sabremos que va primero, coste minimo. Padre e hueco encontrado, nos ahorramos el puntero
        typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
        auxN->id=id;
        auxN->valor=v;
        auxN->identSup=c.primElmt;
        c.primElmt->numDepend++;
        auxN->numDepend = 0;
        auxN->siguiente=c.primElmt;
        c.primElmt = auxN;
        c.numElem++;
        return true;
      }
      //empieza la busqueda del hueco real
      colecInterdep<ident, val> ::Nodo* auxH = c.primElmt;
      while(auxH->siguiente != nullptr && auxH->siguiente->id > id){
        auxH = auxH->siguiente;
      }
      if(auxH->siguiente == nullptr && auxH->siguiente->id==id){return false;}
      //hemos encontrado el hueco tanto si es final como si no
      typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
      auxN->siguiente=auxH->siguiente;
      auxH->siguiente=auxH;
      auxH->id=id;
      auxH->valor=v;
      auxH->identSup=c.primElmt;
      auxH->numDepend=0;
      c.numElem++;
      c.primElmt->numDepend++;//???????
      return true;
    }
    //Hemos encontrado el hueco pero NO el padre en la primera pos
    if (c.primElmt->id < id) {
        //En busqueda del padre
        colecInterdep<ident, val> ::Nodo* auxP = c.primElmt->siguiente;//el primero ya lo hemos mirado y buscamos en presente
        while(auxP!=nullptr && auxP->id > id){
          auxP = auxP->siguiente;
        }
        if(auxP==nullptr){//hemos llegado al final 
          return false;
        }
        if(auxP->id!=super){//no esta
          return false;
        }
        //encontrado
        typename colecInterdep<ident, val>::Nodo* auxH = new typename colecInterdep<ident, val>::Nodo;
        auxH->id=id;
        auxH->valor=v;
        auxH->identSup=auxP;
        auxH->numDepend = 0;
        auxH->siguiente=c.primElmt;
        c.primElmt = auxH;
        c.numElem++;
        auxP->numDepend++;
        return true;
    }
    bool padre= false;//padre encontrado
    //ya podemos empezar la busqueda real
    //vamos a jugar desde el nodo anterior para poder meterlo justo despues. Caso nada encontrado, mas generico
    colecInterdep<ident, val> ::Nodo* auxH = c.primElmt;
      while(auxH->siguiente != nullptr && auxH->siguiente->id > id){
        if((auxH->siguiente->id==id)||(auxH->siguiente->id<super&&padre==false)){//si esta el nodo o nos hemos pasado al padre
          return false;//abort
        }
        if(auxH->siguiente->id==super){//padre>hueco
          colecInterdep<ident, val> ::Nodo* auxP = c.primElmt;
          auxP = auxH;//segumos con la busqueda del hijo
          padre=true;
        }
         auxH = auxH->siguiente;
      }
      
      if(auxH->siguiente == nullptr && auxH->siguiente->id==id){return false;}
      //hemos encontrado el hueco tanto si es final como si no
      if (padre==true){
        typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
        auxN->siguiente=auxH->siguiente;
        auxH->siguiente=auxN;
        auxN->id=id;
        auxN->valor=v;
        auxN->identSup=auxP;
        auxP->numDepend++;
        auxN->numDepend=0;
        c.numElem++;
        return true;
      }
      colecInterdep<ident, val> ::Nodo* auxP;
      auxP = auxH->siguiente;//queda encontrar al padre
      while(auxP!= nullptr && auxP->id > id){
        aux = aux->siguiente;
      }
      if(auxP== nullptr && auxP->id!=super){return false;}
      typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
        auxN->siguiente=auxH->siguiente;
        auxH->siguiente=auxN;
        auxN->id=id;
        auxN->valor=v;
        auxN->identSup=auxP;
        auxP->numDepend++;
        auxN->numDepend=0;
        c.numElem++;
        return true;
  }
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
