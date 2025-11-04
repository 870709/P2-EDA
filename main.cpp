#include "coleccionesInterdependientes.hpp"
#include "evento.hpp"
#include "coleccionesInterdependientes.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const string ID_VACIO = "-.-.-.-.-";

/**
 * Procesa la instrucción 'I' (hacer Independiente).
 * Lee un 'id' de 'f'. Intenta hacerlo independiente en 'c'.
 * Escribe el resultado en 'g' según si la operación tuvo éxito,
 * si el evento ya era independiente, o si no existía.
 */
void procesarI(ifstream& f, ofstream& g, colecInterdep<string, Evento>& c) {
    string id;
    getline(f, id);

    // 1. Intentamos la operación. Esta función (idealmente) busca el nodo,
    // comprueba si es dependiente y, si lo es, lo modifica.
    // Devuelve 'true' solo si ha realizado un cambio.
    if (hacerIndependiente(c, id)) {
        // Éxito: Se encontró y se cambió de dependiente a independiente.
        g << "INDEPENDIZADO: " << id << endl;
    } else {
        // Fracaso: O no existe, o ya era independiente.
        // Necesitamos una búsqueda adicional para distinguirlos.
        if (existeIndependiente(c, id)) {
            // Se encontró, pero no hubo cambio porque ya era independiente.
            g << "YA ERA INDepend.: " << id << endl;
        } else {
            // Si 'hacerIndependiente' falló y 'existeIndependiente' es falso,
            // entonces el elemento no existe (o es dependiente y 'hacerIndependiente'
            // falló por otra razón, pero "no existe" es el único caso restante
            // según la especificación de salida).
            g << "NO INDEPENDIZADO: " << id << endl;
        }
    }
}



/**
 * Procesa la instrucción 'D' (hacer Dependiente).
 * Lee un 'id' y un 'super' de 'f'.
 * Comprueba si AMBOS existen. Si es así, imprime "INTENTANDO" y
 * llama a la operación del TAD. Si no, imprime "IMPOSIBLE".
 */
void procesarD(ifstream& f, ofstream& g, colecInterdep<string, Evento>& c) {
    string id, super;
    getline(f, id);
    getline(f, super);

    // La especificación de salida nos obliga a comprobar la existencia primero.
    if (existe(c, id) && existe(c, super)) {
        // Ambos existen. Informamos del intento y luego lo ejecutamos.
        g << "INTENTANDO hacer depend.: " << id << " -de-> " << super << endl;
        
        // Llamamos a la operación del TAD.
        // No necesitamos comprobar el 'bool' de retorno,
        // ya que la salida no informa del resultado del intento.
        hacerDependiente(c, id, super);
    } else {
        // Uno o ambos no existen.
        g << "IMPOSIBLE hacer depend.: " << id << " -de-> " << super << endl;
    }
}



/**
 * Procesa la instrucción 'B' (Borrar).
 * Lee un 'id' de 'f'. Intenta borrarlo de 'c'.
 * El TAD 'borrar' devuelve true si tiene éxito (existe y numDepend == 0).
 * Escribe "BORRADO" o "NO BORRADO" en 'g'.
 */
void procesarB(ifstream& f, ofstream& g, colecInterdep<string, Evento>& c) {
    string id;
    getline(f, id);

    // La lógica del TAD 'borrar' coincide con la salida requerida.
    // 'borrar' falla si no existe O si tiene dependientes.
    if (borrar(c, id)) {
        g << "BORRADO: " << id << endl;
    } else {
        g << "NO BORRADO: " << id << endl;
    }
}


/**
 * Procesa la instrucción 'LD' (Listar Dependientes).
 * Lee un 'id' de 'f'.
 * 1. Busca el evento 'id' y lista sus detalles.
 * 2. Itera por TODA la colección y lista los detalles de cualquier
 * evento que sea directamente dependiente de 'id'.
 * Utiliza el iterador del TAD como es obligatorio.
 */
void procesarLD(ifstream& f, ofstream& g, colecInterdep<string, Evento>& c) {
    string id;
    getline(f, id);
    g << "****DEPENDIENTES: " << id << endl;

    // --- 1. Buscar y mostrar el evento "padre" ---
    Evento eventoPadre;
    bool esDepPadre;
    string superPadre;
    unsigned int numDepPadre;

    // Usamos 'obtenerInfo' para la eficiencia (1 sola búsqueda)
    if (!obtenerInfo(c, id, eventoPadre, esDepPadre, superPadre, numDepPadre)) {
        g << "****DESCONOCIDO" << endl;
        return; // El evento no existe, terminamos
    }

    // El evento existe. Mostramos sus datos.
    string descPadre = descripcion(eventoPadre);
    unsigned int prioPadre = prioridad(eventoPadre);

    if (esDepPadre) {
        g << "[ " << id << " -de-> " << superPadre << " ;;; " << numDepPadre << " ] --- "
          << descPadre << " --- ( " << prioPadre << " ) ****" << endl;
    } else {
        g << "[ " << id << " --- " << numDepPadre << " ] --- "
          << descPadre << " --- ( " << prioPadre << " ) ****" << endl;
    }

    // --- 2. Iterar por toda la colección buscando hijos ---
    iniciarIterador(c);
    int contadorHijos = 1; // Para el 'p' del formato de salida

    while (existeSiguiente(c)) {
        bool esDepHijo = siguienteDependiente(c);
        
        // Comprobamos si el elemento actual es dependiente Y si su supervisor es 'id'
        if (esDepHijo && siguienteSuperior(c) == id) {
            
            // ¡Encontramos un hijo! Obtenemos todos sus datos
            string idHijo = siguienteIdent(c);
            Evento eventoHijo = siguienteVal(c);
            unsigned int numDepHijo = siguienteNumDependientes(c);
            string descHijo = descripcion(eventoHijo);
            unsigned int prioHijo = prioridad(eventoHijo);

            // La especificación de salida para el hijo es confusa.
            // Pide formato indep/dep, pero un hijo DEBE ser dependiente.
            // Asumimos que se refiere al formato del hijo (que es dependiente de 'id').
            
            g << "[" << contadorHijos << " -> " << idHijo << " -de-> " << id 
              << " ;;; " << numDepHijo << " ] --- "
              << descHijo << " --- ( " << prioHijo << " ) ;;;;" << endl;
            
            contadorHijos++;
        }
        
        avanza(c); // Avanzamos al siguiente elemento de la colección
    }

    g << "****FINAL dependientes -de-> " << id << endl;
}


