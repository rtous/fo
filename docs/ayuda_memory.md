# Desarrollo del proyecto (memory) paso a paso

A continuación se os dan algunas pistas sobre un posible camino a seguir para desarrollar el proyecto. Esta guía está pensada para aquellos que no sabéis por donde empezar o para resolver alguna duda concreta. No es obligatorio seguirla ni tampoco hacer las cosas como aquí se sugiere. Podéis coger alguna idea o ignorarla completamente. La evaluación de vuestro diseño e implementación se hará respecto a los criterios de evaluación publicados en Metacurs.

Recordad que la librería de colores (colores.h/colores.c) y la librería de números aleatorios (azar.h/azar.c) ya se os proporcionan hechas.

## Versión 1 (imprimir un tablero)

Escribid un programa memory.c que simplemente muestre un tablero como el del ejecutable de demo. Para esta versión el tamaño lo pondremos directamente en el código (4 filas y 3 columnas) y todas las cartas estarán tapadas:

```
    000 001 002 
   +---+---+---+
000| ? | ? | ? |
   +---+---+---+
001| ? | ? | ? |
   +---+---+---+
002| ? | ? | ? |
   +---+---+---+
003| ? | ? | ? |
   +---+---+---+
```

En el terminal las cartas tapadas se ven con fondo rojo. Para conseguirlo usaremos las funciones de colores.h.

El main (incompleto) podría ser algo así:

```c
#include <stdio.h>
#include "colores.h"

int main() {
	int nfil = 4;
	int ncol = 3;
	int f, c;

	limpiar_pantalla();
	//[...] Código para imprimir la cabecera con los números de columna:     000 001 002
	//[...] Código para imprimir el separador:    +---+---+---+

	for (f = 0; f < nfil; f++) {
		//[...] Código para imprimir el número de fila:  000|
		for (c = 0; c < ncol; c++) {
			cambiar_color_fondo(RED);
			cambiar_color_letra(BLACK);
			printf(" ? ");
			cambiar_color_fondo_default();
			printf("|");
		}
		//[...] Salto de línea y separador
	}
}
```

Fijaos en que después de imprimir cada carta se llama a `cambiar_color_fondo_default()`. Si no lo hacéis, el color se "arrastra" a todo lo que se imprima después.

*PISTA: Para imprimir un número con tres cifras rellenando con ceros (000, 001...) podéis usar `printf("%03d", f);`*

Vosotros tenéis que:

- Completar el código
- Compilar con:

```
gcc memory.c colores.c -o memory
```

## Versión 2 (almacenar el tablero en una matriz)

Para almacenar el tablero tendréis que definir dos nuevos tipos de dato a los que podéis llamar, por ejemplo, tcasilla y ttablero. De momento los podéis poner directamente encima del main.

Pensad que una casilla del tablero puede estar en tres situaciones distintas:

- Hay una carta tapada (se muestra ` ? ` con fondo rojo).
- Hay una carta destapada (se muestra la letra con fondo verde).
- Ya no hay carta porque se ha emparejado (se muestra vacía con fondo azul).

Para representarlo, tcasilla guardará la letra de la carta y un entero con el estado de la casilla, que solo puede tomar tres valores. Para que el código se entienda mejor, definiremos una constante para cada estado:

```c
#define MAX_SIZE_TABLERO 50

#define TAPADA 0
#define DESTAPADA 1
#define VACIA 2

typedef struct {
	char letra;  // letra de la carta (A..Z, a..z)
	int estado;  // TAPADA, DESTAPADA o VACIA
} tcasilla;

typedef struct {
	int ncol, nfil;  // número de columnas y filas que se usan realmente
	tcasilla tab[MAX_SIZE_TABLERO][MAX_SIZE_TABLERO];
	[...]
} ttablero;

int main() {
...
```

Más adelante añadiréis a ttablero el número de cartas que quedan en el tablero (ncartas). Os será muy útil para saber cuándo termina la partida.

Hecho esto podéis declarar e inicializar una variable tablero al principio del main. Para probar usaremos un tablero de 4 filas y 3 columnas (6 parejas) con casillas en los tres estados:

