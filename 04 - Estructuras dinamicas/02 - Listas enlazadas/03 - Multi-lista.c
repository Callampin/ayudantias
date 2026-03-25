
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Materia {
    char nombre[50];
    int codigo;
};

struct NodoMateria {
    struct Materia datos;
    struct NodoMateria *siguienteMateria;
    struct NodoMateria *siguienteAlumno;
};

int main() {
    struct NodoMateria *cabecera = NULL;
    
    struct NodoMateria *mat1 = (struct NodoMateria *) malloc(sizeof(struct NodoMateria));
    mat1->datos.codigo = 101;
    strcpy(mat1->datos.nombre, "Matematicas");
    mat1->siguienteMateria = NULL;
    mat1->siguienteAlumno = NULL;
    
    struct NodoMateria *mat2 = (struct NodoMateria *) malloc(sizeof(struct NodoMateria));
    mat2->datos.codigo = 102;
    strcpy(mat2->datos.nombre, "Programacion");
    mat2->siguienteMateria = NULL;
    mat2->siguienteAlumno = NULL;
    
    mat1->siguienteMateria = mat2;
    cabecera = mat1;
    
    printf("--- Multi-Lista: Materias ---\n\n");
    
    struct NodoMateria *actual = cabecera;
    int posMateria = 1;
    while (actual != NULL) {
        printf("Materia %d: %s (codigo: %d)\n", 
               posMateria, actual->datos.nombre, actual->datos.codigo);
        actual = actual->siguienteMateria;
        posMateria++;
    }
    
    printf("\n--- Liberando memoria ---\n");
    free(mat1);
    free(mat2);
    printf("Memoria liberada\n");
    
    getchar();
    return 0;
}
