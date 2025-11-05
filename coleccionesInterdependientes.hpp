/*Módulo que implementa el TAD colecciones interdependientes con memoria dinámica.
Enrique José Guarás Lacasta (870709) y Anastasia Shlyk (931807)
*/

#ifndef _EVENTOS_HPP
#define _EVENTOS_HPP
using namespace std;

/* INICIO DE LA PARTE PÚBLICA o INTERFAZ  */

/* Los valores del TAD representan colecciones de elementos formados como tuplas
de la forma (ident, val, -, NumDepend) o bien (ident, val, identSup, NumDepend). A los elementos
con forma (ident, val, -, NumDepend) los llamaremos en general ‘elementos independientes’,
mientras que a los elementos con forma (ident, val, identSup, NumDepend), los llamaremos en
general ‘elementos dependientes’. En la colección no podrá haber dos elementos con el mismo
ident.
En las tuplas que representan elementos dependientes, la información identSup será la
1identificación del elemento del que es directamente dependiente el elemento con identificación
ident. Ningún elemento de la colección podrá ser directamente dependiente de sí mismo, y todo
elemento dependiente debe serlo de otro elemento que exista en la colección (que a su vez puede
ser un elemento independiente o dependiente).
En cada elemento, la información NumDepend de su tupla representará el número total de elementos
en la colección que son directamente dependientes del elemento con identificador ident, y que
será 0 si ningún elemento de la colección depende de dicho elemento.}


   Esta implementacion cuenta con implementaciones con coste constante siendo: crear, tamanyo, esVacia, y las operaciones del iterador. 
   Por otra parte, , , , ,  y borrar tendrán coste O(N) siendo, N el número de elementos en la colección (lista ordenada),
   con una implementación que aprovecha que la coleccion está ordenada (en función de ident) para evitar 
   iteraciones innecesarias en las busquedas (finalizaran cuando se encuentre un ident posterior
   al que buscamos siempre que se pueda). 
   Ademas de asegurarnos de no recorrer toda la estructura multiples veces de forma innecesaria para las funciones de O(N).
   Igualmente, el coste en memoria de esta implementación será O(N).
   
   Por otra parte, el parámetro formal ident le exigimos estar dotado de los operadores habituales de: 
   comparación de igualdad == , y el operador habitual de anterioridad <, que 
   se utilizarán respectivamente en todas las operaciones de coste O(N) de coleccionMon.
      bool operator==(const ident& id1, const ident& id2);
      bool operator<(const ident& id1, const ident& id2);
 */

/* Operacion que crea una coleccion vacia con el primer puntero apuntando a NULL
*/
template<typename ident, typename val> struct colecInterdep;

//
template<typename ident, typename val> void crear(colecInterdep<ident, val>& c);

//
template<typename ident, typename val> unsigned int tamanyo(const colecInterdep<ident, val>& c);

/* Devuelve true si y solo si la coleccion es vacia (no cuenta con elementos), false en caso contrario
*/
template<typename ident, typename val> bool esVacia(const colecInterdep<ident, val>& c);


//
template<typename ident, typename val> bool existe(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool existeIndependiente(const colecInterdep<ident, val>& c, const ident& id);


/* Siempre y cuando no exista ya en la colección algun nodo con el mismo 'id' respecto al que vamos a introducir, 
  esta actualiza la coleccion entrante 'c' de forma que se añade un nodo en la coleccion en la posicion en la cual se 
  permita seguir respetando el orden de la estructura. 
  Siendo asi que el anterior nodo de la coleccion tenga un 'id' anterior al nuevo nodo (si existe anterior) y que el 
  siguiente nodo tenga un 'id' posterior al nodo nuevo (si existe siguiente). 
  Para sus valores se asignaran respectivamente segun la estructura definida: (ident, val, -, NumDepend).
    Siendo su 'ident' el 'id' pasado por referencia.
    Lo mismo para su 'valor' con paramentro entrantre 'v'.
    Para el 'identSup' se quedara como puntero nulo hasta nueva actualizacion al estar añadiendo un Independiente.
    Y el numero de 'numDepend' a este nodo sera 0, al haberlo añadido ahora.
  Aumentando asi en 1 el numero de elementos de la colección.
  En el caso de que ya haya un nodo con ident igual a 'id', no se actualizara la coleccion entrante 'c' y se devolvera 
  false para avisar de que no se ha añadido. Y lo mismo en caso de que no se cumplan alguna de las condiciones de paso de parametros.
*/
template<typename ident, typename val> bool anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v);

