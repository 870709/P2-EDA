/* Nombre, apellidos y NIP del (de los) autor(es).
*/
#include <iostream>

#ifndef _EVENTOS_HPP
#define _EVENTOS_HPP
using namespace std;



//
template<typename ident, typename val> struct colecInterdep;

template<typename ident, typename val> void escribir(colecInterdep<ident, val>& c);


template<typename ident, typename val> bool obtenerInfo(const colecInterdep<ident, val>& c, const ident& id, val& valO, bool& depen, ident& idO, unsigned int& NumDepO);
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
template<typename ident, typename val> bool iniciarIterador( colecInterdep<ident, val>& c);

//
template<typename ident, typename val> bool existeSiguiente(const colecInterdep<ident, val>& c);

// 
template<typename ident, typename val> bool siguienteIdent(const colecInterdep<ident, val>& c, ident &sig);

// 
template<typename ident, typename val> bool siguienteVal(const colecInterdep<ident, val>& c, val& sig);

// 
template<typename ident, typename val> bool siguienteDependiente(const colecInterdep<ident, val>& c);

//
template<typename ident, typename val> bool siguienteSuperior(const colecInterdep<ident, val>& c, ident &sig);

//
template<typename ident, typename val> bool siguienteNumDependientes(const colecInterdep<ident, val>& c, int &num);