```c
int main() {
	ttablero tablero = 
		{	3,
			4,
			{
				{{'A',TAPADA}, {'B',VACIA}, {'C',TAPADA}},
				{{'D',TAPADA}, {'E',TAPADA}, {'F',DESTAPADA}},
				{{'A',TAPADA}, {'B',VACIA}, {'C',DESTAPADA}},
				{{'D',TAPADA}, {'E',TAPADA}, {'F',TAPADA}}
			}
		};
	[...]
```

Fijaos en que los valores se asignan a los campos por orden: el 3 va a ncol, el 4 a nfil y la matriz a tab. Por eso es importante que declaréis los campos en este mismo orden. Las casillas de la matriz que no aparecen en la inicialización se ponen a 0, pero no las usaremos.

Este tablero corresponde a:

```
    000 001 002 
   +---+---+---+
000| ? |   | ? |
   +---+---+---+
001| ? | ? | F |
   +---+---+---+
002| ? |   | C |
   +---+---+---+
003| ? | ? | ? |
   +---+---+---+
```

En el terminal, las casillas con ` ? ` se ven con fondo rojo, las dos casillas vacías (la pareja B, que ya se ha encontrado) con fondo azul y las letras F y C con fondo verde.

Vosotros tenéis que:

- Completar los tipos de datos.
- Adaptar el main para que use nfil y ncol guardados en la variable tablero.
- Borrar las variables nfil y ncol de la versión anterior.
- Modificar los printf para que cada casilla se imprima según su estado:
  * VACIA: tres espacios con fondo azul (BLUE).
  * TAPADA: ` ? ` con fondo rojo (RED) y letra negra (BLACK).
  * DESTAPADA: la letra con fondo verde (GREEN) y letra blanca (WHITE).
- Comprobar que el tablero se ve como en el ejemplo, con los tres colores.

*PISTA: Como el estado solo puede tomar tres valores, un `switch (casilla.estado)` queda muy claro.*

## Versión 3 (funciones)

Ahora pondremos el código para imprimir el tablero en funciones. Antes del main (y después de los typedef) cread las siguientes funciones:

```c
void imprimir_casilla(tcasilla c) {
	[...] código que imprime una casilla con el color que le toca según su estado
}

void imprimir_ralla_entre_filas(int ncol) {
	[...] código que imprime el separador    +---+---+---+
}

void imprimir_tablero(ttablero tablero) {
	[...] código que antes imprimía el tablero (llama a las otras funciones)
}

int main() {
	[...]
	imprimir_tablero(tablero);
}
```

Fijaos en que imprimir_tablero recibe el tablero por valor (sin `*`) porque solo lo consulta, no lo modifica.

Vosotros tenéis que:

- Completar el código de las funciones.
- Sustituir el código de impresión que teníais antes en el main por `imprimir_tablero(tablero);`

## Versión 4 (librerías)

Ahora tenemos todo el código en un único fichero, memory.c, pero es conveniente (y de hecho obligatorio para sacar la máxima nota) estructurarlo en librerías. Se puede hacer de diferentes maneras, pero una aproximación razonable es tener una librería para las casillas y otra para el tablero:

```
casilla.h   casilla.c
tablero.h   tablero.c
```

El fichero casilla.h conviene que tenga la siguiente estructura:

```c
#ifndef CASILLA_H
#define CASILLA_H

#define TAPADA 0
#define DESTAPADA 1
#define VACIA 2

[...] typedef de tcasilla

[...] cabecera de las funciones (imprimir_casilla)

#endif
```

El fichero tablero.h tendrá una estructura similar, pero como ttablero contiene casillas tiene que incluir casilla.h:

```c
#ifndef TABLERO_H
#define TABLERO_H
#include "casilla.h"

#define MAX_SIZE_TABLERO 50

[...] typedef de ttablero

[...] cabecera de las funciones (imprimir_tablero)

#endif
```

Las líneas `#ifndef`, `#define` y `#endif` evitan que un mismo .h se incluya dos veces (por ejemplo, si memory.c incluye casilla.h y tablero.h, y tablero.h también incluye casilla.h). Sin ellas el compilador os dará un error de tipo redefinido.

Los ficheros .c conviene que empiecen así:

```c
#include <stdio.h>
#include "casilla.h"
#include "colores.h"

[...] código funciones
```

Vosotros tenéis que:

- Mover el typedef de tcasilla y la función imprimir_casilla a casilla.h/casilla.c.
- Mover el typedef de ttablero y las funciones de impresión del tablero a tablero.h/tablero.c.
- Escribir en los .h solo las cabeceras de las funciones que se usen desde fuera. Las funciones auxiliares (como imprimir_ralla_entre_filas) pueden quedarse solo en el .c.
- En memory.c añadir:

