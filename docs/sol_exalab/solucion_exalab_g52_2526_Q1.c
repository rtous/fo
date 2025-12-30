/*
	Control de Laboratorio, Grupo 22, 22 diciembre 2025

	Nombre y apellidos: ???????
*/

#include<stdio.h>

#define MAX_DATOS 100
#define TRUE 1
#define FALSE 0

typedef struct {
	int anyo;
	int valor;
} tdato;

typedef struct {
	int	ndatos;
	tdato vdatos[MAX_DATOS];
} tdatos;

int menu();
void mostrar_datos(tdatos datos);
void modificar_dato(tdatos *datos);
void introducir_dato(tdatos *datos);
void eliminar_dato(tdatos *datos);

int main(){
	int opcion;
	tdatos datos = {5, {
			{2021, 3957},
			{2022, 4030},
			{2023, 4135},
			{2024, 4477},
			{2025, 4943}
		}
	};
	do {
		opcion = menu();
		switch(opcion) {
			case 1:
				mostrar_datos(datos);
				break;
			case 2:
				modificar_dato(&datos);
				break;
			case 3:
				introducir_dato(&datos);
				break;
			case 4:
				eliminar_dato(&datos);
				break;
		}
	} while (opcion != 5);
}

int menu() {

	int opcion;

	printf("\n1) Mostrar datos\n");
	printf("2) Modificar dato\n");
	printf("3) Introducir nuevo dato\n");
	printf("4) Eliminar dato\n");
	printf("5) Salir\n");
	do {
		printf("Escoja una opcion (1-5): ");
		scanf("%d%*c", &opcion);
	} while (opcion < 1 || opcion > 5);

	return opcion;
}

void mostrar_datos(tdatos datos) {

	int i;
	

	for (i = 0; i < datos.ndatos; i++) {
		printf("(%d, %d)\n", datos.vdatos[i].anyo, datos.vdatos[i].valor);
	}
	if (datos.ndatos == 0)
		printf("No hay datos\n");
}

void modificar_dato(tdatos *datos) {

	int anyo;
	int i;
	int valor;
	unsigned int ncasos;

	printf("Anyo: ");
	scanf("%d%*c", &anyo);
	printf("Valor: ");
	scanf("%d%*c", &valor);
	i = 0;
	while (i < datos->ndatos && datos->vdatos[i].anyo < anyo)
		i++;
	if (datos->ndatos > 0 && i < datos->ndatos && datos->vdatos[i].anyo == anyo ) {
		datos->vdatos[i].valor = valor;
	} else 
		printf("No existe el anyo!\n");
}

void introducir_dato(tdatos *datos) {

	int i, j;
	tdato dato;

	printf("Anyo: ");
	scanf("%d%*c", &dato.anyo);
	printf("Valor: ");
	scanf("%d%*c", &dato.valor);
	i = 0;
	while (i < datos->ndatos && datos->vdatos[i].anyo < dato.anyo)
		i++;
	if (datos->ndatos > 0 && i < datos->ndatos && datos->vdatos[i].anyo == dato.anyo)
		printf("Ya existe el anyo!\n");
	else {
		for (j = datos->ndatos; j > i; j--) {
			datos->vdatos[j] = datos->vdatos[j-1];
		}
		datos->vdatos[i] = dato;
		datos->ndatos++;
	}
}

void eliminar_dato(tdatos *datos) {

	int anyo, mes;
	int i, j;

	printf("Anyo: ");
	scanf("%d%*c", &anyo);
	i = 0;
	while (i < datos->ndatos && datos->vdatos[i].anyo < anyo)
		i++;
	if (datos->ndatos > 0 && i < datos->ndatos && datos->vdatos[i].anyo == anyo) {
		for (j = i; j < datos->ndatos-1; j++) {
			datos->vdatos[j] = datos->vdatos[j+1];
		}
		datos->ndatos--;
	}
	else 
		printf("No existe el anyo!\n");
}

