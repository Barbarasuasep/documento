#include <stdio.h>
#include <stdlib.h>

int main (){
	int B [100], cantNumeros=0, i=0, P[99], cantCortes=0, sumaTotal=0, sumaPrimaria=0, minimaDiferencia=0;
	int *arreglo_B, *arreglo_P;

	//se lee el archivo
	FILE *leerarchivo, *guardararchivo;
	leerarchivo= fopen("entrada.ent","r");
	if (leerarchivo==NULL){
		printf("El fichero no existe");
		getchar ();
		return 0;
	}
	else {
		fscanf (leerarchivo, "%d", &cantNumeros); //lee la cantidad de numeros
		if (cantNumeros<3)
			printf("La cantidad de numeros a leer es menor a 3, por favor arregle el archivo.\n");
		else {
			arreglo_B= B;
			arreglo_P= P;
			for (i=0; i<cantNumeros; i++)
			{
				fscanf(leerarchivo, "%d", arreglo_B+i); //lee cuales son los numeros
			}
			fclose (leerarchivo);
			//se calcula el numero de cortes del arreglo
			cantCortes= cantNumeros -1;
			//suma del total del arreglo
			for (i=0; i<cantNumeros; i++){
				sumaTotal= sumaTotal + *(arreglo_B+i);
			}
			//desarrollo del problema
			for (i=0; i<cantCortes; i++){
				sumaPrimaria= sumaPrimaria + *(arreglo_B+i);
				*(arreglo_P+i) = sumaPrimaria - (sumaTotal - sumaPrimaria);
				//se cambia de signo para que queden todos positivos.
				if (0> *(arreglo_P+i)){
					*(arreglo_P+i) = *(arreglo_P+i)* -1;
				}
			}
			//se elige la minima diferencia
			minimaDiferencia= *arreglo_P;
			for (i=0; i<cantCortes; i++){
				if (minimaDiferencia> *(arreglo_P+i))
					minimaDiferencia= *(arreglo_P+i);
			}
				//se guarda en el archivo de salida
				guardararchivo= fopen ("salida.sal","w+");
				fprintf(guardararchivo, "%d", minimaDiferencia );
				fclose(guardararchivo);
			
		}
	}
}