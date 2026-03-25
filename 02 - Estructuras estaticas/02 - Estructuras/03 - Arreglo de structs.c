
#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[50];
    int edad;
};

int main() {
    struct Persona personas[3];
    
    personas[0].edad = 20;
    personas[1].edad = 22;
    personas[2].edad = 19;
    strcpy(personas[0].nombre, "Ana");
    strcpy(personas[1].nombre, "Luis");
    strcpy(personas[2].nombre, "Maria");
    
    printf("--- Lista de personas ---\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - %d anios\n", i + 1, personas[i].nombre, personas[i].edad);
    }
    
    int sumaEdades = 0;
    for (int i = 0; i < 3; i++) {
        sumaEdades = sumaEdades + personas[i].edad;
    }
    printf("\nPromedio de edades: %d\n", sumaEdades / 3);
    
    getchar();
    return 0;
}
