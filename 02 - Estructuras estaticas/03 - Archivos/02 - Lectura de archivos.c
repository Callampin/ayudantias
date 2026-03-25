
#include <stdio.h>

int main() {
    FILE *archivo;
    char linea[100];
    
    archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura\n");
        return 1;
    }
    
    printf("--- Contenido del archivo ---\n");
    while (fgets(linea, 100, archivo) != NULL) {
        printf("%s", linea);
    }
    
    fclose(archivo);
    
    getchar();
    return 0;
}
