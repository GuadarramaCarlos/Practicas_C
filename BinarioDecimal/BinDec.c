#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"
char nombrearchivo[20];
char extension[]=".txt";
char *archivo;
int i=0, suma=0,numtemp=0,continuar,opc,opcion;
char numbin[5]="01 ";
char text[9]=" ";
int main(void){
	printf("Bienvenido usuario, en este programa se leera un archivo cuyo nombre sera porporcionado por ti\n");
	printf("Del archivo se leeran los primeros 8 caracteres, de ser numeros (0 o 1) se convertira a decimal, de no entrar en estos parametros se le hara saber\n");
	do{
		printf("Ingresa el nombre del archivo (Toma en cuenta que solo se aceptan .txt) ingresa solamente el nombre del archivo, no la extension\n"),
		scanf("%s", nombrearchivo);
		archivo = strcat(nombrearchivo,".txt");
		do{
			
			mostrarmenu();
			printf("Selecciona una opcion:");
			scanf("%d",&opc);
			switch(opc){
				case 1:
					printf("Abrir archivo %s\n",archivo);
					AbrirArchivo(archivo,text,numbin,archivo);
				break;
				
				case 2:
					imprimirArchivo(archivo,text,numbin);
				break;
				
				case 3:
					bioToDec(text,numbin);
				break;
				
				case 4:
					printf("Hasta luego\n");
					return 0;
				break;
				default:
					printf("Opcion no valida");
					
			}
			printf("Ingresa 1 para seleccionar otra opcion\n");
			scanf("%d",&opcion);
		}while(opcion==1);
		
		printf("Ingresa 1 para trabajar con otro archivo\n");
		scanf("%d",&continuar);
	}while(continuar==1);
	return 0;	
}


