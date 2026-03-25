
#include <stdio.h>

struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

void mostrarPersona(struct Persona p) {
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\n", p.edad);
    printf("Altura: %.2f metros\n", p.altura);
}

void modificarEdad(struct Persona *p, int nuevaEdad) {
    p->edad = nuevaEdad;
}

int main() {
    struct Persona persona1 = {"Chris", 24, 1.73};
    
    printf("--- Datos originales ---\n");
    mostrarPersona(persona1);
    
    modificarEdad(&persona1, 25);
    
    printf("\n--- Datos modificados ---\n");
    mostrarPersona(persona1);
    
    getchar();
    return 0;
}
