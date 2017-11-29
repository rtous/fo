# Desarrollo del proyecto Buscaminas Paso a Paso

## Paso 1: Datos y estructura del proyecto

En primer lugar decidiremos que tipos de datos usaremos y como estructuraremos el proyecto en diferentes ficheros. La información que tenemos que guardar es la siguiente:

- Hay un tablero de nfils x ncols casillas, no necesariamente cuadrado. 
- Como límite nfils será menor que una constante MAX_F=36 y ncols menor que una constante MAX_C=36.
- Para cada casilla habrá que guardar la siguiente información (NOTA: Podéis tener un diseño diferente a éste):
	- bomba: Contenido de una casilla: 0=Vacía, 1=Conteniene una mina.
	- estado: 0=DESTAPADA, 1=TAPADA, 2=MARCADA_MINA, 3=MARCADA_DUDA. 
	- num_minas_adyacentes: Número de minas en las 8 casillas adyacentes.
	- DISEÑOS ALTERNATIVO: En vez de guardar el estado se puede guardar directamente el carácter que hay que mostrar. En vez de precalcular al principio el número de minas adyacentes se puede ir calculando a medida que se levantan casillas.
- Para el tablero habrá que guardar la siguiente información:
	- nfils y ncols.
	- cas: Una matriz de MAX_F x MAX_C casillas (de las que únicamente usaremos nfils x ncols). 
	- num_minas: Número de minas. Inicialmente 0. 
	- cas_tapadas: Número de casillas tapadas. Inicialmente nfils * ncols. 
	- num_minas_marcadas: Número de minas marcadas. Inicialmente 0. 
	- ha_explotado: Si ya ha explotado una mina del tablero y por tanto el juego tiene que terminar (0=No ha explotado, 1=Sí ha explotado). Inicialmente 0.
	- tiempo_inicial: La hora inicial (tiempo de sistema en segundos), en la que el jugador levantó la primera casilla. Inicialmente 0. 
	- DISEÑOS ALTERNATIVO: Se puede guardar el número de minas levantadas en vez del de tapadas. Se puede hacer sin los campos ha_explotado ni tiempo_inicial.

Obviamente un posible diseño del programa consistiría en dos tipos de datos (typedef struct), uno para las casillas y uno para el tablero. La definición de estos tipos puede ser parecida a la del Ejercicio 6 de la Sesión 5 de laboratorio, pero con una matriz en vez de un vector. Conviene que para cada tipo tengamos un "módulo" (también llamado "librería") C diferente. Para cada tipo habrá un fichero .h con las declaraciones y un fichero .c con el código. Aparte, tendremos un programa principal al que podríamos llamar "buscaminas.c". Eso daría una composición de ficheros inicial:
```
	buscaminas.c
	casilla.c
	casilla.h
	tablero.c
	tablero.h
	colores.c
	colores.h
```

Se os proporcionan los ficheros [tablero.h](./buscaminas/tablero.h) y [casilla.h](./buscaminas/casilla.h) de la solución propuesta. No obstante, podéis utilizar diseños diferentes a los aquí propuestos y vuestros propios ficheros .h. También se os proporciona el fichero [buscaminas.tar](buscaminas.tar), que muestra como sería un proyecto completo. Lo podéis compilar haciendo:

	wget https://github.com/rtous/fo/raw/master/project_0708Q1_buscaminas/buscaminas.tar
	xvf buscaminas.tar
	cd buscaminas
	gcc buscaminas.c tablero.c casilla.c colores.c -o buscaminas

	
## Paso 2 Estructura del programa principal

Implementaremos primero una versión de la función main() dentro de buscaminas.c que haga únicamente lo siguiente:
```
	Mostrar menú de selección de tablero
	Inicializar el tablero (sin minas)
	Hacer...
		Mostrar el tablero
		Pedir jugada
	...mientras no haya terminado el juego 
```

El menú de selección de tablero (conviene tener una función para esto, por ejemplo "menu_que_inicializa_tablero" dentro de buscaminas.c) se mostrará únicamente una vez en cada ejecución del juego (a no ser que la opción introducida sea incorrecta):

```
Menu:
1) Tablero  8x 8	10 minas
2) Tablero 16x16	40 minas
3) Tablero 16x30	99 minas
4) Tablero personalizado
Que opcion eliges? [1-4]: 1
```

Si la opción es incorrecta se volverá a mostrar la pregunta "Que opcion eliges? [1-4]:". Si el usuario selecciona "Tablero personalizado":

```
Filas? [4-36]: 4
Columnas? [4-36]: 4
Minas? [1-7]: 5
```

