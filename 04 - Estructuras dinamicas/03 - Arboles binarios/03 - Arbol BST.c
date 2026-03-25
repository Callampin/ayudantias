
#include <stdio.h>
#include <stdlib.h>

struct NodoBST {
    int dato;
    struct NodoBST *izquierdo;
    struct NodoBST *derecho;
};

struct NodoBST* crearNodo(int valor) {
    struct NodoBST *nuevo = (struct NodoBST *) malloc(sizeof(struct NodoBST));
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

struct NodoBST* insertar(struct NodoBST *raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }
    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    return raiz;
}

struct NodoBST* buscar(struct NodoBST *raiz, int valor) {
    if (raiz == NULL || raiz->dato == valor) {
        return raiz;
    }
    if (valor < raiz->dato) {
        return buscar(raiz->izquierdo, valor);
    }
    return buscar(raiz->derecho, valor);
}

void inorden(struct NodoBST *nodo) {
    if (nodo == NULL) return;
    inorden(nodo->izquierdo);
    printf("%d ", nodo->dato);
    inorden(nodo->derecho);
}

int main() {
    struct NodoBST *raiz = NULL;
    
    printf("--- Arbol BST (Binary Search Tree) ---\n\n");
    
    printf("Insertando: 50, 30, 70, 20, 40, 60, 80\n\n");
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 60);
    insertar(raiz, 80);
    
    printf("Arbol en inorden: ");
    inorden(raiz);
    printf("\n\n");
    
    printf("Buscando 40: ");
    if (buscar(raiz, 40) != NULL) {
        printf("Encontrado!\n");
    } else {
        printf("No encontrado\n");
    }
    
    printf("Buscando 25: ");
    if (buscar(raiz, 25) != NULL) {
        printf("Encontrado!\n");
    } else {
        printf("No encontrado\n");
    }
    
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