/**
 * Procesa la instrucción 'LT' (Listar Todos).
 * Muestra el tamaño total de 'c'.
 * Itera por toda la colección 'c' en orden y muestra los
 * detalles de CADA evento, usando el formato correcto (dep/indep).
 * Utiliza el iterador del TAD como es obligatorio.
 */
void procesarLT(ofstream& g, colecInterdep<string, Evento>& c) {
    g << "-----LISTADO: " << tamanyo(c) << endl;
    
    iniciarIterador(c);
    while (existeSiguiente(c)) {
        
        // Obtenemos todos los datos del elemento actual
        string id = siguienteIdent(c);
        Evento evento = siguienteVal(c);
        bool esDep = siguienteDependiente(c);
        unsigned int numDep = siguienteNumDependientes(c);
        
        string desc = descripcion(evento);
        unsigned int prio = prioridad(evento);

        // Imprimimos con el formato adecuado
        if (esDep) {
            string supervisor = siguienteSuperior(c);
            g << "[ " << id << " -de-> " << supervisor << " ;;; " << numDep << " ] --- "
              << desc << " --- ( " << prio << " )" << endl;
        } else {
            g << "[ " << id << " --- " << numDep << " ] --- "
              << desc << " --- ( " << prio << " )" << endl;
        }
        
        avanza(c); // Avanzamos al siguiente
    }
    
    g << "-----" << endl;
}


bool obtenerInfoEvento(ifstream& f, ofstream& g, colecInterdep<string, Evento>& coleccion) {
    string id;
    getline(f, id);
    Evento evento;
    bool esDependiente;
    string supervisor;   
    unsigned int numDep;
    if (obtenerInfo(coleccion, id, evento, esDependiente, supervisor, numDep)) {
        string desc = descripcion(evento);
        unsigned int prio = prioridad(evento);
        g << "LOCALIZADO: ";
        if (esDependiente) {
            g << "[ " << id << " -de-> " << supervisor << " ;;; " << numDep << " ] --- "
              << desc << " --- ( " << prio << " )" << endl;
        } else {
            g << "[ " << id << " --- " << numDep << " ] --- "
              << desc << " --- ( " << prio << " )" << endl;
        }
        return true; 
    } else {
        g << "NO LOCALIZADO: " << id << endl;
        return false;
    }
}

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
  unsigned int numDepend;
  getline(f, nombre);
  getline(f, descrip);
  f >> prioridad;
  getline(f, salto);
  Evento eventoNuevo = crearEvento(descrip, prioridad);

  Evento eventoAnt;
  bool depen; 
  string nomSup;


  if(obtenerInfo(coleccion, nombre, eventoAnt, depen, nomSup, numDepend)){
    if(actualizarVal(coleccion, nombre, eventoNuevo)){
      if(depen){
        g << "CAMBIADO: " << "[ "<< nombre <<" -de-> "<< nomSup <<" ;;; "<< numDepend<< " ] --- "<< descrip << " --- ( "<<prioridad<<" )" << endl;
        return true;
      }else{
        g << "CAMBIADO: " << "[ "<< nombre << " --- " << numDepend << " ] --- "<< descrip << " --- ( "<<prioridad<<" )" << endl;
        return true;
      }
    }else{
      g << "NO CAMBIADO: "<< "[ "<< nombre << " ]"<< endl;
      return false;
    }
  }else{
    g << "NO CAMBIADO: "<< "[ "<< nombre << " ]"<< endl;
    return false;
  }
}

void existe(ifstream &f,ofstream &g, colecInterdep<string, Evento>& coleccion){
  string nombre;
  getline(f, nombre);
  if(existe(coleccion, nombre)){
    if(existeDependiente(coleccion, nombre)){
      g << "DEPendiente: "<< "[ "<< nombre << " ]"<< endl;
    }else{
      g << "INDEPendiente: "<< "[ "<< nombre << " ]"<< endl;
    }
  }else{
    g << "DESCONOCIDO: "<< "[ "<< nombre << " ]"<< endl;
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
          procesarD(f, g, coleccion);
        }else if (instruccion == "O"){
          obtenerInfoEvento(f, g, coleccion);
        }else if (instruccion == "E"){
          existe(f,g,coleccion);
        }else if (instruccion == "I"){
          procesarI(f,g,coleccion);
        }else if (instruccion == "B"){
          procesarB(f,g,coleccion);
        }else if (instruccion == "LD"){
          procesarLD(f,g,coleccion);
        }else if (instruccion == "LT"){
          procesarLT(f,g,coleccion);
        }
      } 
    }else{
      cout << "Error al crear el fichero de salida."<<endl;
    }
  }else{
    cout << "Error al abrir fichero de entrada."<< endl;
  }
  
}