Para inicializar el tablero conviene implementar una función a parte dentro de tablero.c que podría llamarse "inicializar_tablero" por ejemplo. Esta función debería hacer lo siguiente:

	- Inicializar nfils y ncols con las dimensiones del tablero.
	- Inicializar el resto de datos (num_minas, cas_tapadas, num_minas_marcadas, ha_explotado, tiempo_inicial) a cero. 
	- Inicializar todas las casillas del tablero como ocultas y sin mina. 
	- No se colocan las minas todavía ya que debe hacerse cuando el usuario levante la primera casilla (ya que ésta no debe contener mina).	

Para mostrar el tablero conviene implementar una función a parte dentro de tablero.c que podría llamarse "imprimir_tablero" por ejemplo. En esta primera versión el tablero tendrá el siguiente aspecto ('x' indica que la casilla está oculta): 

```
[00m:00s] | :-) | Minas marcadas: 0/40

 |0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F|
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
0|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
1|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
2|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
3|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
4|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
5|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
6|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
7|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
8|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
9|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
A|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
B|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
C|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
D|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
E|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
F|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

```
Olvidémonos de momento de la cabecera del tablero (el temporizador, el smiley y el número de minas marcadas). Para mostrar el contenido de una casilla conviene implementar una función dentro de casilla.c. que podría llamarse "imprimir_casilla" por ejemplo. En función de cada caso mostrará una cosa distinta:

- Levantada y no tiene mina: mostrarla vacía (un espacio en blanco).
- Levantada y no tiene mina pero tiene minas adyacentes: Se mostrará el número de minas adyacentes. Según el número se usará un color distinto (1=rojo, 2=verde, etc.), el que devuelva la función "printf_color(int color)" de colores.c para ese número.
- Levantada y tiene mina: mostrar un '*' de color rojo.
- No ha sido levantada ni marcada: mostrar 'x' de color blanco.
- Marcada como mina: mostrar '!' de color rojo.
- Marcada como dudosa: mostrar '?' de color amarillo.

Una vez mostrado el tablero, a continuación se pedirá la jugada de la siguiente manera:
	
```
	Acciones: '!' marcar, '?' marcar como dudosa, 'x' desmarcar, ' ' levantar. Introduce jugada [fca] (fila, columna, accion [!?x ]):

```
El jugador introducirá 2 coordenadas (para valores superiories a 9 se usaran las letras 'A'-'Z') seguidas de un caràcter que indicará una acción. Por ejemplo la jugada "34 " consiste en levantar la casilla (3,4). Convendría que en caso que las coordenadas no sean válidas se vuelva a pedir la jugada.


## Paso 3 Realizar jugada. Marcar casillas 

Vamos a añadir la realización de la jugada a nuestro pseudocódigo:

```
	Inicializar el tablero (sin minas)
	Hacer...
		Mostrar el tablero
		Pedir jugada
		Realizar jugada
	...mientras no haya terminado el juego 
```

Sería conveniente crear una función a parte para la realización de la jugada. Por ejemplo, se podría crear una función "realizar_jugada_en_tablero" dentro de tablero.c. 

Implementemos primero únicamente las jugadas de marcar o desmarcar casillas:

- Si la casilla que se quiere marcar ya ha sido levantada (estado==DESTAPADA) se ignora la jugada.
- Si se marca una casilla como mina hay que cambiar el estado de la casilla a MARCADA_MINA e incrementar el contador de minas marcadas.
- Si se marca una casilla como dudosa hay que cambiar el estado de la casilla a MARCADA_DUDA.
- Si desmarca una casilla hay que cambiar su estado a TAPADA (y decrementar el contador de minas marcadas si estaba marcada como mina).

## Paso 4 Realizar jugada / Levantar primera casilla / Distribuir minas

Durante la primera jugada de levantar casilla de la partida hay que realizar varias inicializaciones en el tablero, siendo la primera la distribución de las minas: 

```
Realizar jugada:
	Si marcar...
	Si levantar:
		Si primera vez:
			Distribuir minas
			...
		Levantar
```
Conviene para ello implementar una función dentro de tablero.c. que podría llamarse "distribuir_minas" por ejemplo. Esta función debe distribuir un número de minas determinado (num_minas) evitando que haya minas en la casilla seleccionada (x,y) o en sus adyacentes:

```
Repetir mientras no se hayan colocado num_minas:
	Se obtendrá un valor 'i' aleatorio de entre 0 y nfils-1 (como en el Ejercicio 14 de la Sesión 3 de laboratorio). 
	Se obtendrá un valor 'j' aleatorio de entre 0 y ncols-1.
	Si la posición (i,j) no tiene mina y no coincide con las coordenadas (x,y) de la primera casilla seleccionada ni sus adyacentes:
		Colocar una mina en (i,j) e incrementar el número de minas del tablero. 	
```

