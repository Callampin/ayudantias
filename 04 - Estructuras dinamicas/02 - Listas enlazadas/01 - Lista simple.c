
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarAlFinal(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevoNodo = (struct Nodo *) malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    
    struct Nodo *actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;
}

void mostrarLista(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo *lista = NULL;
    
    printf("--- Lista Enlazada Simple ---\n\n");
    
    printf("Insertando: 10, 20, 30\n");
    insertarAlFinal(&lista, 10);
    insertarAlFinal(&lista, 20);
    insertarAlFinal(&lista, 30);
    
    printf("Lista actual: ");
    mostrarLista(lista);
    
    printf("\n--- Eliminando nodos y liberando memoria ---\n");
    struct Nodo *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
    printf("Memoria liberada\n");
    
    getchar();
    return 0;
}
