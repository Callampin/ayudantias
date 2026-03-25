
#include <stdio.h>

struct Persona {
    char nombre[50];
    int edad;
};

int main() {
    FILE *archivo;
    struct Persona persona1 = {"Carlos", 30};
    struct Persona personaLeida;
    
    archivo = fopen("datos.bin", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura\n");
        return 1;
    }
    fwrite(&persona1, sizeof(struct Persona), 1, archivo);
    fclose(archivo);
    
    archivo = fopen("datos.bin", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura\n");
        return 1;
    }
    fread(&personaLeida, sizeof(struct Persona), 1, archivo);
    fclose(archivo);
    
    printf("Persona leida: %s, %d anios\n", personaLeida.nombre, personaLeida.edad);
    
    getchar();
    return 0;
}
