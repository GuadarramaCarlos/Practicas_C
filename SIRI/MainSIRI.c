#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void crearArchivo(char *nombreArchivo);
void leerArchivo(char *nombreArchivo);
void escribirArchivo(char *nombreArchivo, const char *texto);
void procesarDetalleIncidencia(char *detalle, char *resultado);
bool validarDetalle(const char *detalle);
void imprimirDetallesProcesados(char *archInc, char *archFol);
void imprimirDetallesFiltrados(char codigo[5],char *archInc, char *archFol);
void ConteoFiltro(char codigo[5], char *archFol);

int main() {
    int tipUsu,opcAdmin,opcAdmin2,numCue,result,opcion;
    int continuar = 1;
    int conGen = 1;
    int conAdmin = 1;
    char tipEdi[3], tipInc[3];
    char cadFol[1000] = "";
    char cadDetInc[1000] = "";
    char detalleIncidencia[151];
    char detalleFormateado[152]; // Espacio extra para el @
    char contrasenaAdminVerdadera[] = "12345";
    char contrasenaAdmin[20], codigoEdi[20];

    const char *NoCuenta = "NoCuenta.txt";
    const char *Folio = "Folio.txt";
    const char *DetInc = "DetInc.txt";
    crearArchivo((char *)NoCuenta);
    crearArchivo((char *)Folio);
    crearArchivo((char *)DetInc);
    //char codigo[]="0203";


    printf("Bienvenido al Sistema de Reporte de Incidencias (SIRI)\n");

    while (continuar == 1) {
        printf("Por favor ingresa tu tipo de usuario\n");
        printf("1.- Usuario general\n");
        printf("2.- Usuario administrador\n");
        scanf("%d", &tipUsu);

        while (tipUsu != 1 && tipUsu != 2) {
            printf("Ingresa un tipo de usuario valido\n");
            scanf("%d", &tipUsu);
        }

        switch (tipUsu) {
             case 1: // Usuario general
                conGen = 1;
                while (conGen == 1) {
                    printf("Bienvenido, por favor ingresa tu numero de cuenta\n");
                    scanf("%d", &numCue);

                    while (numCue < 99999999 || numCue >= 499999999) {
                        printf("Ingresa un numero de cuenta valido\n");
                        scanf("%d", &numCue);
                    }

                    // Convertir el número de cuenta a cadena y escribirlo en NoCuenta.txt
                    char numCueStr[20];
                    snprintf(numCueStr, sizeof(numCueStr), "%d", numCue);
                    escribirArchivo((char *)NoCuenta, numCueStr);

                    printf("Por favor ingresa el tipo de edificio (01 a 05)\n");
                    printf("01 Edificio A\n02 Edificio B\n03 Edificio C\n04 Edificio D\n05 Edificio E\n");
                    scanf("%s", tipEdi);
                    while (strcmp(tipEdi, "01") && strcmp(tipEdi, "02") && strcmp(tipEdi, "03") && strcmp(tipEdi, "04") && strcmp(tipEdi, "05")) {
                        printf("Escribe un numero de edificio valido\n");
                        scanf("%s", tipEdi);
                    }

                    printf("Ingresa el tipo de incidencia (01 a 03)\n");
                    printf("01 Falta de servicios\n02 Danio a la propiedad\n03 Pintarrajeos\n");
                    scanf("%s", tipInc);
                    while (strcmp(tipInc, "01") && strcmp(tipInc, "02") && strcmp(tipInc, "03")) {
                        printf("Ingresa un tipo de incidencia valido\n");
                        scanf("%s", tipInc);
                    }

                    // Concatenar edificio e encidencia y escribir en Folio.txt
                    char folioEntry[15];
                    snprintf(folioEntry, sizeof(folioEntry), "%s%s%s", numCueStr, tipEdi, tipInc);
                    escribirArchivo((char *)Folio, folioEntry);

                    // Validar y procesar el detalle de incidencia
                    do {
                        printf("Ingresa el detalle de la incidencia (maximo 100 caracteres, no se permiten '&' ni '@'):\n");
                        scanf(" %[^\n]", detalleIncidencia);

                        if (!validarDetalle(detalleIncidencia)) {
                            printf("Error: los caracteres '&' y '@' no están permitidos. Intenta de nuevo.\n");
                        }
                    } while (!validarDetalle(detalleIncidencia));

                    procesarDetalleIncidencia(detalleIncidencia, detalleFormateado);
                    escribirArchivo((char *)DetInc, detalleFormateado);
                    


                    printf("Incidencia registrada exitosamente.\n");
                    printf("Ingresa 1 si quieres volver al inicio del usuario general, otro numero para salir\n");
                    scanf("%d", &conGen);
                }
                break;

                
            //Inicio del admin
            case 2: 
            printf("Bienvenido al administrador,para validar tu identidad ingresa la contrasena dada\n");
            scanf(" %s", contrasenaAdmin);          
			result=strcmp(contrasenaAdmin,contrasenaAdminVerdadera);
			//strcmp compara las cadenas, de ser iguales retorna un 0
			if(result==0){
				do{
				printf("Bienvenido admin, porfavor selecciona una opcion\n");
				printf("1._Estadisticas\n");
				printf("2_Mostrar incidencias\n");
				printf("3._Mostrar incidencias filtradas\n");
				scanf("%d", &opcion);
				while(opcion<1 || opcion>3){
					printf("Elige una opcion valida  de accion entre el 1 y el 3\n");
					scanf("%d", opcion);
				}
				switch(opcion){
					case 1:
						printf("Estadisticas:\n");
						//funcionalidad de estadisticas
						printf("Estadisticas edificio A:\n");
						printf("   Tipo 01:");
						ConteoFiltro("0101", (char *)Folio);
						printf("   Tipo 02:");
						ConteoFiltro("0102", (char *)Folio);
						printf("   Tipo 03:");
						ConteoFiltro("0103", (char *)Folio);
						
						//Edificio B
						printf("Estadisticas edificio B:\n");
						printf("   Tipo 01:");
						ConteoFiltro("0201", (char *)Folio);
						printf("   Tipo 02:");
						ConteoFiltro("0202", (char *)Folio);
						printf("   Tipo 03:");
						ConteoFiltro("0203", (char *)Folio);
						
						//Edificio C
						printf("Estadisticas edificio C:\n");
						printf("   Tipo 01:");
						ConteoFiltro("0301", (char *)Folio);
						printf("   Tipo 02:");
						ConteoFiltro("0302", (char *)Folio);
						printf("   Tipo 03:");
						ConteoFiltro("0303", (char *)Folio);
						
						//Edificio D
						printf("Estadisticas edificio D:\n");
						printf("   Tipo 01:");
						ConteoFiltro("0401", (char *)Folio);
						printf("   Tipo 02:");
						ConteoFiltro("0402", (char *)Folio);
						printf("   Tipo 03:");
						ConteoFiltro("0403", (char *)Folio);
						
						//Edificio E
						printf("Estadisticas edificio D:\n");
						printf("   Tipo 01:");
						ConteoFiltro("0501", (char *)Folio);
						printf("   Tipo 02:");
						ConteoFiltro("0502", (char *)Folio);
						printf("   Tipo 03:");
						ConteoFiltro("0503", (char *)Folio);
					break;
					
					case 2:
						printf("Mostrar incidencias");
                  		imprimirDetallesProcesados((char *)DetInc,(char *)Folio);
                  		
					break;
					
					case 3:
						printf("Mostar incidencias filtradas\n");
						printf("En esta funcionalidad solo podras filtar por tipo de edificio\n");
						printf("Ingresa el codigo del edificio por el cual quieres filtrar\n");
	                    scanf("%s", codigoEdi);
	                    imprimirDetallesFiltrados(codigoEdi,(char *)DetInc, (char *)Folio);
					break;
					
					default:
					break;
					
				}
				printf("Ingresa 1 si quieres volver al inicio del administrador, otro numero para salir\n");
                scanf("%d", &conAdmin);
            	}while(conAdmin==1);
            }
            else{
            	printf("La contrasena es invalida srás retornado al inicio\n");
			}
            break;

           
        }

        printf("Ingresa 1 si quieres volver al inicio para seleccionar el tipo de usuario\n");
        scanf("%d", &continuar);
    }

    return 0;
}

