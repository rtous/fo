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

