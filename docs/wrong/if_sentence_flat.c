#include<stdio.h>


int main()
{

	char letra;


		printf("\nIntroduzca un caracter: ");
		scanf("%c%*c", &letra);

		if (letra!='a'&& letra!='e'&& letra!='i'&& letra!='o'&& letra!='u')
			printf("\nEs una letra\nNo es una vocal\n");

		else
			printf("\nNo es una letra\nEs una vocal\n");

		if(letra>='a' && letra<='z' || letra>='A' && letra<='Z')
			printf("Es una consonante\n");
		else
			printf("No es una consonante\n");

		if(letra>='A' && letra<='Z')
			printf("Es una mayuscula\n");
		else
			printf("No es una mayuscula\n");

		if(letra>=0 && letra<=9)
			printf("Es un digito\n");
		else
			printf("No es un digito\n");
 

		if(letra>='a' && letra<='z')
		{
			letra=letra-('a'-'A');
			printf("El caracter con la capitalizacion invertida es %c\n", letra);
		}
		else if (letra>='A' && letra<='Z')
		{
			letra=letra+('a'-'A');
			printf("El caracter con la capitalizacion invertida es %c\n", letra);
		}	
}