// Implementación de funciones para estadísticas e incidencias
void mostrarEstadisticas() {
    printf("Mostrando estadísticas...\n");
    // Código para mostrar las estadísticas
}

void mostrarIncidencias() {
    printf("Mostrando todas las incidencias...\n");
    // Código para mostrar las incidencias
}

// Funciones de manejo de archivos
void crearArchivo(char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo != NULL) fclose(archivo);
}

void leerArchivo(char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para lectura o no existe el archivo.\n");
        return;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }
    fclose(archivo);
}

void escribirArchivo(char *nombreArchivo, const char *texto) {
    FILE *archivo = fopen(nombreArchivo, "a");
    if (archivo != NULL) {
        fprintf(archivo, "%s", texto);
        fclose(archivo);
    }
}

// Función para procesar el detalle de la incidencia
void procesarDetalleIncidencia(char *detalle, char *resultado) {
    int longitud = strlen(detalle);
    int i;
    if (longitud > 150) {
        detalle[150] = '\0'; // Truncar a 150
    }
    // Copiar detalle y rellenar con & hasta completar los 150
    strcpy(resultado, detalle);
    for ( i = longitud; i < 150; i++) {
        resultado[i] = '&';
    }
    resultado[150] = '@'; // Agregar el separador @
    resultado[151] = '\0'; // Finalizar la cadena 
}

