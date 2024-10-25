# Desarrollo del proyecto (cinquillo) paso a paso

## Versión 1 (imprimir un vector de cartas)

Escribid un programa cinquillo.c que (sin mostrar menús ni nada) simplemente muestre un vector de cartas como las que se muestran para cada jugador en el ejecutable de demo. Para esta versión nos inventaremos 3 cartas fijas. El main podría quedar así:

```
#include <stdio.h>
#include "carta.h"
#include "colores.h"

int main() {
	t_carta cartas[10] = {{2, PAL_OROS}, {1, PAL_BASTOS}, {10, PAL_OROS}};
	int num_cartas = 3;
	for(int j = 0; j < num_cartas; j++) {
		imprimir_carta(cartas[j].pal, cartas[j].num);
	}
	printf_reset_color();
	printf("\n");
}
```

Vostoros tenéis que:

- Crear los ficheros carta.c y carta.h. 
- En carta.h definiréis las constantes PAL_OROS, etc. Y el tipo t_carta con información del palo y el número.
- **CONSEJO: Seguramente dentro de t_carta guardaréis el palo como un código 0-4. El número o figura (que puede ser 1-7 y 10-12) lo podríais guardar directamente, pero puede resultar más conveniente guardar un identificador 0-11. Solo cuando tengáis que mostrarlo tendréis que mapear el identificador con la figura.** 

- En carta.h también incluiréis la declaración de la función:
```
	void imprimir_carta(int pal, int num);	
```

- En carta.c pondréis un include de carta.h y también el código del método imprimir_carta que deberéis programar usando la librería colores.
- Deberéis compilar con:
```
	gcc cinquillo.c colores.c carta.c -o cinquillo
```

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
- En baraja.c deberéis programar esas dos funciones. La función crear_baraja simplemente carga todas las cartas posibles en la baraja e inicializa el campo con el número de cartas totales (40). Tal vez sea conveniente definir las constantes NUM_NUMS = 10 y NUM_PALS = 4 en alguna parte (por ejemplo en carta.h). Una complicación es que no debéis añadir ni el 8 ni el 9.
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
	int mantel[NUM_NUMS][NUM_PALS];
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
<!--
### 4.2 Información de las cartas que se pueden poner

Recorriendo la matriz que representa el mantel es suficienta para saber qué cartas pueden poner los jugadores. No obstante, aquí os proponemos almacenar también esta información, aunque sea redundante, para hacer algunas acciones más eficientes en tiempo (y más fáciles de programar). Se puede guardar en una 

```
char mantel_proxima_carta[NUM_PALS][2];
```
-->   
## Versión 5 (el bucle de juego)

Vamos ahora a extender cinquillo.c para que reiteradamente pregunte a todos los jugadores que carta quieren tirar (el bucle de juego). Empezemos por una versión simple, con un bucle infinito y todos los jugadores humanos. Dejemos para más adelante también en análisis de qué cartas son posibles y simplemente mostremos como posibles todas las que tiene el jugador. El bucle de juego, que iría al final del main, podría ser algo así:
```
	do {
		for (int i = 0; i < NUM_JUGS; i++) {
			imprimir_jugadores(jugadores);
			imprimir_mantel(mantel);
			printf("\nTurno de JUG#%d:\n", i);
			carta_seleccionada = pedir_carta(i, jugadores, mantel);
			poner_carta(carta_seleccionada, jugadores, mantel);
		}
	} while (1==1);	
```
- Añadid en el main de cinquillo.c la declaración la carta seleccionada por el jugador:
```
int main() {
	...
	t_carta carta_seleccionada;
	...
```
- Programad (en el mismo cinquillo.c) las funciones :
```
t_carta pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], char mantel[NUM_NUMS][NUM_PALS]);

void poner_carta(t_carta carta, t_jugador jugadores[NUM_JUGS], char mantel[NUM_NUMS][NUM_PALS]);
```
La función pedir_carta muestra al usuario las posibles cartas y le pregunta cual escoge. Conviene poner el análisis de las cartas posibles en una función a parte (por ejemplo "cartas_posibles"). Para ello necesitamos crear un nuevo tipo t_cartas_posibles en cinquillo.c. Algo muy parecido a t_jugador, que incluya el número de cartas que tiene y un vector de t_carta. Una vez hecho eso la función pedir_carta puede empezar así:
```
t_carta pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], char mantel[NUM_NUMS][NUM_PALS]) {
	int opcion;
	t_cartas posibles;
	cartas_posibles(num_jugador, jugadores, mantel, &posibles);
	//Mostrar las cartas posibles.
	//Pedir al usuario la opción deseada.
	//Devolver la carta seleccionada.
}
```
De momento haced que la función cartas_posibles simplemente ponga en el parámetro "posibles" todas las cartas que tiene el jugador.

La función poner_carta ya la podéis programar, simplemente pondrá a TRUE la posición del mantel correspondiente a la carta seleccionada.

