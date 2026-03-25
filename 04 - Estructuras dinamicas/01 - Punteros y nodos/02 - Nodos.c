
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

int main() {
    struct Nodo *nodo1;
    struct Nodo *nodo2;
    struct Nodo *nodo3;
    
    nodo1 = (struct Nodo *) malloc(sizeof(struct Nodo));
    nodo2 = (struct Nodo *) malloc(sizeof(struct Nodo));
    nodo3 = (struct Nodo *) malloc(sizeof(struct Nodo));
    
    nodo1->dato = 10;
    nodo1->siguiente = nodo2;
    
    nodo2->dato = 20;
    nodo2->siguiente = nodo3;
    
    nodo3->dato = 30;
    nodo3->siguiente = NULL;
    
    printf("--- Lista enlazada de 3 nodos ---\n\n");
    
    struct Nodo *actual = nodo1;
    int posicion = 1;
    
    while (actual != NULL) {
        printf("Nodo %d: dato = %d, siguiente = %p\n", 
               posicion, actual->dato, (void*)actual->siguiente);
        actual = actual->siguiente;
        posicion++;
    }
    
    printf("\n--- Libreando memoria ---\n\n");
    free(nodo1);
    free(nodo2);
    free(nodo3);
    printf("Memoria liberada correctamente\n");
    
    getchar();
    return 0;
}
