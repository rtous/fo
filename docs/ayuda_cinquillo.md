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
		imprimir_carta(cartas[j]);
	}
	printf_reset_color();
	printf("\n");
}
```

Vostoros tenéis que:

- Crear los ficheros carta.c y carta.h. 
- En carta.h definiréis las constantes PAL_OROS, etc. Y el tipo t_carta con información del palo y el número.
- En carta.h también incluiréis la declaración de la función:
```
	void imprimir_carta(t_carta carta);	
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
	printf_reset_color();
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
	printf_reset_color();
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
La función genera enteros pseudoaleatorios entre 0 y max. Mediante esta función podéis ir sacando cartas de la baraja (max sería el número de cartas que todavía quedan en la baraja). Cada vez que saquéis una carta debéis restar 1 al campo de t_baraja que contiene el número de cartas que quedan.
- La librería baraja.c/baraja.h también incluye la función inicializar_azar() que hay que llamar al princio del programa (ya os lo he añadido en el main de más arriba). Esta función utiliza el reloj del ordenador y es necesaria para que los números pseudoaleatorios que luego genera no sean siempre los mismos.
- Añadir a cinquillo.c includes de baraja.h y azar.h.
- Deberéis compilar con:
```
	gcc cinquillo.c colores.c carta.c baraja.c azar.c -o cinquillo
```

