# Desarrollo del proyecto Sokoban en 10 pasos

## FASE 1 (sin ficheros ni menú, habrá un almacén predeterminado especificado en el propio código)

### Paso 1: Estructura modular del proyecto y tipos de datos.

Vuestro proyecto no estará bien diseñado si lo programáis todo dentro de un único fichero. A parte de un programa principal (que podéis llamar sokoban.c), que conendrá la función main, conviene repartir las funcionalidades del proyecto entre diferentes "módulos" (también llamados "librerías"). Cada módulo tendrá un fichero .h con las declaraciones y un fichero .c con el código. 

Una forma de repartir las funcionalidades es alrededor de "objetos de datos", conjuntos de datos y funcionalidades que constituyen entidades independientes dentro de un programa. Por ejemplo, en el proyecto Sokoban tendría sentido tener un módulo "almacen", en el que incluyamos las definiciones de tipos, constantes y funciones relativas a un almacén de Sokoban. También podría ser conveniente definir un módulo para todo lo relativo una "casilla" del almacén. Eso daría la siguiente composición de ficheros inicial:

```
	sokoban.c
	almacen.c
	almacen.h
	casilla.c
	casilla.h
```
Cread de momento ficheros vacíos para sokoban.c, almacen.c, almacen.h, casilla.c y casilla.h.

Definid ahora, dentro de almacen.h y casilla.h, los tipos de datos necesarios (t_almacen y t_casilla) para guardar la información de un único almacén. Lo podéis hacer de manera similar a como se hacía en el Ejercicio 6 de la Sesión 5 de laboratorio, pero con una matriz en vez de un vector. Por ejemplo, en almacen.h podríais tener:

```
#define MAX_F			24
#define MAX_C			70

typedef struct {
	t_casilla cas[MAX_F][MAX_C];
	...
} t_almacen;
```

Y en casilla.h un tipo de datos que permita guaradar el estado de una casilla del almacén en un momento dado. 

```
typedef struct {
	...
} t_casilla;
```

### Paso 2: Leer un almacen y guardarlo en memoria.

En el fichero sokoban.c programaremos un main que únicamente llame a una función 'leer_almacen' de almacen.c (todavía no existe). En el main tendréis que declarar una variable de tipo t_almacen, que contendrá el almacén que se está jugando. Tendréis que pasarle la dirección de esta variable a leer_almacen para que le dé contenido. En almacen.c programaremos la nueva función:

```
	void leer_almacen(t_almacen *almacen)
```
Tendremos que añadir también la declaración de la función en almacen.h y añadir un include de "almacen.h" tanto en sokoban.c como en almacen.c. 

Esa función se limitará a leer un almacén declarado dentro de una variable local de 'leer_almacen' de la siguiente manera: 
```
t_plano tablero= {
		"######",
		"#    #",
		"#@ $ #",
		"#    #",
		"#   .#",
		"######",
		"; Very easy",
		""};
```
El tipo t_plano lo añadiremos a almacen.h:
```
	typedef char t_plano[MAX_FIL+2][MAX_COL]; /* plano+descripcion del almacen */
```

'leer_almacen' únicamente tendrá que recorrer la matriz de carácteres 'tablero' línea a línea hasta que se encuentre una línea vacía (cuyo primer carácter sea '\0'). Por cada línea no vacía leída tendrá que recorrer sus MAX_COL carácteres y modificar los campos del parámetro "almacen" como convenga. 

NOTA: Si en almacen.c hacemos un include de "almacen.h" y éste, a su vez, hace un include de "casilla.h", en almacen.c no hace falta hacer el include de "casilla.h" de nuevo. 

NOTA: Será necesario detectar si una línia es el nombre del almacén, para tratarla de manera diferente.

NOTA: Podéis distribuir la funcionalidad de leer_almacen en más funciones, tanto en almacen.c como en casilla.c si lo creéis conveniente.


### Paso 3: Mostrar un almacen guardado en memoria. 

A continuación añadid a almacen.c (y su correspondiente cabecera en almacen.h) la siguiente función:
```
	void mostrar_almacen(t_almacen almacen)
```

Esta función mostrará por pantalla un almacen guardado en memoria del mismo modo que lo hace el juego de demostración. 

NOTA: Podéis distribuir esta funcionalidad entre más funciones, tanto de almacen.c como de casilla.c si lo creéis conveniente.

IMPORTANTE: Será conveniente borrar toda la pantalla al principio de mostrar_almacen. Tenéis una función en la librería "teclas" para ello.

Podéis probar a llamar a mostrar_almacen desde el main de sokoban.c, después de la llamada a leer_almacen.


### Paso 4: Leer teclas. Bucle de juego

Una vez leído un almacén entraremos en lo que se denomina "bucle de juego" que consistirá en lo siguiente:

```
	repetir {
		mostrar estado del juego (mostrar_almacen en nuestro caso)
		esperar tecla 
		procesar tecla y cambiar estado
	}
```

Este bucle de juego lo tenéis que programar dentro del main, a continuación de haber leído un almacén. Para gestionar el teclado os proporcionamos la librería "teclas".


### Paso 5: Mover al jugador por el almacen

