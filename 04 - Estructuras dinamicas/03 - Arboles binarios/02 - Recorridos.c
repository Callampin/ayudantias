
#include <stdio.h>
#include <stdlib.h>

struct NodoArbol {
    int dato;
    struct NodoArbol *izquierdo;
    struct NodoArbol *derecho;
};

struct NodoArbol* crearNodo(int valor) {
    struct NodoArbol *nuevo = (struct NodoArbol *) malloc(sizeof(struct NodoArbol));
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

void preorden(struct NodoArbol *nodo) {
    if (nodo == NULL) return;
    printf("%d ", nodo->dato);
    preorden(nodo->izquierdo);
    preorden(nodo->derecho);
}

void inorden(struct NodoArbol *nodo) {
    if (nodo == NULL) return;
    inorden(nodo->izquierdo);
    printf("%d ", nodo->dato);
    inorden(nodo->derecho);
}

void postorden(struct NodoArbol *nodo) {
    if (nodo == NULL) return;
    postorden(nodo->izquierdo);
    postorden(nodo->derecho);
    printf("%d ", nodo->dato);
}

int main() {
    struct NodoArbol *raiz = crearNodo(50);
    raiz->izquierdo = crearNodo(30);
    raiz->derecho = crearNodo(70);
    raiz->izquierdo->izquierdo = crearNodo(20);
    raiz->izquierdo->derecho = crearNodo(40);
    raiz->derecho->izquierdo = crearNodo(60);
    raiz->derecho->derecho = crearNodo(80);
    
    printf("           50\n");
    printf("         /    \\\n");
    printf("       30      70\n");
    printf("      /  \\    /  \\\n");
    printf("    20   40  60   80\n\n");
    
    printf("Preorden  (raiz, izq, der): ");
    preorden(raiz);
    printf("\n");
    
    printf("Inorden   (izq, raiz, der): ");
    inorden(raiz);
    printf("\n");
    
    printf("Postorden (izq, der, raiz): ");
    postorden(raiz);
    printf("\n");
    
    printf("\n--- Liberando memoria ---\n");
    free(raiz->izquierdo->izquierdo);
    free(raiz->izquierdo->derecho);
    free(raiz->izquierdo);
    free(raiz->derecho->izquierdo);
    free(raiz->derecho->derecho);
    free(raiz->derecho);
    free(raiz);
    
    getchar();
    return 0;
}
