# Desarrollo del proyecto paso a paso

## Versión 0.1 (descargar demo [linux](wordle_v0.1), [windows](wordle_v0.1.exe) o mac [mac](wordle_v0.1_mac))

Escribid un programa wordle.c que directamente (sin menús) muestre un tablero NUM_FILAS x NUM_LETRAS_PALABRA tal y como aparece en el ejecutable de ejemplo. En esta versión dentro de cada casilla mostrará simplemente la letra A. Consideraciones:

- Habrá que usar los ficheros colores.c y colores.h para poder mostrar negritas.
- Cread una función "imprimir_tablero" en vez poner todo el código dentro del main.

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

Las funciones las tendréis que programar en el mismo wordle.c antes del main o dará error.

## Versión 0.3 (aquí no hay demo ya que se vería algo parecido a la 0.2)

Extended wordle.c para que, en vez de guardar solo un char en cada casilla, guade un struct con los campos letra (el char) y tipo (un entero que nos servirá para indicar de qué color se mostrará cada casilla). Crearemos dos nuevos ficheros:

	casilla.h
	casilla.c

En casilla.h pondremos:
	- el typedef struct de un nuevo tipo t_casilla y sus dos campos
	- un #define para los diferentes tipos de letra (TIPO_VACIA, TIPO_LETRA_Y_POSICION, TIPO_LETRA_OK, TIPO_LETRA_KO)
	- la declaración de tres funciones: inicializar_casilla, poner_letra_en_casilla e imprimir_casilla.

En wordle.c deberemos añadir un #include de casilla.h y también tendremos que modificar la declaración de la matriz casillas:

	t_casilla casillas[NUM_FILAS][NUM_LETRAS_PALABRA];

Deberéis cambiar la cabecera de las funciones inicializar_tablero, imprimir_tablero y poner_palabra para que utilicen la nueva declaración de casillas. También deberéis modificar su código para que en vez de trabajar directamente con el contenido de casillas como antes ahora hagan llamadas a las funciones inicializar_casilla, poner_letra_en_casilla e imprimir_casilla. Para esta versión podéis hacer que muestre todas las letras con el tipo TIPO_LETRA_KO (el de letra incorrecta, que muestra en gris).

## Versión 0.4 


 