```c
#include "tablero.h"
```

- Compilar ahora con:

```
gcc memory.c tablero.c casilla.c colores.c -o memory
```

- Comprobar que sigue funcionando como antes.

*NOTA: Esto es solo un diseño de ejemplo. Si queréis podéis hacer un diseño distinto.*

## Versión 5 (tamaño del tablero e inicialización de las cartas)

Hasta ahora el tablero tenía un tamaño fijo. En el ejecutable de demo se pregunta al usuario con cuántas parejas quiere jugar (entre 2 y 50) y a partir de ahí se calcula el número de filas y columnas. Añadid a tablero.h unas constantes:

```c
#define MIN_PAREJAS 2
#define MAX_PAREJAS 50
```

Y cread en tablero.c una función que se encargue de toda la inicialización:

```c
void inicializar_tablero(ttablero *tablero);
```

Fijaos en que ahora el tablero se pasa por puntero (`*`) porque la función lo tiene que modificar. Si lo pasáis por valor, los cambios se pierden al salir de la función. Para acceder a los campos dentro de la función usaréis `->`, por ejemplo `tablero->nfil`.

La función inicializar_tablero puede dividirse en dos partes (podéis hacer una función auxiliar para cada una):

**1) Calcular el tamaño del tablero.** Queremos que el tablero sea lo más "cuadrado" posible. Una forma de hacerlo sin usar sqrt():

- ncartas = nparejas * 2
- Calcular la raíz cuadrada entera de ncartas: empezad con un entero r=1 y id incrementándolo mientras (r+1)*(r+1) <= ncartas.
- ncol es el divisor de ncartas más grande que sea <= r: empezad con ncol=r y id restando 1 mientras ncartas % ncol != 0.
- nfil = ncartas / ncol

Como ncartas siempre es par, el bucle siempre termina como muy tarde en ncol=2. Algunos ejemplos para comprobar vuestro código:

| Parejas | Cartas | Tablero (filas x columnas) |
|---------|--------|----------------------------|
| 2       | 4      | 2x2                        |
| 3       | 6      | 3x2                        |
| 5       | 10     | 5x2                        |
| 6       | 12     | 4x3                        |
| 8       | 16     | 4x4                        |
| 10      | 20     | 5x4                        |
| 18      | 36     | 6x6                        |
| 50      | 100    | 10x10                      |

**2) Poner las cartas.** Hay que poner cada letra dos veces y todas las cartas en estado TAPADA. Una forma sencilla es recorrer el tablero con un contador i que vaya de 0 a nparejas-1 y vuelva a empezar (`i = (i+1) % nparejas`). Así, con 6 parejas, las letras quedarían en orden A B C D E F A B C D E F (más adelante las mezclaremos). Como solo hay 26 letras mayúsculas, a partir de la pareja 27 usaremos minúsculas:

- Si i < 26 la letra es `'A' + i`
- Si i >= 26 la letra es `'a' + i - 26`

No olvidéis guardar también en el tablero el número de cartas (ncartas). A partir de esta versión ya no necesitáis la inicialización fija de la versión 2: la podéis borrar.

En el main quedaría:

```c
int main() {
	ttablero tablero;

	inicializar_tablero(&tablero);
	imprimir_tablero(tablero);
}
```

Vosotros tenéis que:

- Completar el código.
- Comprobar los tamaños de la tabla anterior.
- Comprobar que con más de 26 parejas aparecen las minúsculas (podéis destapar temporalmente todas las cartas para verlo).

## Versión 6 (mezclar las cartas)

Ahora mismo las cartas están siempre en el mismo orden, así que el juego no tiene mucha gracia. Para mezclarlas usaremos la librería azar.h que se os proporciona:

- `inicializar_azar()` se llama una sola vez al principio del main.
- `numero_al_azar(max)` devuelve un entero entre 0 y max-1.

Una forma sencilla de mezclar es recorrer todas las casillas e intercambiar cada una con otra casilla escogida al azar. Para escoger la casilla al azar podéis generar un número entre 0 y ncartas-1 y convertirlo en fila y columna:

```c
num_azar = numero_al_azar(tablero->ncartas);
f2 = num_azar / tablero->ncol;
c2 = num_azar % tablero->ncol;
```