/* Siempre y cuando no exista ya en la colección algun nodo con el mismo 'id' respecto al que vamos a introducir, y ya extista
  el nodo del cual va a depender con 'id' 'super', esta actualiza la coleccion entrante 'c' de forma que se añade un nodo 
  en la coleccion en la posicion en la cual se permita seguir respetando el orden de la estructura. 
  Siendo asi que el anterior nodo de la coleccion tenga un 'id' anterior al nuevo nodo (si existe anterior) y que el 
  siguiente nodo tenga un 'id' posterior al nodo nuevo (si existe siguiente). 
  Para sus valores se asignaran respectivamente segun la estructura definida: (ident, val, identSup, NumDepend).
    Siendo su 'ident' el 'id' pasado por referencia.
    Lo mismo para su 'valor' con paramentro entrantre 'v'.
    Para el 'identSup' se quedara como puntero que apunte a nodo del cual dependerá con el 'id' 'super'.
    Y el numero de 'numDepend' a este nodo sera 0, al haberlo añadido ahora.
  Aumentando asi en 1 el numero de elementos de la colección.
  En el caso de que ya haya un nodo con ident igual a 'id' o no exista un nodo con 'id' 'super' , no se actualizara la coleccion entrante 'c' 
  y se devolvera false para avisar de que no se ha añadido. 
  Y lo mismo en caso de que no se cumplan alguna de las condiciones de paso de parametros.
*/
template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super);

/* Siempre y cuando exista ya en la colección algun nodo con el mismo 'id', y ya extista el nodo del cual va a depender 
  con 'id' 'super', esta actualiza la coleccion entrante 'c' de forma que modifica los parametros del nodo 'id', 'super' y el antiguo dependiente del nodo 'id' (en caso de tenerlo). 
  Haciendo asi que el parametro 'identSuper' del nodo 'id' apunte al nodo con 'id''super' y aumentando en este mismo su 'numDependientes' en 1.
  Y en caso de que previamente este ya apuntara a uno, decrementar su 'numDependientes' en 1. Haciendo asi que la función devuelva true.
  Y devolvera false en caso contrario.
  */
template<typename ident, typename val> bool hacerDependiente(colecInterdep<ident, val>& c, const ident& id, const ident& super);

/* Siempre y cuando exista ya en la colección algun nodo con el mismo 'id' dependiente, siendo asi que su 'identSuper'!=nullptr al apuntar ya a algun otro nodo existente
   esta actualiza la coleccion entrante 'c' de forma que modifica los parametros del nodo 'id' y el antiguo dependiente del nodo 'id'. 
  Haciendo asi que el parametro 'identSuper' del nodo 'id' no apunte a nada (nullptr) y disminuyendo en 1 su antiguo dependiente. Haciendo asi que la función devuelva true.
  Devolviendo false en caso contrario.
  */
template<typename ident, typename val> bool hacerIndependiente(colecInterdep<ident, val>& c, const ident& id);

//
template<typename ident, typename val> bool actualizarVal(colecInterdep<ident, val>& c, const ident& id, const val& nuevo);

//
template<typename ident, typename val> bool obtenerVal(const colecInterdep<ident, val>& c, const ident& id, val& val?);

//
template<typename ident, typename val> bool obtenerSupervisor(const colecInterdep<ident, val>& c, const ident& id, ident& id?);

//
template<typename ident, typename val> bool obtenerNumDependientes(const colecInterdep<ident, val>& c, const ident& id, unsigned int& NumDep?);

