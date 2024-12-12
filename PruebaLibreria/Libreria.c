#include <stdio.h>
void cifrar(char texto[], char textocifrado[], int desplazamiento) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            textocifrado[i] = 'A' + (texto[i] - 'A' + desplazamiento) % 26; 
        } else {
            textocifrado[i] = texto[i]; 
        }
    }
    textocifrado[i] = '\0'; 
}

void descifrar(char texto[], char textodescifrado[], int desplazamiento) {
    int i;
    for (i = 0; texto [i] != '\0'; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            textodescifrado[i] = 'A' + (texto[i] - 'A' - desplazamiento + 26) % 26; 
        } else {
            textodescifrado[i] = texto[i]; 
        }
    }
    textodescifrado[i] = '\0'; 
}

void convertirAMayusculas(char texto[]) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] -= ('a' - 'A'); 
        }
    }
}
