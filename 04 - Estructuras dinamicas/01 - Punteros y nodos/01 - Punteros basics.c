
#include <stdio.h>

int main() {
    int variable = 42;
    int *puntero;
    
    puntero = &variable;
    
    printf("--- Punteros basicos ---\n\n");
    
    printf("Valor de 'variable': %d\n", variable);
    printf("Direccion de 'variable' (&variable): %p\n", &variable);
    
    printf("\n--- Usando el puntero ---\n\n");
    
    printf("Valor de 'puntero' (la direccion que almacena): %p\n", puntero);
    printf("Direccion del puntero itself (&puntero): %p\n", &puntero);
    printf("Valor al que apunta 'puntero' (*puntero): %d\n", *puntero);
    
    printf("\n--- Modificando a traves del puntero ---\n\n");
    
    *puntero = 100;
    printf("Ahora 'variable' vale: %d\n", variable);
    
    getchar();
    return 0;
}