template<typename ident, typename val> bool obtenerInfo(const colecInterdep<ident, val>& c, const ident& id, val& valO, bool& depen, ident& idO, unsigned int& NumDepO);
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
  friend void crear<ident, val>(colecInterdep<ident, val>& c);
  friend bool esVacia<ident, val>(const colecInterdep<ident, val>& c);
  friend bool existe<ident, val>(const colecInterdep<ident, val>& c, const ident& id);
  friend unsigned int tamanyo <ident, val> (const colecInterdep<ident, val>& c);
  friend bool existeDependiente <ident, val> (const colecInterdep<ident, val>& c, const ident& id);
  friend bool existeIndependiente <ident, val> (const colecInterdep<ident, val>& c, const ident& id);
  friend bool anadirIndependiente <ident, val> (colecInterdep<ident, val>& c, const ident& id, const val& v);
  friend bool anadirDependiente <ident, val> (colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super);
  friend bool hacerDependiente <ident, val> (colecInterdep<ident, val>& c, const ident& id, const ident& super);
  friend bool hacerIndependiente <ident, val> (colecInterdep<ident, val>& c, const ident& id);
  friend bool actualizarVal <ident, val> (colecInterdep<ident, val>& c, const ident& id, const val& nuevo);
  friend bool obtenerVal <ident, val> (const colecInterdep<ident, val>& c, const ident& id, val& val?);
  friend bool obtenerSupervisor <ident, val> (const colecInterdep<ident, val>& c, const ident& id, ident& id?);
  friend bool obtenerNumDependientes <ident, val> (const colecInterdep<ident, val>& c, const ident& id, unsigned int& NumDep?);
  friend bool obtenerInfo <ident, val> (const colecInterdep<ident, val>& c, const ident& id, val& valO, bool& depen, ident& idO, unsigned int& NumDepO);
  friend bool borrar <ident, val> (colecInterdep<ident, val>& c, const ident& id);
  friend void iniciarIterador <ident, val> ( colecInterdep<ident, val>& c);
  friend bool existeSiguiente <ident, val> (const colecInterdep<ident, val>& c);
  friend ident siguienteIdent <ident, val> (const colecInterdep<ident, val>& c);
  friend val siguienteVal <ident, val> (const colecInterdep<ident, val>& c);
  friend bool siguienteDependiente <ident, val> (const colecInterdep<ident, val>& c);
  friend ident siguienteSuperior <ident, val> (const colecInterdep<ident, val>& c);
  friend unsigned int siguienteNumDependientes <ident, val> (const colecInterdep<ident, val>& c);
  friend void avanza <ident, val> (colecInterdep<ident, val>& c);

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


//++
template<typename ident, typename val> bool existe(const colecInterdep<ident, val>& c, const ident& id){
  typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux != nullptr && aux->id == id){
    return true;
  }
  return false;
}


//
template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id){
  typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux != nullptr && aux->id == id && aux->identSup != nullptr){
    return true;
  }
  return false;
}

//
template<typename ident, typename val> bool existeIndependiente(const colecInterdep<ident, val>& c, const ident& id){
  typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux != nullptr && aux->id == id && aux->identSup == nullptr){
    return true;
  }
  return false;
}


