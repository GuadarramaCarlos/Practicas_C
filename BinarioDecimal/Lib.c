#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
void mostrarmenu(){
	printf("Este es el menu de opciones:\n");
	printf("1.-Abrir archivo y verificar que sea binario\n");
	printf("2.-Imprimir contenido del archivo (Los primeros 8 caracteres)\n");
	printf("3.-Convertir binario a decimal\n");
	printf("4.-Salir del programa\n");
}

void AbrirArchivo(char nomArch[100],char linea[9],char numbin[5],char nombrearchivo[100]){
	int Bin=1;
	int i=0;
	int abierto=1;
	FILE *arch= fopen((char*)nomArch,"r");
	if(arch==NULL){
		printf("	El archivo:%s  no existe\n",nombrearchivo);
		abierto=1;
	}
	else{
		printf("	Archivo abierto exitosamente\n");
		fgets(linea,sizeof(linea)+1,arch);
		printf("%s\n",linea);
		fclose(arch);
		
		//Validacion caracteres
		for(i=0;i<8;i++){
			printf("Estamos comparando %c en la posicion %d\n ",linea[i],i);
			if(linea[i]!=numbin[0] && linea[i]!=numbin[1]){
				printf("	El archivo contiene caracteres no afines a un binario\n");
				printf("	El caracter no valido fue (%c)\n",linea[i]);
				Bin==0;
				break;
			}
		}
		if(Bin==1){
			printf("El archivo es binario\n");
		}
	}
}

void imprimirArchivo(char nomArch2[100],char linea[9],char numbin[5]){
	if(linea[0]==numbin[2]){
		printf("	Abre el archivo binario antes de imprimir el contenido\n");
	}else{
		printf("	%s\n",linea);
	}
}

void bioToDec(char linea[9],char numbin[5]){
	int i=0,numtemp,suma;
	if(linea[0]==numbin[2]){
		printf("	Abre el archivo binario antes de imprimir el contenido\n");
	}else{
		for(i=0;i<8;i++){
			if(linea[i]==numbin[0]){
				//printf("Se entro a la condicion 1");
				numtemp=0;
			}
			else{
				//printf("Se entro a la condicion 2");
				numtemp=1;
			}
			//printf("El numero temporal es (%d) y se esta elevando a %d y el numero en linea es %c\n", numtemp,i,linea[i]);
			//printf("+%d*(%d)",numtemp,7-i);
			suma+=(numtemp)*pow(2,7-i);
		}	
		printf("El numero es: %d\n",suma);
	
	}
	
}
