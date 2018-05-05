typedef int Info;
/* estructura autoreferenciada */
typedef struct nodoArbol { 
    
    Info dato;
    struct nodoArbol *izq; 
    struct nodoArbol *der; 
}Nodo;


Nodo *crearNodo(Info dato);
Nodo *insertar(Nodo *a, Info dato);
Nodo* buscarMin(Nodo *a);
Nodo *eliminar(Nodo *a, Info dato);
Nodo *buscar(Nodo *a, Info dato);
void preorden(Nodo *a);
void inorden(Nodo *a);
void postorden(Nodo *a);