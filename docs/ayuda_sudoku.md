# Desarrollo del proyecto (sudoku) paso a paso

## Versión 1 (imprimir un sudoku)

Escribid un programa sudoku.c que simplemente muestre un sudoku incompleto como el del ejecutable de demo. Para esta versión pondremos los valores directamente en el código (no los leeremos de un fichero todavía). Para probar pondremos un 0 en todas las celdas:
```
 |0 1 2|3 4 5|6 7 8|
-+-+-+-+-+-+-+-+-+-+
0|0 0 0|0 0 0|0 0 0|
1|0 0 0|0 0 0|0 0 0|
2|0 0 0|0 0 0|0 0 0|
-+-+-+-+-+-+-+-+-+-+
3|0 0 0|0 0 0|0 0 0|
4|0 0 0|0 0 0|0 0 0|
5|0 0 0|0 0 0|0 0 0|
-+-+-+-+-+-+-+-+-+-+
6|0 0 0|0 0 0|0 0 0|
7|0 0 0|0 0 0|0 0 0|
8|0 0 0|0 0 0|0 0 0|
-+-+-+-+-+-+-+-+-+-+

```

El main (incompleto) podría ser algo así:

```
#include <stdio.h>
#include "colores.h"

int main() {
	int tamanyo_total = 9;
	int tamanyo_region = 3; 
	int i, j;
	printf_color_negrita();
	//[...] Codigo para imprimir cabecera  |0 1 2|3 4 5|6 7 8|

	for (i = 0; i<tamanyo_total; i++) {
		if (i%tamanyo_region == 0) 
			//[...] Bucle para imprimir separador (si queréis lo podéis poner en una función) 
		//[...] Código para imprimir una fila de valores (incluye un bucle)
	}
	//[...] Codigo para imprimir separador (si queréis lo podéis poner en una función) 
	printf_reset_color();
}
```
Vostoros tenéis que:

- Completar el código
- Compilar con:
```
	gcc sudoku.c colores.c -o sudoku
```

## Versión 2 (almacenar el sudoku en una matriz)

Para almacenar los valores del sudoku tendréis que definir dos nuevos tipos de dato al los que podeís llamar, por ejemplo, t_sudoku y t_celda. De momento los podéis poner directamente encima del main:

```
typedef struct {
	[...]
} t_celda;

typedef struct {
	t_celda celdas[MAX_SIZE][MAX_SIZE];
	[...]
} t_sudoku;

int main() {
...
```
t_sudoku almacenará la matriz de celdas y también el tamaño del sudoku (9 en el ejemplo) y la región (3 en el ejemplo). t_celda almacenará el valor de cada celda y un booleano que indique si la celda es modificable por el usuario o no (predefinida). El valor de la celda conviene que sea un carácter ya que en los sudokus grandes usaremos letras también (0,1,2,3,4,5,6,7,8,9,A,B,C...).

Resultará conveniente que defináis algunas constantes al principio de sudoku.c:

```
#include <stdio.h>
#include "colores.h"

#define MAX_SIZE 36
#define TRUE 1
#define FALSE 0
...
```
Hecho esto podéis inicializar ya una variable sudoku en el main con los valores del sudoku de ejemplo:

```
t_sudoku sudoku = {
	{//celdas
		{{'5',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{'8',FALSE},{' ',TRUE},{' ',TRUE},{'4',FALSE},{'9',FALSE}},
		{{' ',TRUE},{' ',TRUE},{' ',TRUE},{'5',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{'3',FALSE},{' ',TRUE}},
		{{' ',TRUE},{'6',FALSE},{'7',FALSE},{'3',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{'1',FALSE}},			
		{{'1',FALSE},{'5',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE}},
		{{' ',TRUE},{' ',TRUE},{' ',TRUE},{'2',FALSE},{' ',TRUE},{'8',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE}},
		{{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{'1',FALSE},{'8',FALSE}},
		{{'7',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{'4',FALSE},{'1',FALSE},{'5',FALSE},{' ',TRUE}},
		{{' ',TRUE},{'3',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{'2',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE}},
		{{'4',FALSE},{'9',FALSE},{' ',TRUE},{' ',TRUE},{'5',FALSE},{' ',TRUE},{' ',TRUE},{' ',TRUE},{'3',FALSE}}
	},
	9,//tamanyo_total
	3,//tamanyo_region
};
```

