#include "arbol.h"

Nodo *crearNodo(Info dato){
    Nodo *nodo;
    nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->izq = nodo->der = NULL;
    return nodo;
}

Nodo *insertar(Nodo *a, Info dato){
    if(a == NULL){
        return crearNodo(dato);
    }else{
        if(dato < a->dato){
            a->izq = insertar(a->izq, dato);
        }else{
            if(dato > a->dato){
                a->der = insertar(a->der, dato);
            }
        }
        
    }
    return a;
}

Nodo* buscarMin(Nodo *a){
    if(a == NULL){
        return NULL;
    }
    if(a->izq == NULL){
        return a;
    }else{
        return buscarMin(a->izq);
    }
}

Nodo *eliminar(Nodo *a, Info dato){
    if(a == NULL){
        printf("No existe el elemento\n");
    }else{
        if(dato < a->dato){
            a->izq = eliminar(a->izq, dato);
        }else{
            if(dato > a->dato){
                a->der = eliminar(a->der, dato);
            }else{
                Nodo *temp;
                
                if(a->der != NULL && a->izq != NULL){
                    temp = buscarMin(a->der);
                    a->dato =temp->dato;
                    a->der = eliminar(a->der, temp->dato);
                }else{
                    temp = a;
                    if(a->izq == NULL){
                        a = a->der;
                    }else{
                        if(a->der == NULL){
                            a = a->izq;
                        }
                    }
                    free(temp);
                }
            }
        }
    }
    return a;
}

Nodo *buscar(Nodo *a, Info dato){
    if(a ==NULL){
        return NULL;
    }else{
        if(dato < a->dato){
            return buscar(a->izq, dato);
        }else{
            if(dato > a->dato){
                return buscar(a->der, dato);
            }else{
                return a;
            }
        }
    }
}

void preorden(Nodo *a){
    if(a != NULL){
        printf("%d ", a->dato);
        preorden(a->izq);
        preorden(a->der);
    }
}

void postorden(Nodo *a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        printf("%d ", a->dato);
    }
}