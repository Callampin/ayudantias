
#include <stdio.h>
#include <stdlib.h>

struct NodoArbol {
    int dato;
    struct NodoArbol *izquierdo;
    struct NodoArbol *derecho;
};

struct NodoArbol* crearNodo(int valor) {
    struct NodoArbol *nuevoNodo = (struct NodoArbol *) malloc(sizeof(struct NodoArbol));
    nuevoNodo->dato = valor;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

int main() {
    struct NodoArbol *raiz = crearNodo(50);
    
    raiz->izquierdo = crearNodo(30);
    raiz->derecho = crearNodo(70);
    
    raiz->izquierdo->izquierdo = crearNodo(20);
    raiz->izquierdo->derecho = crearNodo(40);
    
    raiz->derecho->izquierdo = crearNodo(60);
    raiz->derecho->derecho = crearNodo(80);
    
    printf("--- Arbol Binario Creado ---\n\n");
    printf("           50\n");
    printf("         /    \\\n");
    printf("       30      70\n");
    printf("      /  \\    /  \\\n");
    printf("    20   40  60   80\n\n");
    
    printf("Nodo raiz: %d\n", raiz->dato);
    printf("Hijo izquierdo de raiz: %d\n", raiz->izquierdo->dato);
    printf("Hijo derecho de raiz: %d\n", raiz->derecho->dato);
    
    printf("\n--- Liberando memoria ---\n");
    free(raiz->izquierdo->izquierdo);
    free(raiz->izquierdo->derecho);
    free(raiz->izquierdo);
    free(raiz->derecho->izquierdo);
    free(raiz->derecho->derecho);
    free(raiz->derecho);
    free(raiz);
    printf("Memoria liberada\n");
    
    getchar();
    return 0;
}