Para el intercambio conviene añadir a casilla.h/casilla.c la función:

```c
void intercambiar_casillas(tcasilla *c1, tcasilla *c2);
```

Recibe punteros porque tiene que modificar las dos casillas. La llamada sería algo así:

```c
intercambiar_casillas(&tablero->tab[f1][c1], &tablero->tab[f2][c2]);
```

*PISTA: Mientras hacéis pruebas es muy útil saber dónde está cada carta. Podéis imprimir el tablero destapado justo después de mezclarlo (y borrar ese código al final). También podéis cambiar en azar.c el `srand(time(NULL))` por `srand(0)` para que las cartas salgan siempre en el mismo sitio en cada ejecución.*

Vosotros tenéis que:

- Añadir intercambiar_casillas a la librería casilla.
- Añadir una función mezclar_tablero en tablero.c y llamarla al final de inicializar_tablero.
- Llamar a inicializar_azar() al principio del main.
- Compilar ahora con:

```
gcc memory.c tablero.c casilla.c colores.c azar.c -o memory
```

## Versión 7 (bucle de juego con un jugador: realizar_jugada)

Vamos ahora a hacer que se pueda jugar. De momento con un único jugador y sin puntuación. El bucle de juego en el main sería:

```c
int main() {
	ttablero tablero;

	inicializar_azar();
	inicializar_tablero(&tablero);

	while (quedan_cartas(tablero)) {
		imprimir_tablero(tablero);
		realizar_jugada(&tablero);
	}
	printf("PARTIDA FINALIZADA\n");
}
```

Añadid a tablero.h/tablero.c las funciones:

```c
int quedan_cartas(ttablero tablero);
void realizar_jugada(ttablero *tablero);
```

quedan_cartas es muy sencilla si guardáis en el tablero el número de cartas que quedan por emparejar (ncartas).

Para guardar la posición de una carta conviene definir un nuevo tipo en tablero.h:

```c
typedef struct {
	int fil, col;
} tposicion;
```

En la función realizar_jugada pondremos:

- El código para preguntar la primera carta, con las comprobaciones:
  1. La fila y la columna están dentro del rango.
  2. La carta de esa casilla está TAPADA (no está VACIA porque ya se ha emparejado).
- Destapar la primera carta (estado DESTAPADA) y volver a imprimir el tablero.
- El código para preguntar la segunda carta, con las mismas comprobaciones. Fijaos en que la comprobación 2 también evita que se escoja dos veces la misma carta, porque la primera ya está DESTAPADA.
- Destapar la segunda carta y volver a imprimir el tablero.
- Comprobar si las dos cartas son pareja (podéis añadir a la librería casilla una función `int son_parejas(tcasilla c1, tcasilla c2);`):
  * Si son pareja: las dos casillas pasan a estado VACIA y se resta 2 a ncartas.
  * Si no son pareja: las dos cartas vuelven a estado TAPADA.

Para leer una posición con el formato de la demo (por ejemplo `1-0`) podéis usar:

```c
scanf("%d%*c%d%*c", &pos.fil, &pos.col);
```

El `%*c` lee un carácter y lo descarta. El primero se come el guión y el segundo el salto de línea que queda al pulsar enter. Las comprobaciones las podéis hacer con un do-while que repita la pregunta mientras la posición no sea válida.

Fijaos en que imprimir_tablero limpia la pantalla. Si después de destapar la segunda carta el programa vuelve directamente al bucle del main, el jugador no tendrá tiempo de ver la carta. Por eso en la demo se muestra un mensaje y se espera a que el usuario pulse enter:

```c
printf("Pulse <enter> para seguir jugando\n");
scanf("%*c");
```

Vosotros tenéis que:

- Completar el código.
- Jugar una partida completa con pocas parejas (2 o 3) y comprobar que el programa termina cuando se han emparejado todas las cartas.
- Probar a introducir posiciones incorrectas (fuera del tablero, casillas vacías, la misma carta dos veces) y comprobar que se vuelve a preguntar.

## Versión 8 (jugadores)

El juego tiene que permitir jugar entre 1 y 4 jugadores por turnos. Cada vez que un jugador consigue una pareja suma un punto y vuelve a jugar. Si falla, el turno pasa al siguiente jugador.

Para guardar esta información cread una nueva librería:

```
jugadores.h   jugadores.c
```

