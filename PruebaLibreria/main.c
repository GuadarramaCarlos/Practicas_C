#include <stdio.h>
#include "Libreria.h"

int main(void) {
    char mensaje[50];
    char cifrado[50];
    char descifrado[50];
    int opcion, desplazamiento;

    while (1) {
        printf("Ingrese frase (o 'salir' para terminar): ");
        fgets(mensaje, sizeof(mensaje), stdin);

        if (mensaje[0] == 's' && mensaje[1] == 'a' && mensaje[2] == 'l' && mensaje[3] == 'i' && mensaje[4] == 'r') {
            break; 
        }

        // Convertir el mensaje a mayúsculas
        convertirAMayusculas(mensaje);

        printf("Seleccione una opción:\n");
        printf("1. Cifrar con 1 desplazamiento\n");
        printf("2. Cifrar con x desplazamientos\n");
        printf("3. Descifrar con 1 desplazamiento\n");
        printf("4. Descifrar con x desplazamientos\n");
        printf("5. Usar texto cifrado\n");
        printf("6. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1:
                desplazamiento = 1;
                cifrar(mensaje, cifrado, desplazamiento);
                printf("Texto cifrado: %s\n", cifrado);
                break;
            case 2:
                printf("Ingrese el desplazamiento: ");
                scanf("%d", &desplazamiento);
                cifrar(mensaje, cifrado, desplazamiento);
                printf("Texto cifrado: %s\n", cifrado);
                break;
            case 3:
                desplazamiento = 1;
                descifrar(cifrado, descifrado, desplazamiento);
                printf("Texto descifrado: %s\n", descifrado);
                break;
            case 4:
                printf("Ingrese el desplazamiento: ");
                scanf("%d", &desplazamiento);
                descifrar(cifrado, descifrado, desplazamiento);
                printf("Texto descifrado: %s\n", descifrado);
                break;
            case 5:
                printf("Texto cifrado actual: %s\n", cifrado);
                printf("Seleccione una opción para descifrar:\n");
                printf("1. Descifrar con 1 desplazamiento\n");
                printf("2. Descifrar con x desplazamientos\n");
                printf("Ingrese su opción: ");
                scanf("%d", &opcion);
                getchar(); 
                switch (opcion) {
                    case 1:
                        desplazamiento = 1;
                        descifrar(cifrado, descifrado, desplazamiento);
                        printf("Texto descifrado: %s\n", descifrado);
                        break;
                    case 2:
                        printf("Ingrese el desplazamiento: ");
                        scanf("%d", &desplazamiento);
                        descifrar(cifrado, descifrado, desplazamiento);
                        printf("Texto descifrado: %s\n", descifrado);
                        break;
                    default:
                        printf("Opción no válida.\n");
                }
                break;
            case 6:
                printf("Saliendo...\n");
                return 0; 
            default:
                printf("Opción no válida.\n");
        }
    }

    return 0;
}
