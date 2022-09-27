# Ayuda para la sesión 2

## Ejercicio 1

La solución del apartado b sería:

	#include <stdio.h>

	main()
	{
		char ini1, ini2, ini3;

		printf("Introduce tus tres iniciales: ");
		scanf("%c%c%c%*c", &ini1, &ini2, &ini3);
		printf("Hola %c%c%c\n", ini1, ini2, ini3);
	}

Para trabajar con enteros debéis usar %d en vez de %c. 

En el apartado e se usan colores, un ejemplo de uso sería:

	#include <stdio.h>
	#include "colours.h"

	main()
	{
		cambiar_color(RED);
		printf("\nHola ");
		cambiar_color(DEFAULT);
	}

Al compilar debéis compilar también colores.c (viene con los ficheros de la sesión):

	gcc sesion2_ej1e.c colores.c -o sesion2_ej1e

## Ejercicio 2

Para definir la constante PI haced:

	#include <stdio.h>
	#define PI 3.14

	main()
	{
		//...
		perimetro = 2*PI*radio;
		//...
	}

Para trabajar con floats usad %f en los scanf y printf. Para que os muestre dos decimales:

	printf("Area del circulo: %.2f\n", area);

## Ejercicio 4

El ejercicio requiere ir pidiendo que el usuario haga sus cálculos y vaya pulsando enter. Esto se haría así:

		//...
		printf("Voy a adivinar tu edad. Ya lo veras. Pulsa la tecla <enter> cuando estes preparado.\nEsperando.....\n");
		scanf("%*c");
		printf("-PIENSA EN EL NUMERO DEL MES EN QUE NACISTE y pulsa <enter>\n");
		scanf("%*c");
		printf("-MULTIPLICALO POR 4 y pulsa <enter> \n");
		//....

Luego se le pide el valor final:

		printf("Cuanto te ha dado?  ");
		scanf("%d%*c", &valor);
		
Y de ese valor se extraen los dos primeros dígitos (valor/100) y los dos últimos dígitos (valor%100). El enunciado dice que hay que dividor por dos los dos primeros para obtener el mes:

		mes = (valor/100)/2;

Y sumarle dos a los dos últimos para obtener la edad:

		edad = valor%100 +2;

Con eso ya estaría pero te dice tu edad en 2015. Para actualizarlo hay que entender el truco:

	(MESNACIMIENTO*4+5)*50+1753-AÑONACIMIENTO+10 = M*200+2013-AÑONACIMIENTO
	MESNACIMIENTO*200 situa MESNACIMIENTO*2 en los dos dígitos altos del resultado
	2013-AÑONACIMIENTO da la edad en 2013 (quedará en los dos dígitos bajos)

En realidad el cálculo es para 2013 pero le sumamos 2 para que sea para 2015. Para actualizarlo al año actual habría que sumarle (AÑOACTUAL-2013) en vez de dos. Para que el programa funcionara siempre se podría preguntar al usuario el año AÑOACTUAL.

## Ejercicio 7

Para pasar de un valor de segundos a horas, minutos y segundos:

	//...
    h = totalsegundos/3600;
    m = (totalsegundos%3600)/60; //o también (totalsegundos/60)%60
    s = totalsegundos%60;
    //...

## Ejercicio 8

Dada una hora en formato hh:mm:ss tenemos que sumarle un segundo y volver a obtener la hora. Los pasos son los siguientes:

- Obtener el total de segundos (h*3600 + ...)
- Sumarle uno
- Pasar el total de segundos a horas, minutos y segundos como en el ejercicio 7
- A diferencia del ejercicio 7, ahora podría pasar que saliera una hora mayor que 23. Para evitarlo (si la hora es 24 debería ser 0) haremos h = h%24.

## Ejercicio 9

Este ejercicio se puede resolver de dieferentes maneras. Una posible, expresada en pseudocódigo sería:

	Si es una letra
		imprimir "es una letra"
		Si es una vocal
			imprimir "es una vocal"
			imprimir "no es una consonante"
		Si no
			imprimir "no es una vocal"
			imprimir "es una consonante"

		Si es una minúscula
			imprimir "No es una mayúscula"
			imprimir "Es una minúscula"
		Si no
			imprimir "Es una mayúscula"
			imprimir "No es una minúscula"

		imprimir "No es un dígito"
		imprimir "El caracter con la capitalizacion invertida es..."
	Si no
		imprimir "no es una letra"
		imprimir "no es una vocal"
		imprimir "no es una consonante"
		imprimir "No es una mayúscula"
		imprimir "No es una minúscula"
		Si es un dígito
			imprimir "Es un dígito"
		Si no
			imprimir "No es un dígito"

Para saber si un carácter es una letra podemos hacer lo siguiente:

	 if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')

Para saber si una letra es una vocal no queda otra que analizar todos los casos:

	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'U' ||
				c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u')

Para saber si es minúscula:

	 if (c >= 'a' && c <= 'z')

Para invertir la capitalización, si la letra es minúscula la pasaremos a mayúscula restándole ('a'-'A') y si es mayúscula sumándole ('a'-'A').


## Ejercicio 10

El usuario habrá introducido "T float float", "C float" (o con la t y la c minúsculas). Para analizarlos usaremos múltiples scanf de la siguiente manera:

	//...
    printf("Introduzca la descripcion de la figura: ");
    scanf("%c ", &desc);
    if (desc == 't' || desc == 'T')
    {
        scanf("%f %f%*c", &base, &altura);
        area = base*altura/2;
        //...

## Ejercicio 11

El pseudocódigo para calcular si un año es bisiesto es:
 
	(es múltiplo de 4 y no de 100) o (es múltiplo de 400)

Para saber si a es múltiplo de b en C: a%b==0

