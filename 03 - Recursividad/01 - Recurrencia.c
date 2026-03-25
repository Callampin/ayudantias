
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int sumaDigitos(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumaDigitos(n / 10);
}

int main() {
    int n = 5;
    
    printf("--- Fibonacci ---\n");
    printf("Fibonacci de %d es: %d\n", n, fibonacci(n));
    
    printf("\n--- Factorial ---\n");
    printf("Factorial de %d es: %d\n", n, factorial(n));
    
    printf("\n--- Suma de digitos ---\n");
    int numero = 1234;
    printf("Suma de digitos de %d es: %d\n", numero, sumaDigitos(numero));
    
    getchar();
    return 0;
}