//++
template<typename ident, typename val> bool anadirIndependiente(colecInterdep<ident, val>& c, const ident& id, const val& v){
  //Si la lista esta vacia, añadiremos el nuevo elemento como primer y unico elemento en esta.
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
  //En caso de no ser vacia, buscaremos que no este y a la vez su hueco respectivo. En caso contrario fallará la adición.
    }else{
      if (c.primElmt->id == id) {
          return false;//primero repetido
      }
      //Comprovamos si fuera en la primera posición, obligatorio puesto que la busqueda posterior no lo verifica.
        else if (id < c.primElmt->id) {
          typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
            auxN->siguiente=c.primElmt;
            c.primElmt=auxN;
            auxN->id=id;
            auxN->valor=v;
            auxN->identSup=nullptr;
            auxN->numDepend=0;
            c.numElem++;
          return true;
        }
      //Realizaremos la busqueda desde el nodo anterior para no perder a su predecesor al añadirlo, puesto que este apuntara al nuevo.
        colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
        while(aux->siguiente != nullptr && aux->siguiente->id < id){
          aux = aux->siguiente;
        } 
        if(aux->siguiente != nullptr && aux->siguiente->id==id){return false;}
      //hemos encontrado el hueco, tanto si es el final de la lista como si no.
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


/* Esta implementación se basa en aplicar una busqueda en 2 turnos, basada en la subdivisión de casos posibles. Al verficar que ninguno de ambos datos que necesitamos 
este al principio, iniciar una busqueda en funcion de los ordenes de las identidades al saber que la lista esta ordenada, buscando primero al menor y posteriormente
al siguiente. Donde a la vez que buscamos que se cumpla la existencia del hueco del nodo a introducir y el dato del que dependerá, dejaremos un puntero guardando 
esta hubicación (continuando con el siguiente puntero) que permita que cuando nos aseguramos que todas las condiciones se cumplen hacer la reserva en memoria y 
asignar a este nodo un apuntado al dependiente. 
Diferenciando 2 tipos de busqueda, una desde un nodo atras para cuando verifiquemos que el nodo a introducir tenga un hueco, para dejar a su nodo anterior apuntando a este
directamente y para el padre que se trata desde el mismo nodo puesto que solo debemos verificar que existe ya en la estructura.
*/
template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super){
 //En caso de ser vacia ni empezamos, abortamos al saber que no estará el dato del que queremos depender. 
  if(esVacia(c)||(id==super)){
    return false; 
//Sabemos que no es vacia, empezaremos con la busqueda
  }else{
    //Comprovamos si fuera en la primera posición, obligatorio puesto que la busqueda posterior no lo verifica.
      if (c.primElmt->id == id) {
          return false;//Si ya esta el dato abortamos.
      }
    //1. Caso critico por realizar una busqueda con siguientes
    if (c.primElmt->id > id) {
        //En busqueda del padre
        typename colecInterdep<ident, val> ::Nodo* auxP = c.primElmt;
        while(auxP!=nullptr && auxP->id < super){
          auxP = auxP->siguiente;
        }
        if(auxP==nullptr || auxP->id!=super){return false;}
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
    //2. Debemos buscar tanto el hueco como el antecesor.
      //2.1 Buscar primero el hueco y luego al padre
        if(id<super){
        typename colecInterdep<ident, val> ::Nodo* auxH = c.primElmt;
          while(auxH->siguiente != nullptr && auxH->siguiente->id < id){
             auxH = auxH->siguiente;
          }
          if(auxH->siguiente != nullptr && auxH->siguiente->id==id){return false;}
          typename colecInterdep<ident, val> ::Nodo* auxP;
          auxP = auxH->siguiente;
          while(auxP!= nullptr && auxP->id < super){
            auxP = auxP->siguiente;
          }
          if(auxP==nullptr || auxP->id!=super){return false;}
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
      //2.2 Buscar primero al padre y luego al hijo
        }else{
            typename colecInterdep<ident, val> ::Nodo* auxP=c.primElmt;
            while(auxP!= nullptr && auxP->id < super){
              auxP = auxP->siguiente;
            }
            if(auxP==nullptr || auxP->id!=super){return false;}
            typename colecInterdep<ident, val> ::Nodo* auxH;
            auxH = auxP;
            while(auxH->siguiente != nullptr && auxH->siguiente->id < id){
              auxH = auxH->siguiente;
            }
            if(auxH->siguiente != nullptr && auxH->siguiente->id==id){return false;}
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
}
//
template<typename ident, typename val> bool hacerDependiente(colecInterdep<ident, val>& c, const ident& id, const ident& super){
    if(esVacia(c)||(id==super)){return false;}
    typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
    if(id<super){
      while(aux != nullptr && aux->id < id){
        aux = aux->siguiente;
      }
      if(aux== nullptr || aux->id!=id){return false;}
      colecInterdep<ident, val> ::Nodo* auxP=aux->siguiente;
      while(auxP!= nullptr && auxP->id < super){
        auxP = auxP->siguiente;
      }
      if(auxP==nullptr||auxP->id!=super){return false;}
      if(aux->identSup != nullptr){
        aux->identSup->numDepend--;
      }
        aux->identSup = auxP;
        auxP->numDepend++;
                return true;
    }else{
        typename colecInterdep<ident, val> ::Nodo* auxP = c.primElmt;
        while(auxP != nullptr && auxP->id < super){
          auxP = auxP->siguiente;
        }
        if(auxP== nullptr || auxP->id!=super){return false;}
        colecInterdep<ident, val> ::Nodo* aux=auxP->siguiente;
        while(aux!= nullptr && aux->id < id){
          aux = aux->siguiente;
        }
         if(aux==nullptr||aux->id!=id){return false;}
        if(aux->identSup != nullptr){
          aux->identSup->numDepend--;
        }
          aux->identSup = auxP;
          auxP->numDepend++;
        return true;
      }
}

//
template<typename ident, typename val> bool hacerIndependiente(colecInterdep<ident, val>& c, const ident& id){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux-> id == id && aux->identSup!=nullptr){
    aux->identSup->numDepend--;
    aux->identSup = nullptr;
    return true;
  }else{
    return false;
  }
}

//pre: existe!!!
template<typename ident, typename val> bool actualizarVal(colecInterdep<ident, val>& c, const ident& id, const val& nuevo){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  aux->val = nuevo;
  return true;
}

//
template<typename ident, typename val> bool obtenerVal(const colecInterdep<ident, val>& c, const ident& id, val& valO){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux == nullptr || id!=aux->id){return false;}
  valO=aux->valor;
  return true;
}

//pre: existe y es dependiente!!!!
template<typename ident, typename val> bool obtenerSupervisor(const colecInterdep<ident, val>& c, const ident& id, ident& idO){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux == nullptr || id!=aux->id || aux->identSup!=nullptr){return false;}
  idO=aux->identSup->id;
  return true;
}