Vostoros tenéis que:

- Completar los tipos de datos.
- Adaptar el main para que acceda a los valores de las celdas.
- Modificar los printf de las celdas para que trabajen con carácteres y no con números.
- Añadir lo necesario para que las celdas modificables se impriman sin negrita.

<!--

## Versión 2 (mostrar las cartas de los jugadores)

Escribid un programa cinquillo.c para que (sin mostrar menús ni nada) simplemente muestre las cartas de los jugadores (no las del mantel) con el aspecto del que aparece en el ejecutable de demo y termine. Para esta versión nos inventaremos unas cartas fijas para cada jugador. El main podría quedar así:
```
int main() {
	t_jugador jugadores[NUM_JUGS];
	jugadores[0].cartas[0].pal = PAL_OROS;
	jugadores[0].cartas[0].num = 1;
	...
	imprimir_jugadores(jugadores);
}
```

Vostoros tenéis que:

- Añadir a cinquillo.c las constantes NUM_JUGS y NUM_CARTAS_JUG. 
- Añadir a cinquillo.c la definición del tipo t_jugador que incluya el número de cartas que tiene, un vector de t_carta. 
- Añadir a cinquillo.c la función "imprimir_jugadores" que deberéis programar. 

*NOTA: Las constantes, typedef y métodos relativos a los jugadores podrían ir en una librería (e.g. jugadores.c/jugadores.h como la que hemos usado para las cartas. Aquí no os lo sugiero para no complicarlo. Lo podéis hacer si queréis, lo podéis hacer más adelante o podéis no hacerlo. És una decisión de diseño que deberéis tomar.*

## Versión 3 (repartir las cartas de una baraja)

Ahora vamos a modificar la versión anterior para que, en vez de fijar nosotros el contenido de las cartas de los jugadores, estas salgan de una "baraja". Lo demás lo dejaremos igual. El main pasaría a ser algo así:
```
int main() {
	t_jugador jugadores[NUM_JUGS];
	t_baraja baraja;
	crear_baraja(&baraja);
	inicializar_azar();
	for (int i = 0; i < NUM_JUGS; i++) {
		for(int j = 0; j < NUM_CARTAS_JUG; j++) {
			jugadores[i].cartas[j] = sacar_carta_baraja(&baraja);
		}
		jugadores[i].num_cartas = NUM_CARTAS_JUG;
	}
	imprimir_jugadores(jugadores);
}
```
Vostoros tenéis que:

- Crear los ficheros baraja.c y baraja.h. 
- En baraja.h definir t_baraja (almacena un vector de cartas y el número de cartas total que tiene la baraja). 
- En baraja.h también incluiréis la declaración de las funciones:
```
	void crear_baraja(t_baraja *p_baraja);
	t_carta sacar_carta_baraja(t_baraja * p_baraja);
```
- En baraja.c deberéis programar esas dos funciones. La función crear_baraja simplemente carga todas las cartas posibles en la baraja e inicializa el campo con el número de cartas totales (40). Tal vez sea conveniente definir las constantes NUM_NUMS = 10 y NUM_PALS = 4 en alguna parte (por ejemplo en carta.h). 
- La función sacar_carta_baraja ha de sacar una carta al azar. Para ello deberéis usar la librería azar.c/azar.h proporcionada que incluye la función:
```
int numero_al_azar(int max);

```
La función genera enteros pseudoaleatorios entre 0 y max-1. Mediante esta función podéis ir sacando cartas de la baraja (max sería el número de cartas que todavía quedan en la baraja). Cada vez que saquéis una carta debéis restar 1 al campo de t_baraja que contiene el número de cartas que quedan.
- La librería baraja.c/baraja.h también incluye la función inicializar_azar() que hay que llamar al princio del programa (ya os lo he añadido en el main de más arriba). Esta función utiliza el reloj del ordenador y es necesaria para que los números pseudoaleatorios que luego genera no sean siempre los mismos.
- Añadir a cinquillo.c includes de baraja.h y azar.h.
- Deberéis compilar con:
```
	gcc cinquillo.c colores.c carta.c baraja.c azar.c -o cinquillo
```
## Versión 4 (el mantel)

Ahora vamos a modificar la versión anterior para añadir la información del mantel, en el que los jugadores van depositando sus cartas. El mantel, que inicialmente está vacío, es esencialmente una matriz de cartas NUM_NUMSxNUM_PALS. Pero no hace falta guardar un campo t_carta para cada celda de la matriz ya que la posición en la matriz ya nos da la información del palo y el número. Podemos guardar simplemente booleanos.

Vostoros tenéis que:

- Añadid en el main de cinquillo.c la declaración del mantel:
```
int main() {
	int mantel[NUM_NUMS][NUM_PALS]; //vector de booleanos
	...
```
- Inicializad toda la matriz a FALSE.
- Programad (en el mismo cinquillo.c) la función:
```
void imprimir_mantel(char mantel[NUM_NUMS][NUM_PALS]); 
```
- Llamad a la función al final del main.

Si lo probáis os saldrá un mantel vacío. Para ver que todo funciona podéis modificar manualmente en el main alguna de las cartas antes de imprimir el mantel, por ejemplo:
```
mantel[0][0] = TRUE;
mantel[4][3] = TRUE;
mantel[9][3] = TRUE;
```

## Versión 5 (el bucle de juego)

Vamos ahora a extender cinquillo.c para que reiteradamente pregunte a todos los jugadores que carta quieren tirar (el bucle de juego). Empezemos por una versión simple, con un bucle infinito y todos los jugadores humanos. El bucle de juego, que iría al final del main, podría ser algo así:
```
do {
	for (int i = 0; i < NUM_JUGS; i++) {
		imprimir_jugadores(jugadores);
		imprimir_mantel(mantel);
		printf("\nTurno de JUG#%d:\n", i);
		printf("\nQue tirada realizas? ");
		int opcion;
		scanf("%d%*c", &opcion);
	}
} while (1==1);	
```
Ahora hay un scanf para que veáis cual es la idea, pero tendremos que modificar esa parte.

## Versión 6 (pedir al usuario qué carta quiere jugar)

En el bucle de juego reemplacemos las algunas líneas de prueba que hemos puesto antes por una llamada a una función "pedir_carta" del siguiente modo:
```
do {
	for (int i = 0; i < NUM_JUGS; i++) {
		imprimir_jugadores(jugadores);
		imprimir_mantel(mantel);
		printf("\nTurno de JUG#%d:\n", i);
		int puede_jugar = pedir_carta(i, jugadores, mantel, &carta_seleccionada);
	}
} while (1==1);	
```
Tendréis que añadir la declaración la carta seleccionada por el jugador:
```
int main() {
	...
	t_carta carta_seleccionada;
	...
```
- Programad (en el mismo cinquillo.c) la función pedir_carta, que muestra al usuario las posibles cartas y le pregunta cual escoge. Sería algo así:
```
int pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], char mantel[NUM_NUMS][NUM_PALS], t_carta *carta_selecccionada) {
	int opcion;
	t_cartas posibles;
	cartas_posibles(num_jugador, jugadores, mantel, &posibles);
	//Mostrar las cartas posibles.
	//Si hay posibles pedir al usuario la opción deseada. 
	//Poner la carta en carta_selecccionada (si hay posibles)
	//Devuelve TRUE si había alguna carta posible
}
```
En caso de que el usuario introduzca una opción <=0 o mayor que el número de cartas que hay en "posibles" se deberá repetir la pregunta. Conviene poner el análisis de las cartas posibles en una función a parte (por ejemplo "cartas_posibles"):
```
void cartas_posibles(int num_jugador, t_jugador jugadores[NUM_JUGS], char mantel[NUM_NUMS][NUM_PALS], t_cartas_posibles *posibles) {
	posibles->num_cartas = 0;
	for (int i = 0; i < jugadores[num_jugador].num_cartas; i++) {
		if (es_posible(jugadores[num_jugador].cartas[i], mantel)) {
			//Añadimos la carta del jugador a "posibles".
			//Incrementamos el número de cartas que hay en "posibles".
		}
	}
}
```
Esta función llama a "es_posible", que dada una carta devuelve TRUE si se pude poner en el mantel:
```
int es_posible(t_carta carta, char mantel[NUM_NUMS][NUM_PALS]) {
	//Devolverá TRUE si se cumple alguna de las siguintes condiciones:
	// El identificador de la figura es un 4 (figura 5).
	// El identificador de la figura es mayor que cero hay una carta en el mantel para ese palo y una figura con identificador+1.
	//El identificador de la figura es menor que NUM_NUMS-1 y hay una carta en el mantel para ese palo y una figura con identificador-1. 
}
```

## Versión 7 (aplicar la jugada seleccionada)

Extendamos nuestro bucle de juego para que se aplique la jugada seleccionada por el usuario:
```
do {
	for (int i = 0; i < NUM_JUGS; i++) {
		imprimir_jugadores(jugadores);
		imprimir_mantel(mantel);
		printf("\nTurno de JUG#%d:\n", i);
		int puede_jugar = pedir_carta(i, jugadores, mantel, &carta_seleccionada);
		if (puede_jugar)
			poner_carta(carta_seleccionada, i, jugadores, mantel);
	}
} while (1==1);
```
- Programad la función poner_carta. Por un lado pondrá a TRUE la posición del mantel correspondiente a la carta seleccionada. Por otro lado, eliminará la carta del jugador correspondiente. Esto último conviene ponerlo en una función a parte, "eliminar_carta_jugador":
```
void eliminar_carta_jugador(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS]);

void poner_carta(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS], char mantel[NUM_NUMS][NUM_PALS]);
```
La función "eliminar_carta_jugador" hará la típica eliminación de un elemento de un vector.

## Versión 8 (detectar final del juego)

Extendamos nuestro bucle de juego para que el juego termine:
```
int final = FALSE;
	do {
		for (int i = 0; i < NUM_JUGS && !final; i++) {
			imprimir_jugadores(jugadores);
			imprimir_mantel(mantel);
			printf("\nTurno de JUG#%d:\n", i);
			int puede_jugar = pedir_carta(i, jugadores, mantel, &carta_seleccionada);
			if (puede_jugar)
				final = poner_carta(carta_seleccionada, i, jugadores, mantel);
			if (final) {
				imprimir_jugadores(jugadores);
				imprimir_mantel(mantel);
				printf_color_negrita();
				printf("\nHA GANADO EL JUGADOR #%d.\n\n", i);
				printf_reset_color();
			}
		}
	} while (!final);
```
Vosotros tenéis que modificar la función "poner_carta" para que devuelva TRUE si el jugador se ha quedado sin cartas. 

## Versión 9 (poner el 5 de oros)

Hasta ahora hemos ignorado el hecho de que el juego lo empieza el jugador que tiene el cinco de oros. Para tenerlo en cuenta llamaremos a una nueva función, "poner_5_oros", antes del bucle de juego.
```
int jugador_que_empieza = poner_5_oros(jugadores, mantel);

//bucle de juego
int final = FALSE;
do {
	for (int i = jugador_que_empieza; i < NUM_JUGS && !final; i++) {
		...
	}
	jugador_que_empieza = 0;
} while (!final);
```
La función "poner_5_oros" buscará que jugador tiene esa carta, llamará a la función "poner_carta" y devolverá la posición del siguiente jugador (el que empieza a jugar).

## Versión 10 (jugadores no humanos)

Añadid al juego la pregunta inicial que hace en la demo sobre si hay un jugador humano (hasta ahora hemos asumido que todos lo eran). Deberéis realizar las modificaciones necesarias para que haya jugadores no humanos (simplemente seleccionaran la primera carta de las posibles). Una vez lo tengáis podéis introducir un tiempo de espera para que el usuario tenga tiempo de ver lo que han hecho los jugadores no humanos como sucede en la demo. Para ello usad la librería duerme.c/duerme.h.

-->