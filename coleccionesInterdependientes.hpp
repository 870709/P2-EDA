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

//
template<typename ident, typename val> void crear(colecInterdep<ident, val>& c){
  //Creamos un el nodo centinela anteriormente explicado
   //typename colecInterdep<ident, val>::Nodo* aux = new typename  colecInterdep<ident, val>::Nodo;
    //Este no apuntara a nada puesto que todavia no hay datos
    aux->sig = nullptr;
  //Apuntamos al nodo centinela como primer elemento "ficticio"
    c.primElmt=aux;
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
    typename colecInterdep<ident, val>::Nodo* aux = new typename       colecInterdep<ident, val>::Nodo;
    //Y lo dejamos apuntando al primer elemento para empezar la busqueda
    aux = c.primElmt;
  //Nos ponemos en posicion para apuntar a los elementos y entrar en el bucle de busqueda
    aux = aux->sig;
  //Empezamos el bucle
    while (aux.sig!=nullptr && aux.id>)
    
}

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
#endif //fin de agrupacion.hpp

