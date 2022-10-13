# Desarrollo del proyecto paso a paso

## Versión 0.1 (descargar demo [linux](wordle_v0.1), [windows](wordle_v0.1.exe) o [mac](wordle_v0.1_mac))

Escribid un programa wordle.c que (sin mostrar menús ni nada) ssolo muestre un tablero NUM_FILAS x NUM_LETRAS_PALABRA tal y como aparece en el ejecutable de ejemplo. En esta versión dentro de cada casilla mostrará simplemente la letra A. Consideraciones:

- Habrá que usar los ficheros colores.c y colores.h para poder mostrar negritas. Deberéis poner un #include de colores.h y al compilar deberéis compilar wordle.c junto con colores.c (podeís hacer gcc *.c -o wordle).
- Cread una función "imprimir_tablero" en vez poner todo el código dentro del main.
<!-- --------------------------------------------- -->

## Versión 0.2 (descargar demo [linux](wordle_v0.2), [windows](wordle_v0.2.exe) o [mac](wordle_v0.2_mac))

Extended wordle.c para que rellene cada fila del tablero con una palabra introducida por el usuario. El pseudocódigo podría ser algo así:

	int main() {
		char palabra[NUM_LETRAS_PALABRA];
		char casillas[NUM_FILAS][NUM_LETRAS_PALABRA];
		int num_intento = 0; 

		inicializar_tablero(casillas);
		do {
			imprimir_tablero(casillas, num_intento);
			pedir_palabra(palabra);
			poner_palabra(casillas, palabra, num_intento);
			num_intento++;
		} while (num_intento < NUM_FILAS);
		imprimir_tablero(casillas, num_intento);
	}

Las funciones programadlas de momento en el mismo wordle.c antes del main o dará error. En esta versión no se analiza la palabra que entra el usuario, simplemente se introduce en casillas. Las funciones harán lo siguiente:

- inicializar_tablero: pone un ' ' en cada casilla.
- imprimir_tablero: Ya la teníamos de la versión anterior, imprime el tablero.
- pedir_palabra: Pide una palabra al usuario y la guarda en "palabra".
- poner_palabra: Pone "palabra" en la fila "num_intento" de "casillas".

## Versión 0.3 (aquí no hay demo ya que se vería algo parecido a la 0.2)

Extended wordle.c para que, en vez de guardar solo un char en cada casilla, guade un struct con los campos letra (el char) y tipo (un entero que nos servirá para indicar de qué color se mostrará cada casilla). Crearemos dos nuevos ficheros:

	casilla.h
	casilla.c

En casilla.h pondremos:

- el typedef struct de un nuevo tipo t_casilla y sus dos campos (un char y un entero).
- un #define para cada tipo de letra (TIPO_VACIA, TIPO_LETRA_Y_POSICION, TIPO_LETRA_OK, TIPO_LETRA_KO).
- la declaración de tres funciones: inicializar_casilla (inicializará carácter=' ' y tipo=TIPO_VACIA), poner_letra_en_casilla (recibe un char y un entero y los asigna a los dos campos de casilla) e imprimir_casilla (en función del tipo muestra el carácter con el color apropiado, mirad colores.h).

En wordle.c deberemos añadir un #include de casilla.h y también tendremos que modificar la declaración de la matriz casillas:

	t_casilla casillas[NUM_FILAS][NUM_LETRAS_PALABRA];

Deberéis cambiar la cabecera de las funciones inicializar_tablero, imprimir_tablero y poner_palabra para que utilicen la nueva declaración de casillas. También deberéis modificar su código para que en vez de trabajar directamente con el contenido de casillas como antes ahora hagan llamadas a las funciones inicializar_casilla, poner_letra_en_casilla e imprimir_casilla. 

En esta versión tampoco se analiza la palabra que entra el usuario, haced que muestre todas las letras con el tipo TIPO_LETRA_KO (el de letra incorrecta, que muestra en gris).


## Versión 0.4 (descargar demo [linux](wordle_v0.4), [windows](wordle_v0.4.exe) o [mac](wordle_v0.4_mac))

En está versión introduciremos una palabra solución y cambiaremos la función "poner_palabra" para que analice las coincidencias que hay entre la palabra entrada por el usuario y la palabra solución. No comprobaremos todavía si ha ganado o ha perdido, solo pintaremos las letras con los colores correctos. Al main le añadiremos:

	char solucion[NUM_LETRAS_PALABRA] = {'A', 'R', 'B', 'O', 'L'};

NOTA: Como véis, en esta versión daremos un valor fijo a la solución.

Ahora a la función "poner_palabra" habrá que pasarle también la palabra solución de este modo (también tendréis que cambiar su declaración):

	poner_palabra(casillas, palabra, num_intento, solucion);

El código de "poner_palabra" ahora tendrá que hacer lo siguiente:

	for (i=0; i<NUM_LETRAS_PALABRA; i++) {
		//1) poner el carácter i en la posición correspondiente de casillas
		//2) Si el carácter i coincide con el carácter i de la solución poner tipo TIPO_LETRA_Y_POSICION_OK
		//3) Si no coincide, mirar todas las otras letras de la solución (en un for o un while) y si coincide con alguna poner tipo TIPO_LETRA_OK
		//4) Si no poned TIPO_LETRA_KO
	}

NOTA: Haciéndolo así, si en la palabra del usuario hay una letra repetida que aparece en la solución pero no en la posición correcta se mostrará todas las veces como TIPO_LETRA_OK. Así estará bien pero en la demo veréis que solo se muestra la primera como TIPO_LETRA_OK. Hacerlo de esa manera es más complicado y es opcional.


## Versión 0.5 (descargar demo [linux](wordle_v0.5), [windows](wordle_v0.54.exe) o [mac](wordle_v0.5_mac))

 En está versión introduciremos una palabra solución y cambiaremos la función "poner_palabra" para que analice las coincidencias que hay entre la palabra entrada por el usuario y la palabra solución. No comprobaremos todavía si ha ganado o ha perdido, solo pintaremos las letras con los colores correctos. Al main le añadiremos:
