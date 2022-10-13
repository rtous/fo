# Desarrollo del proyecto paso a paso

## Versión 0.1

Escribid un programa wordle.c que muestre un tablero NUM_FILAS x NUM_LETRAS_PALABRA tal y como aparece en el ejecutable de ejemplo. En esta versión dentro de cada casilla mostrará simplemente la letra A. Consideraciones:

- Habrá que usar los ficheros colores.c y colores.h para poder mostrar negritas.
- Cread una función "imprimir_tablero" en vez poner todo el código dentro del main.

## Versión 0.2 

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

## Versión 0.3

Extended wordle.c para que, en vez de guardar solo un char en cada casilla, guade un struct con los campos letra (el char) y tipo (un entero que nos servirá para indicar de qué color se mostrará cada casilla). Crearemos dos nuevos ficheros:

	casilla.h
	casilla.c

En casilla.h pondremos:
	- el typedef struct de un nuevo tipo t_casilla y sus dos campos
	- #define para los diferentes tipos de letra (TIPO_VACIA, TIPO_LETRA_Y_POSICION, TIPO_LETRA_OK, TIPO_LETRA_KO)
	- la declaración de tres funciones: inicializar_casilla, poner_letra_en_casilla e imprimir_casilla.

En wordle.c deberemos añadir un #include de casilla.h y también tendremos que modificar la declaración de la matriz casillas y de todas las funciones que operan con ella.

 