El efecto visual de movimiento del jugador en el almacén lo conseguiremos borrando la patalla y redibujando el almacén con el jugador en una nueva posición. Para ello, cuando el usuario pulse una de las teclas de movimiento, haremos lo siguiente:

* Modificar la casilla en la que se encuentra el jugador para indicar que ya no está allí.
* Modificar la casilla destino (dependerá de la tecla pulsada) para indicar que ahora contiene al jugador.

Como el bucle de juego borrará la pantalla y redibujará el almacén, veremos como el jugador se desplaza. Se asume que teníais guardada en alguna parte la posición que ocupa el jugador, sino tendréis que hacerlo.  

De momento podemos aceptar cualquier movimiento para probar si funciona. Más adelante tendremos que controlar si el movimiento es válido o qué otras consecuencias tiene.

### Paso 6: Completad la primera fase del juego (sin ficheros ni menú)

Añadid el código necesario para que se pueda jugar y para que el juego detecte cuando hemos ganado (cuando todas las CAJAS estén en GOLES). Comprobad que se controlan bien las diferentes situaciones, por ejemplo:

* Que no se pueda mover una CAJA sobre otra CAJA. 
* Que no se pueda mover una CAJA a una casilla de GOL en la que ya hay una CAJA.
* Etc.

## FASE 2 (ahora con ficheros)

### Paso 7: Leer un almacen de un fichero 

En sokoban.c haremos un include de fichero.h para poder utilizar las funciones y constantes de la librería 'fichero'. Al principio del main de sokoban.c abriremos el fichero "Easy.txt" mediante una llamada a abrir_fichero. Al final del main conviene cerrar el fichero llamando a cerrar_fichero. Ambas funciones ya están implementadas en la librería fichero. A continuación sustituiremos en el main la llamada a leer_almacen por una llamada a leer_almacen_fichero. En almacen.c programaremos la nueva función:

```
	void leer_almacen_fichero(FILE *f, t_almacen *almacen);
```

Tendremos que añadir también la declaración de la función en almacen.h. 

Aunque un fichero puede contener más de un almacén, conviene empezar limitándonos a leer el primer almacén del fichero de almacenes "Easy.txt". Para leer el primer almacén usaremos repetidamente la función de la librería fichero:

```
	int leer_linea_fichero(FILE *f, char linea[LONG_LINEA_FICHERO]);
```

'leer_almacen_fichero' únicamente tendrá que ir realizando llamadas a leer_linea_fichero mientras ésta devuelva LINEA_NO_VACIA (el final de nivel se señala con una línea vacía). Por cada línea no vacía leída habrá que analizar su primer carácter. Si se trata de un ';' la línea será el nombre del almacen y tendremos que copiar los LONG_NOMBRE_ALMACEN carácteres que contiene al campo correspondiente de nuestro tipo t_almacen. Si no se trata del nombre, la línea contendrá la información de una fila del almacén y tendremos que recorrer uno a uno sus LONG_LINEA_FICHERO carácteres y procesarlos como hacíamos en la versión sin ficheros. Las constantes LONG_NOMBRE_ALMACEN y LONG_LINEA_FICHERO están definidas en la librería fichero.


### Paso 8: Leer todos los almacenes de un fichero

Modificaremos el main() de sokoban.c para que, una vez jugado un almacén, vaya llamando a 'leer_almacen' repetidamente, hasta que no haya más almacenes por jugar. Podremos conocer esta circunstancia llamando a la función de la librería fiheros: 

```
	int es_fin_de_fichero(FILE *f);
```

NOTA: Si nos fijamos bien veremos que antes de que se detecte el final de fichero se realiza una última llamada a leer_almacen(), que no hace nada excepto leer la última línea vacía del fichero (el final de fichero también se indica con una línea vacía!). Cuando leemos esa última línia, leer_linea_fichero devuelve FINAL_DE_FICHERO en vez de LINEA_VACIA (pero nos da igual ya que solo la procesamos si devuelve LINEA_NO_VACIA). Después de que hayamos consumido esa última línea 'es_fin_de_fichero' devolverá 1. 

### Paso 9: Mostrar el menu

En sokoban.c programaremos la función:

```
	void menu();
```

Esta función preguntará al usuario qué fichero quiere abrir y lo abrirá. La llamaremos al principio del main() y únicamente una vez, ya que cuando se deja de jugar sobre un fichero el juego finaliza. Sustituirá el código para abrir el fichero que ya teníamos. 

El contenido del menú será el siguiente:

```
	Menu: Con que fichero de niveles quieres jugar?
	0) Yo introducire el nombre del fichero
	1) Original.txt	The 50 original levels from Sokoban plus the 40 from Extra.
	2) Easy.txt	Colection for testing purposes.
	3) 100Boxes.txt	This collection includes 10 small levels of 10 packages each.
	4) 696.txt	696 collection.
	Que opcion eliges? [0-4]:
```

NOTA: Mejor dejad la opción 0 para más adelante.

Para implementar el menú es recomendable utilizar la función de la librería preguntas:

```
	int preguntar_n_en_rango(char *s, int min, int max);
```

Esta función ya incluye un bucle que reitera la pregunta si el usuario selecciona una opción fuera de rango.
