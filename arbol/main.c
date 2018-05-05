#include <stdio.h>
#include <stdlib.h>
#include "arbol.c"
//gcc main.c -o main.exe 
 


int main(int argc, char *argv []){
    unsigned i, n = 7;
    Nodo *raiz = NULL;
    Info datos [] = {40, 20, 30, 10, 60, 70, 50, 45, 55, 54, 65,
    63, 75, 64};
    for(i = 0; i < n; i++){
        raiz = insertar(raiz, datos[i]);
    }
    preorden(raiz);
    printf("\n");
    
    postorden(raiz);
    printf("\n");
    
    raiz = eliminar(raiz, 60);
    raiz = eliminar(raiz, 20);
    preorden(raiz);
    printf("\n");
}