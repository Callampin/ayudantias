
#include <stdio.h>
#include <stdlib.h>

struct NodoDoble {
    int dato;
    struct NodoDoble *anterior;
    struct NodoDoble *siguiente;
};

void insertarAlFinalDoble(struct NodoDoble **cabeza, int valor) {
    struct NodoDoble *nuevoNodo = (struct NodoDoble *) malloc(sizeof(struct NodoDoble));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    
    struct NodoDoble *actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    
    actual->siguiente = nuevoNodo;
    nuevoNodo->anterior = actual;
}

void mostrarAdelante(struct NodoDoble *cabeza) {
    struct NodoDoble *actual = cabeza;
    printf(" Adelante: ");
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void mostrarAtras(struct NodoDoble *cabeza) {
    struct NodoDoble *actual = cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    printf(" Atras:    ");
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL\n");
}

int main() {
    struct NodoDoble *lista = NULL;
    
    printf("--- Lista Enlazada Doble ---\n\n");
    
    printf("Insertando: 10, 20, 30\n");
    insertarAlFinalDoble(&lista, 10);
    insertarAlFinalDoble(&lista, 20);
    insertarAlFinalDoble(&lista, 30);
    
    mostrarAdelante(lista);
    mostrarAtras(lista);
    
    printf("\n--- Liberando memoria ---\n");
    struct NodoDoble *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
    printf("Memoria liberada\n");
    
    getchar();
    return 0;
}
