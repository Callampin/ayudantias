
#include <stdio.h>

int suma(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + suma(arr, n - 1);
}

int maximo(int arr[], int n) {
    if (n == 1) return arr[0];
    int resto = maximo(arr, n - 1);
    return (arr[n - 1] > resto) ? arr[n - 1] : resto;
}

int busquedaBinaria(int arr[], int inicio, int fin, int objetivo) {
    if (inicio > fin) return -1;
    int medio = inicio + (fin - inicio) / 2;
    if (arr[medio] == objetivo) return medio;
    if (arr[medio] > objetivo) return busquedaBinaria(arr, inicio, medio - 1, objetivo);
    return busquedaBinaria(arr, medio + 1, fin, objetivo);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    printf("--- Suma de elementos ---\n");
    printf("La suma es: %d\n", suma(arr, n));
    
    printf("\n--- Maximo ---\n");
    printf("El maximo es: %d\n", maximo(arr, n));
    
    printf("\n--- Busqueda binaria ---\n");
    int pos = busquedaBinaria(arr, 0, n - 1, 3);
    printf("Posicion de 3: %d\n", pos);
    
    getchar();
    return 0;
}