En jugadores.h definiremos dos tipos (uno para un jugador y otro para todos los jugadores de la partida):

```c
#define MAX_NOM 20
#define MAX_JUGADORES 4

typedef struct {
	[...] nombre del jugador (string de MAX_NOM+1 caracteres)
	[...] puntos
} tjugador;

typedef struct {
	[...] número de jugadores
	[...] vector de tjugador
	[...] turno (índice del jugador que juega, entre 0 y njugs-1)
} tjugadores;
```

Y las funciones:

```c
void inicializar_jugadores(tjugadores *js);
void imprimir_info_jugadores(tjugadores js);
void pasar_turno(tjugadores *js);
```

- inicializar_jugadores pregunta el número de jugadores (entre 1 y MAX_JUGADORES) y el nombre de cada uno, pone los puntos a 0 y escoge al azar quién empieza.
- imprimir_info_jugadores muestra la puntuación de cada jugador debajo del tablero.
- pasar_turno avanza al siguiente jugador. Después del último vuelve al primero. Con el operador % se puede hacer en una sola línea.

Para leer un nombre que puede contener espacios (por ejemplo "Ana Pi") no os sirve `%s`, ya que se para en el primer espacio. Podéis usar:

```c
scanf("%[^\n]%*c", js->jugs[i].nom);
```

`%[^\n]` lee todo hasta el salto de línea y `%*c` descarta el salto de línea.

*CUIDADO: Si justo antes habéis leído un número con `scanf("%d", ...)`, el salto de línea se queda en el buffer y el siguiente `%[^\n]` leerá una cadena vacía. Por eso conviene leer los números con `scanf("%d%*c", ...)`.*

Como ahora realizar_jugada tiene que sumar puntos y pasar el turno, necesita recibir también los jugadores:

```c
void realizar_jugada(ttablero *tablero, tjugadores *js);
```

Para que tablero.h conozca el tipo tjugadores tendréis que añadir `#include "jugadores.h"` en tablero.h.

El bucle del main quedaría:

```c
	while (quedan_cartas(tablero)) {
		imprimir_tablero(tablero);
		imprimir_info_jugadores(js);
		realizar_jugada(&tablero, &js);
	}
```

Vosotros tenéis que:

- Crear la librería jugadores e implementar las funciones.
- Mostrar al principio de cada jugada quién tiene el turno (en la demo se muestra con fondo amarillo).
- Modificar realizar_jugada para que sume un punto al jugador si consigue pareja o pase el turno si no.
- Compilar ahora con:

```
gcc memory.c tablero.c casilla.c jugadores.c colores.c azar.c -o memory
```

## Versión 9 (final de partida y ganadores)

Cuando ya no quedan cartas hay que mostrar el tablero final y el ganador. Cuidado: puede haber empate entre varios jugadores, y en ese caso hay que mostrarlos todos.

Añadid a la librería jugadores la función:

```c
void mostrar_ganadores(tjugadores js);
```

Una forma sencilla de hacerla es con dos recorridos del vector de jugadores:

1. Buscar la puntuación máxima.
2. Mostrar todos los jugadores que tengan esa puntuación.

Vosotros tenéis que:

- Implementar mostrar_ganadores y llamarla al final del main.
- Probar una partida con 2 jugadores y 2 parejas en la que cada uno consiga una pareja, para comprobar que se muestran los dos ganadores.

## Troubleshooting

- ld: symbol(s) not found / undefined reference (error del linker): no se ha incluido el .c de alguna librería en el comando gcc.
- error: redefinition of typedef / conflicting types: falta el `#ifndef ... #define ... #endif` en algún .h.
- error: unknown type name 'tjugadores' en tablero.h: falta el `#include "jugadores.h"` en tablero.h.
- Los cambios que hago en una función no se guardan: estáis pasando el tablero (o los jugadores) por valor. Si la función tiene que modificarlo, pasadlo por puntero.
- Todo el texto sale de colores: falta llamar a `cambiar_color_fondo_default()` después de imprimir algo con color.
- El programa no espera a que escriba el nombre / se salta una pregunta: queda un salto de línea en el buffer de un scanf anterior. Usad `%*c` para descartarlo.
- Las cartas salen siempre en el mismo sitio: estáis usando `srand(0)` en azar.c (útil para pruebas, pero hay que volver a `srand(time(NULL))` al final).