//
template<typename ident, typename val> bool avanza(colecInterdep<ident, val>& c);
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
  friend val obtenerVal <ident, val> (const colecInterdep<ident, val>& c, const ident& id);
  
  friend ident obtenerSupervisor <ident, val> (const colecInterdep<ident, val>& c, const ident& id);
  friend unsigned int obtenerNumDependientes <ident, val> (const colecInterdep<ident, val>& c, const ident& id);
  friend bool borrar <ident, val> (colecInterdep<ident, val>& c, const ident& id);
  friend bool iniciarIterador <ident, val> ( colecInterdep<ident, val>& c);
  friend bool existeSiguiente <ident, val> (const colecInterdep<ident, val>& c);
  friend bool siguienteIdent <ident, val> (const colecInterdep<ident, val>& c, ident &sig);
  friend bool siguienteVal <ident, val> (const colecInterdep<ident, val>& c, val& sig);
  friend bool siguienteDependiente <ident, val> (const colecInterdep<ident, val>& c);
  friend bool siguienteSuperior <ident, val> (const colecInterdep<ident, val>& c, ident &sig);
  friend bool siguienteNumDependientes <ident, val> (const colecInterdep<ident, val>& c, int &num);
  friend bool avanza <ident, val> (colecInterdep<ident, val>& c);

  friend void escribir<ident, val>(colecInterdep<ident, val>& c);
  friend bool obtenerInfo <ident, val> (const colecInterdep<ident, val>& c, const ident& id, val& valO, bool& depen, ident& idO, unsigned int& NumDepO);

  private: 
    struct Nodo {
        ident id;
        val valor;
        Nodo* identSup = nullptr;
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
template<typename ident, typename val> void escribir(colecInterdep<ident, val>& c){
  typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
  for(int i = 0; i< c.numElem; i++){
    cout << aux->id << " "<< aux->numDepend<<endl;
    aux = aux->siguiente; 
  }
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
// template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id){
//   if(esVacia(c)){
//     return false;
//   }else{
//     typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
//     while(aux != nullptr && aux->id <= id){
//       if(aux->id == id && existe(c, aux->identSup)){
//         return true;
//       }
//       aux = aux->siguiente;
//     }
//     return false;
//   }
// }


// template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id){
//   if(esVacia(c)){
//     return false;
//   }else{
//     typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
//     while(aux != nullptr && aux->id <= id){
//       if(aux->id == id){
//         if (aux->identSup == nullptr){
//           return false;
//         }else{
//           return true;
//         }
//       }
//       aux = aux->siguiente;
//     }
//     return false;
//   }
// }




template<typename ident, typename val> bool existeDependiente(const colecInterdep<ident, val>& c, const ident& id){
  typename colecInterdep<ident, val>::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  if(aux != nullptr && aux->id == id && aux->identSup != nullptr){
    cout << aux->id << endl;
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
    cout << "Creado el primero elemento"<< endl;
    }else{
    if (c.primElmt->id == id) {
        return false;//primero repetido
    }
    //Comprobamos si fuera en la primera posición
    else if (c.primElmt->id > id) {
      cout << "Tenemos que meterlo al principio de la coleccion"<< endl;
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
    while(aux->siguiente != nullptr && aux->siguiente->id < id){
      aux = aux->siguiente;
    } 
      if(aux->siguiente != nullptr && aux->siguiente->id==id){//ya existe no podemos añadirlo
          return false;
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
    //1. En caso de si ser el padre el primer elemento solo faltará encontrar el hueco del dato a introducir, siempre y cuando este no exista ya.
      else if (c.primElmt->id == super) {
        //Caso de que el elemento nuevo vaya como primer elemento de lista
          if(id<super){
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
      //Si no se cumple la anterior verificacion empezamos la busqueda del hueco unicamente.
      typename colecInterdep<ident, val> ::Nodo* auxH = c.primElmt; //No es necesario volver a verificar el primer elemento.
      while(auxH->siguiente != nullptr && auxH->siguiente->id < id){
        auxH = auxH->siguiente;
      }
      if(auxH->siguiente != nullptr && auxH->siguiente->id==id){return false;}
      //Hemos encontrado el hueco y el padre es el primer elemento.
        typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
          auxN->siguiente=auxH->siguiente;
          auxH->siguiente=auxN;
          auxN->id=id;
          auxN->valor=v;
          auxN->identSup=c.primElmt;
          auxN->numDepend=0;
          c.numElem++;
          c.primElmt->numDepend++;
        return true;
    }
    //2. Hemos encontrado el hueco pero no al padre
    if (c.primElmt->id > id) {
        //En busqueda del padre
        typename colecInterdep<ident, val> ::Nodo* auxP = c.primElmt->siguiente;//ya sabemos que el primero no es
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
    //3. Debemos buscar tanto el hueco como el antecesor.
      //3.1 Buscar primero el hueco y luego al padre
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
      //3.2 Buscar primero al padre y luego al hijo
        }else{
            typename colecInterdep<ident, val> ::Nodo* auxP=c.primElmt->siguiente;
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




// template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super){
//   if(id != super){
//     typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt, *sup = nullptr, *hueco = nullptr;
//     ident max; 
//     if(id > super){
//       max = id;
//       cout << "recoremos hasta id"<< endl;
//     }else{
//       max = super;
//       cout << "recoremos hasta super"<< endl;
//     }
//      // en un recorrido de la colección confirmamos que no existe el nodo con ident id, guardamos el puntero al nodo con ident super. Recorremos solo 
//     while(aux != nullptr && aux->id <= max){
//       //confirmamos que no exista el nodo id 
//       if(aux->id == id){
//         return false;
//       }else if(aux->id == super){
//         sup = aux;
//         cout << "encontrado el sup su id es "<< sup->id << endl;

//       }
//       aux = aux->siguiente;
//     }
//     if(sup != nullptr){
//       cout << "antes de aumentar el num de dependencias del sup" << sup->numDepend<< endl;
//       sup->numDepend++;
//       cout << "aumentado el num de dependencias del sup" << sup->numDepend<< endl;

//       typename colecInterdep<ident, val> ::Nodo* nuevo = new typename colecInterdep<ident, val>::Nodo;
//       nuevo->id = id;
//       nuevo->valor = v;
//       nuevo->identSup = sup;
//       nuevo->numDepend = 0;
//       nuevo->siguiente = nullptr;

//       //id del nuevo es menor que el del primer nodo
//       if(id < c.primElmt->id){
//         nuevo->siguiente = c.primElmt;
//         c.primElmt = nuevo;
//         c.numElem += 1;
//         return true;
//       } else {
//         aux = c.primElmt;
//         while(aux->siguiente != nullptr && aux->siguiente->id < id){
//           aux = aux->siguiente;
//         }
//         typename colecInterdep<ident, val> ::Nodo* temp = aux->siguiente;
//         aux->siguiente = nuevo;
//         nuevo->siguiente = temp;
//         c.numElem += 1;
//         return true;
//       }
//     }else{
//       return false;
//     }
//   }
//   return false;
// }


// template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super){
//   if(id!=super){
//     typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt, sup = nullptr, hueco = nullptr;
//     if(c.primElmt -> id == id){
//       return false;
//     }else {
//       // if(c.primElmt->id == super){
//       // sup = c.primElmt;
//       while(aux->siguiente != nullptr && aux->id >= min(id, super)){
//         if(aux->id > id && aux->siguiente->id < id){
//           hueco = aux;
//         }
//         if(aux->id == super){
//           sup = aux;
//         }
//         aux = aux->siguiente;
//       } 
//     }
//   }
// }

template<typename ident, typename val> bool hacerDependiente(colecInterdep<ident, val>& c, const ident& id, const ident& super){
    if(esVacia(c)||(id==super)){return false;}
    typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
    if(id<super){
      while(aux != nullptr && aux->id < id){
        aux = aux->siguiente;
      }
      if(aux== nullptr || aux->id!=id){return false;}

      typename colecInterdep<ident, val> ::Nodo* auxP = nullptr;
      auxP=aux->siguiente;
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
        typename colecInterdep<ident, val> ::Nodo* aux=auxP->siguiente;
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
// template<typename ident, typename val> bool hacerDependiente(colecInterdep<ident, val>& c, const ident& id, const ident& super){
//   if (id != super){
//     typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt, sup = nullptr, elem = nullptr;
//     while(aux != nullptr && aux->id <= max(sup, id)){
//       if(aux->id == id){
//         elem = aux;
//       }
//       if(aux->id == super){
//         sup = aux;
//       }
//       aux = aux->siguiente;
//     }
//     if(sup != nullptr && elem != nullptr){
//       if(elem->identSup != nullptr){
//         elem->identSup->numDepend--;
//       }
//       elem->identSup = sup;
//       sup->numDepend++;
//     }else{
//       return false;
//     }

//   }else return false;
// }
//version Enrique 
// template<typename ident, typename val> bool anadirDependiente(colecInterdep<ident, val>& c, const ident& id, const val& v, const ident& super){
//   //no hay padre
//   if(esVacia(c)||(id==super)){
//     return false; 
//   }else{
//     if (c.primElmt->id == id) {
//         return false;
//     }
//     //Encontramos al padre
//     else if (c.primElmt->id == super) {
//       if(id<super){//acceso inmediato
//         typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
//         auxN->id=id;
//         auxN->valor=v;
//         auxN->identSup=c.primElmt;
//         c.primElmt->numDepend++;
//         auxN->numDepend = 0;
//         auxN->siguiente=c.primElmt;
//         c.primElmt = auxN;
//         c.numElem++;
//         return true;
//       }
//       //hueco
//       colecInterdep<ident, val>::Nodo* auxH = c.primElmt;
//       while(auxH->siguiente != nullptr && auxH->siguiente->id > id){
//         auxH = auxH->siguiente;
//       }
//       if(auxH->siguiente == nullptr && auxH->siguiente->id==id){return false;}
//       typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
//       auxN->siguiente=auxH->siguiente;
//       auxH->siguiente=auxH;
//       auxH->id=id;
//       auxH->valor=v;
//       auxH->identSup=c.primElmt;
//       auxH->numDepend=0;
//       c.numElem++;
//       c.primElmt->numDepend++;//???????
//       return true;
//     }
//     //hueco pero NO el padre 
//     if (c.primElmt->id < id) {
//         //En busqueda del padre
//         colecInterdep<ident, val> ::Nodo* auxP = c.primElmt->siguiente;
//         while(auxP!=nullptr && auxP->id > id){
//           auxP = auxP->siguiente;
//         }
//         if(auxP==nullptr){//hemos llegado al final 
//           return false;
//         }
//         if(auxP->id!=super){//no esta
//           return false;
//         }
//         //encontrado
//         typename colecInterdep<ident, val>::Nodo* auxH = new typename colecInterdep<ident, val>::Nodo;
//         auxH->id=id;
//         auxH->valor=v;
//         auxH->identSup=auxP;
//         auxH->numDepend = 0;
//         auxH->siguiente=c.primElmt;
//         c.primElmt = auxH;
//         c.numElem++;
//         auxP->numDepend++;
//         return true;
//     }
//     if(id>super){
//     colecInterdep<ident, val> ::Nodo* auxH = c.primElmt;
//       while(auxH->siguiente != nullptr && auxH->siguiente->id > id){
//         if((auxH->siguiente->id==id))){//(auxH->siguiente->id<super&&padre==false
//           return false;//abort
//         }
//         /*if(auxH->siguiente->id==super){//padre>hueco
//           colecInterdep<ident, val> ::Nodo* auxP = c.primElmt;
//           auxP = auxH;//segumos con la busqueda del hijo
//           padre=true;
//         }*/
//          auxH = auxH->siguiente;
//       }
      
//       if(auxH->siguiente == nullptr && auxH->siguiente->id==id){return false;}
//       //hemos encontrado el hueco tanto si es final como si no
//       /*if (padre==true){
//         typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
//         auxN->siguiente=auxH->siguiente;
//         auxH->siguiente=auxN;
//         auxN->id=id;
//         auxN->valor=v;
//         auxN->identSup=auxP;
//         auxP->numDepend++;
//         auxN->numDepend=0;
//         c.numElem++;
//         return true;
//       }*/
//       colecInterdep<ident, val> ::Nodo* auxP;
//       auxP = auxH->siguiente;
//       while(auxP!= nullptr && auxP->id > super){
//         aux = aux->siguiente;
//       }
//       if(auxP== nullptr && auxP->id!=super){return false;}
//       typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
//         auxN->siguiente=auxH->siguiente;
//         auxH->siguiente=auxN;
//         auxN->id=id;
//         auxN->valor=v;
//         auxN->identSup=auxP;
//         auxP->numDepend++;
//         auxN->numDepend=0;
//         c.numElem++;
//         return true;
//   }else{
//       colecInterdep<ident, val> ::Nodo* auxP=c.primElmt->siguiente;
//       while(auxP!= nullptr && auxP->id > super){
//         aux = aux->siguiente;
//       }
//       if(auxP==nullptr&&auxP->id!=super){return false;}
//       colecInterdep<ident, val> ::Nodo* auxH;
//       auxH = auxP;//en el que estamos seguro que no es
//       //hemos encontrado el hueco tanto si es final como si no
//       /*if (padre==true){
//         typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
//         auxN->siguiente=auxH->siguiente;
//         auxH->siguiente=auxN;
//         auxN->id=id;
//         auxN->valor=v;
//         auxN->identSup=auxP;
//         auxP->numDepend++;
//         auxN->numDepend=0;
//         c.numElem++;
//         return true;
//       }*/
//       while(auxH->siguiente != nullptr && auxH->siguiente->id > id){
//         auxH = auxH->siguiente;
//       }
//       if(auxH->siguiente == nullptr && auxH->siguiente->id==id){return false;}
//       //if(auxP== nullptr && auxP->id!=super){return false;}
//       typename colecInterdep<ident, val>::Nodo* auxN = new typename colecInterdep<ident, val>::Nodo;
//         auxN->siguiente=auxH->siguiente;
//         auxH->siguiente=auxN;
//         auxN->id=id;
//         auxN->valor=v;
//         auxN->identSup=auxP;
//         auxP->numDepend++;
//         auxN->numDepend=0;
//         c.numElem++;
//         return true;
//     }
// }
// }

//
template<typename ident, typename val> bool hacerIndependiente(colecInterdep<ident, val>& c, const ident& id){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  //despues del recorrido aux es puntero al id(si existe) o al elemento siguiente(en este caso id no existe)
  if(aux-> id == id && aux->identSup != nullptr){
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
  if(aux == nullptr || id!=aux->id){return false;}
  aux->valor = nuevo;
  return true;
}

//pre: existe
template<typename ident, typename val> val obtenerVal(const colecInterdep<ident, val>& c, const ident& id){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }if(aux == nullptr || id!=aux->id){return false;}

  return aux->valor;
}

//pre: existe y es dependiente!!!!
template<typename ident, typename val> ident obtenerSupervisor(const colecInterdep<ident, val>& c, const ident& id){
  cout << "Empezamos funcion obtener SUp"<< endl;
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
    cout << aux->id;
  }
  cout << "obtener Supervisor de " << aux->id;
  aux = aux->identSup;
  return aux->id;
}

//pre: existe!!!!
template<typename ident, typename val> unsigned int obtenerNumDependientes(const colecInterdep<ident, val>& c, const ident& id){
  typename colecInterdep<ident, val> ::Nodo* aux = c.primElmt;
  while(aux != nullptr && aux->id < id){
    aux = aux->siguiente;
  }
  return aux->numDepend;
}

//
template<typename ident, typename val> bool borrar(colecInterdep<ident, val>& c, const ident& id){

}
//ITERADOR
//
template<typename ident, typename val> bool iniciarIterador( colecInterdep<ident, val>& c){
  c.iter = c.primElmt;
}

//
template<typename ident, typename val> bool existeSiguiente(const colecInterdep<ident, val>& c){
  return c.iter == nullptr;
}

//OJO precondicion!!!! Parcial: la operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))}
template<typename ident, typename val> bool siguienteIdent(const colecInterdep<ident, val>& c, ident &sig){
  if(c.iter !=nullptr){
    sig = c.iter -> id;
    return true;
  }return false;
  
  
}

// 
template<typename ident, typename val> bool siguienteVal(const colecInterdep<ident, val>& c, val& sig){
  if(c.iter !=nullptr){
    sig = c.iter -> valor;
    return true;
  }return false;
}

// 
template<typename ident, typename val> bool siguienteDependiente(const colecInterdep<ident, val>& c){
  return !(c.iter -> identSup == nullptr);
}

//
template<typename ident, typename val> bool siguienteSuperior(const colecInterdep<ident, val>& c, ident &sig){
  if(c.iter !=nullptr){
    sig = c.iter->identSup->id;
    return true;
  }return false;
}

//
template<typename ident, typename val> bool siguienteNumDependientes(const colecInterdep<ident, val>& c, int &num){
  if(c.iter !=nullptr){
    num= c.iter->numDepend;
    return true;
  }return false;
}

//
template<typename ident, typename val> bool avanza(colecInterdep<ident, val>& c){
  if(c.iter !=nullptr){
    c.iter = c.iter->siguiente;
    return true;
  }return false;
  
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

#endif