//pre: existe!!!!
template<typename ident, typename val> bool obtenerNumDependientes(const colecInterdep<ident, val>& c, const ident& id, unsigned int& NumDepO){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux == nullptr || id!=aux->id){return false;}
  NumDepO=aux->numDepend;
  return true;
}

template<typename ident, typename val> bool obtenerInfo(const colecInterdep<ident, val>& c, const ident& id, val& valO, bool& depen, ident& idO, unsigned int& NumDepO){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux == nullptr || id!=aux->id){return false;}
  valO=aux->valor;
  if(aux->identSup!=nullptr){idO=aux->identSup->id;depen=true;}
   else{depen=false;}
  NumDepO=aux->numDepend;
  return true;
}

//++
template<typename ident, typename val> bool borrar(colecInterdep<ident, val>& c, const ident& id){
  if(esVacia(c)){return false;}
  if (c.primElmt->id == id) {
    if (c.primElmt->numDepend != 0) {
       return false;
    }
    if (c.primElmt->identSup != nullptr) {
      c.primElmt->identSup->numDepend--;
    }
    typename colecInterdep<ident, val> ::Nodo* controlador = c.primElmt;
    c.primElmt = c.primElmt->siguiente;
    delete controlador;
    c.numElem--;
    return true;
  }
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux->siguiente != nullptr && aux->siguiente->id < id){
    aux = aux->siguiente;
  }
  if(aux->siguiente == nullptr || aux->siguiente->id!=id || aux->siguiente->numDepend!=0){return false;}
  typename colecInterdep<ident, val> ::Nodo* controlador = aux->siguiente;
  if (controlador->identSup != nullptr) {
        controlador->identSup->numDepend--;
  }
  aux->siguiente=controlador->siguiente;
  delete(controlador);
  c.numElem--;
  return true;
}

//
template<typename ident, typename val> void iniciarIterador( colecInterdep<ident, val>& c){
  c.iter = c.primElmt;
}

//
template<typename ident, typename val> bool existeSiguiente(const colecInterdep<ident, val>& c){
  return c.iter == nullptr;
}

//OJO precondicion!!!! Parcial: la operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))}
template<typename ident, typename val> ident siguienteIdent(const colecInterdep<ident, val>& c){
  return c.iter -> id;
}

// 
template<typename ident, typename val> val siguienteVal(const colecInterdep<ident, val>& c){
  return c.iter -> valor;
}

// 
template<typename ident, typename val> bool siguienteDependiente(const colecInterdep<ident, val>& c){
  return !(c.iter -> identSup == nullptr);
}

//
template<typename ident, typename val> ident siguienteSuperior(const colecInterdep<ident, val>& c){
  return c.iter->identSup->id;
}

//
template<typename ident, typename val> unsigned int siguienteNumDependientes(const colecInterdep<ident, val>& c){
  return c.iter->numDepend;
}

//
template<typename ident, typename val> void avanza(colecInterdep<ident, val>& c){
  c.iter = c.iter->siguiente;
}
#endif //fin de agrupacion.hpp