## Paso 5 Realizar jugada / Levantar primera casilla / Calcular el número de minas adyacentes de todas las casillas

Cuando se levanta una casilla es necesario conocer el número de minas que hay en sus casillas adyacentes. Este número debe mostrarse al jugador y además, si ninguna de las casillas adyacentes tiene minas (minas adyacentes = 0) podremos ya levantarlas todas. El cálculo del número de minas en casillas adyacentes se puede ir haciendo a medida que se va necesitando, o alternativamente se puede calcular al inicio del juego para todas las casillas. Aquí os proponemos hacerlo de esta segunda manera. Después de distribuir las minas en el tablero recorreremos el tablero y anotaremos cuantas minas adyacentes tienen todas las casillas sin mina:
```
Realizar jugada:
	Si marcar...
	Si levantar:
		Si primera vez:
			Distribuir minas
			Calcular el número de minas adyacentes de todas las casillas
		Levantar
```

Conviene implementarlo en una función dentro de tablero.c. que podría llamarse "num_minas_adyacentes_tablero" por ejemplo. El psudocódigo sería:

```
	Para cada casilla del tablero:
		Si la casilla no contiene mina calcular el número de minas adyacentes de la casilla (ver más abajo) y guardarlo en el campo "num_minas_adyacentes" de la tcasilla. 
```
Para recorrer las 8 casillas adyacentes de una casilla en (i,j), una manera conveniente de hacerlo es la siguiente:

- Recorrer con dos bucles 'for' la matriz de 8x8 casillas cuyo centro es la casilla que se está inicializando.
- Hay que evitar leer más allá de los márgenes del tablero.
- El bucle exterior iterará de MAX(i-1, 0) hasta MIN(i+1, nfils-1).
- El bucle interior iterará de MAX(j-1, 0) hasta MIN(j+1, ncols-1).

## Paso 6 Realizar jugada / Levantar casilla

Una vez tratado el caso de que se trate de la primera casilla, para toda casilla hay que hacer lo siguiente:

- Si la casilla no ha sido levantada todavía (estado>0) se levanta, se cambia su estado a DESTAPADA y se mira su contenido. 
- Si la casilla contiene mina se asigna 1 al campo "ha_explotado" de t_tablero.
- Si la casilla no tiene mina ni minas adyacentes procederemos a levantar automáticamente las casillas adyacentes (Paso 7).


## Paso 7 Levantar casillas automáticamente (versión básica)

Como ayuda al jugador, si éste levanta una mina cuyas casillas adyacentes no tienen minas, se levantarán de manera automática todas ellas. En resumen: 
```
Cuando el jugador levanta una casilla que no contiene mina:
	Se mira el número de minas en casillas adyacentes (num_minas_adyacentes)
	Si num_minas_adyacentes==0 se procederá a levantar automáticamente todas las casillas adyacentes (recorriéndolas como en el Paso 5)
```
No obstante, el juego real no se detiene aquí. Las casillas levantadas de manera automática también podrían tener cero minas adyacentes, y en ese caso convendría levantar sus casillas adyacentes también. Este proceso se puede ir repitiendo hasta que no quede sin levantar ninguna casilla adyacente a otra (levantada) que tenga num_minas_adyacentes==0. En este punto conviene no abordar esta complejidad, y completar una versión básica del programa. Una vez tengamos la versión básica funcionando podemos intentar implementar la manera de levantar casillas en cascada. Una manera elegante de resolver este problema es mediante una función recursiva, que se llame a sí misma. 

## Paso 8 Finalización del programa

Vamos a añadir al pseudocódigo del main() los elementos de finalización:
```
	Inicializar el tablero 
	Hacer...
		Mostrar el tablero
		Pedir jugada
		Realizar jugada
	...mientras no haya terminado el juego 
	Mostrar tablero con todas las minas visibles
	Mostrar mensaje de victoria o derrota
```

- El juego termina si el jugador levanta una casilla con mina o si levanta todas las casillas sin mina.
- En caso que levante una casilla con mina se hará lo siguiente antes de finalizar:
	- Se levantan todas las casillas del tablero (por ejemplo con una función levantar_todas en tablero.c) y se muestra al usuario. 
	- Se muestra un mensaje de "---> BOOOOOOOOMMMMM!!!!!! <---" y se acaba.
- En caso que se hayan levantado todas las casillas sin mina se mostrará un mensaje de "---> GANASTE!!!!!! <---" y se acaba.






