# Desarrollo del proyecto paso a paso

## Versión 0.1 (mostrar el tablero)

Escribid un programa dominosa.c que (sin mostrar menús ni nada) solo muestre un tablero de 3 filas y 4 columnas con el aspecto del que aparece en el ejecutable de demo. Para esta primera versión usad una simple matriz de enteros inicializada por vosotros en el mismo código para el contenido de las casillas (sin conexiones entre casillas). Por ejemplo:

	int main() {
		int tablero[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 0, 1}};
		...

Consideraciones:

- Habrá que usar los ficheros colores.c y colores.h para poder mostrar colores y negritas (son diferentes a los del laboratorio).

- Deberéis poner un #include de colores.h y al compilar deberéis compilar dominosa.c junto con colores.c (podeís hacer gcc *.c -o dominosa).  

- Cread una función "imprimir_tablero" en vez poner todo el código dentro del main.

## Versión 0.2 (nuevo tipo tablero en vez de una matriz de ints)

Como queremos poder trabajar con tableros de diferentes tamaños nos convendrá guardar el número de filas y columnas en variables. Para tenerlo todo bien organizado crearemos un nuevo typedef struct llamado t_tablero en el que pondremos toda la información que de momento tenemos del tablero: la matriz de enteros, el número de filas y el número de columnas. Podéis llamar a los campos como queráis (por ejemplo casillas, num_filas y num_columnas). 

Podríamos poner la definición de t_tablero en dominosa.c pero será más elegante (principio de diseño de software "separation of concerns") poner todo lo relativo al tablero en una librería a parte. Crearemos dos nuevos ficheros:

	tablero.h
	tablero.c

En tablero.h pondremos:

- El typedef struct del nuevo tipo t_tablero. 
- La declaración de las funciones relativas al tablero, de momento imprimir_tablero.

En tablero.c pondremos:

- El código de las funciones relativas al tablero, de momento imprimir_tablero.

Deberéis cambiar la cabecera y el código de la función imprimir_tablero para que se adapte a la nueva declaración de tablero. Una vez hecho esto modificad dominosa.c para que utilice el nuevo tipo. Deberéis añadir un #include de tablero.h y también tendréis que sustituir la declaración de la variable tablero en el main (suponiendo que num_filas y num_columnas sean los dos primeros campos):

	t_tablero tablero = {3, 4, {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 0, 1}}};


Comprobad que el programa sigue funcionando con los nuevos cambios.

<!-- --------------------------------------------- -->

## Versión 0.3 (pedir la jugada al usuario)

Extended dominosa.c para que reiteradamente pida una nueva jugada al usuario. El esqueleto del código (para una versión que no termina nunca) podría ser algo así:

	int main() {
		t_tablero tablero = {3, 4, {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 0, 1}}};
	
		do {
			imprimir_tablero(tablero);
			realizar_jugada(&tablero);
		} while (1==1);
	}

Deberéis crear una nueva función realizar_jugada dentro de tablero.c (y añadir su cabecera a tablero.h). De momento haced que la función solo pida la jugada (tal y como muestra la demo), sin hacer nada con ella. 


<!-- --------------------------------------------- -->

## Versión 0.4 (conexiones entre casillas)

Para poder ejecutar la jugada del usuario os hace falta guardar de alguna manera las conexiones entre casillas (las fichas del dominó). Un ficha o conexión se compone de dos casillas contiguas (encima/debajo o izquierda/derecha). Hay diferentes maneras de guardar esa información y sois libres de optar por la que más os convenza. Una opción sería guardar las conexiones de algún modo en la misma matriz de casillas. En caso de que lo hagáis de ese modo (no es obligatorio) deberéis modificar la matriz que hay dentro de t_tablero para que en vez de almacenar enteros almacene structs de un nuevo tipo, t_casilla. Podéis definir t_casilla dentro de tablero.h o podéis crear una nueva librería (casilla.c y casilla.h) si pensáis que quedará mejor organizado (por ejemplo si hay funciones que trabajan a nivel de una casilla).

No se os da aquí pistas de qué información guardar dentro de t_casilla (a parte del entero que ya teníais). Ha de ser una información que permita saber con qué casilla está conectada cada casilla. 

Una vez tengáis una manera de guardar la información de las conexiones podéis amplicar el código de realizar_jugada para que cree una conexión nueva si es válida (si son dos casillas contiguas) o vuelva a preguntar en caso que no. Si alguna de las casillas que se intentan conectar ya estaban conectadas se deberían eliminar esas conexiones. 


<!-- --------------------------------------------- -->

## Versión 0.5 (fin de la partida)

Reemplazad el "while (1==1)" por un "while (!partida_terminada(tablero))" o algo así, y añadid la función partida_terminada a tablero.c y tablero.h. Esa función debe comprobar si se han conectado todas las fichas posibles. Por ejemplo si trabajamos con un número de dígitos posibles N = 3 (0, 1 y 2), hay que verificar que esten las fichas  0-0, 0-1, 0-2, 1-1, 1-2 y la 2-2 (el orden de los dígitos no importa). La manera de comprobarlo no es trivial y tenéis libertad de hacerlo como queráis. 


<!-- --------------------------------------------- -->

## Versión 0.6 (fichero)

Hasta ahora hemos trabajado con un tablero prefijado en el código. Vamos ahora a inicializar el tablero con los datos de un fichero, por ejemplo 2001.txt. Copiad en vuestro proyecto ese fichero y también el .c y .h de la librería para leer ficheros del material de proyecto que se os ha proporcionado. Cread una nueva función inicializar_tablero (en tablero.c y tablero.h) que, mediante llamadas a la librería, lea el contenido inicial del tablero de un fichero.



<!-- --------------------------------------------- -->

## Versión 0.7 (menú)

Finalmente extended dominosa.c para que muestre un menú como el de la demo.