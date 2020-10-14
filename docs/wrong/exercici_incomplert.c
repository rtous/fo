#include <stdio.h>
#include "colours.h"

int main()
{
	char letra;

	printf("Introduzca un caracter: ");
	scanf("%c%*c", &letra);

	if ((letra == 'a') || (letra == 'e') || (letra == 'i') || (letra == 'o') || (letra == 'u'))

	printf("Es una vocal");

	else	printf("El caracter %c no es una vocal\n", letra);
}
