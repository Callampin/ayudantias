
#include <stdio.h>

int potencia(int base, int exponente) {
    if (exponente == 0) return 1;
    return base * potencia(base, exponente - 1);
}

int multiplicacion(int a, int b) {
    if (b == 0) return 0;
    return a + multiplicacion(a, b - 1);
}

int contarDigitos(int n) {
    if (n == 0) return 0;
    return 1 + contarDigitos(n / 10);
}

int main() {
    printf("--- Potencia ---\n");
    printf("2^5 = %d\n", potencia(2, 5));
    
    printf("\n--- Multiplicacion ---\n");
    printf("3 x 4 = %d\n", multiplicacion(3, 4));
    
    printf("\n--- Contar digitos ---\n");
    printf("Cantidad de digitos en 98765: %d\n", contarDigitos(98765));
    
    getchar();
    return 0;
}