// Función para saber que el detalle no contenga & ni @
bool validarDetalle(const char *detalle) {
	int i;
    for (i = 0; detalle[i] != '\0'; i++) {
        if (detalle[i] == '&' || detalle[i] == '@') {
            return false; // Encontro un & o @
        }
    }
    return true;
}

void imprimirDetallesProcesados(char *archInc, char *archFol) {
    FILE *archivo = fopen(archInc, "r");
    FILE *FolioArch = fopen(archFol,"r");
    char linea[152];
    char lineafol[14];
    int contador = 1;
    
    int i;
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de detalles de incidencia para lectura.\n");
        return;
    }

    if (FolioArch == NULL) {
        printf("No se pudo abrir el archivo folios para lectura.\n");
        return;
    }


    printf("\nINCIDENCIAS REGISTRADAS:\n\n");
   while (fgets(linea, sizeof(linea), archivo) && fgets(lineafol, sizeof(lineafol), FolioArch)) {
   		printf("%d.", contador++);
   		for(i = 0; lineafol[i] != '\0'; i++) {
            printf("%c", lineafol[i]);
        }
        printf(":\n     ");
        for(i = 0; linea[i] != '\0' && linea[i] != '\n' && linea[i] != '&' && linea[i] != '@'; i++) {
            printf("%c", linea[i]);
        }
        printf("\n");
    }

    if (contador == 1) {
        printf("No hay incidencias registradas.\n");
    }
    
    fclose(archivo);
}

void imprimirDetallesFiltrados(char codigo[5], char *archInc, char *archFol) {
    FILE *archivo = fopen(archInc, "r");
    FILE *FolioArch = fopen(archFol,"r");
    char linea[152];
    char lineafol[14];
	int contador = 1,i;

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de detalles de incidencia para lectura.\n");
        return;
    }

    if (FolioArch == NULL) {
        printf("No se pudo abrir el archivo folios para lectura.\n");
        return;
    }

    printf("\nSe filtran incidencias con el codigo %s:\n\n", codigo);
    while (fgets(linea, sizeof(linea), archivo) && fgets(lineafol, sizeof(lineafol), FolioArch)) {
        if (lineafol[9] == codigo[0] && lineafol[10] == codigo[1]) {
            printf("%d. ", contador++);
            printf("Folio:%s\n      ", lineafol); 
            for (i = 0; linea[i] != '\0' && linea[i] != '\n' && linea[i] != '&' && linea[i] != '@'; i++) {
                printf("%c", linea[i]); 
            }
            printf("\n");
        }
    }

    if (contador == 1) {
        printf("No hay incidencias registradas que coincidan con el codigo proporcionado.\n");
    }

    fclose(archivo);
    fclose(FolioArch);
}

void ConteoFiltro(char codigo[5], char *archFol) {
    FILE *FolioArch = fopen(archFol,"r");
    char lineafol[14];
	int contador = 0,i;

    if (FolioArch == NULL) {
        printf("No se pudo abrir el archivo folios para lectura.\n");
        return;
    }
    while (fgets(lineafol, sizeof(lineafol), FolioArch)) {
        if (lineafol[9] == codigo[0] && lineafol[10] == codigo[1] &&  lineafol[11] == codigo[2] && lineafol[12] == codigo[3]) {
             contador++;
        }
    }
    printf("%d\n", contador);
    fclose(FolioArch);
}
