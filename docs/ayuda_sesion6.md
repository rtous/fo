# Ayuda para la sesión 6

## Ejercicio 1 

Para declarar e inicializar una matriz de enteros:

    int m1[5][4];

    for (i=0; i<5; i++)
        for (j=0; j<4; j++)
            m1[i][j]=1;

O también:

    int m1[5][4] = {[0 ... 4]={[0 ... 3]=1}};

En el caso del sudoku tenéis que inicializar uno a uno (y usar la constante):

    #define VACIA -1

    ...

    int sudoku[9][9]={{5,3,VACIA,VACIA,7,VACIA,VACIA,VACIA,VACIA},
                      {6,VACIA,VACIA,1,9,5,VACIA,VACIA,VACIA},
                      ...

Para declarar una matriz de datos de tipo tfracciones:
   
    tfraccion mat_frac[N][N];

Para acceder a un campo de un struct dentro de una matriz haríais por ejemplo:

          mat_frac[i][j].num=...

<!--          
## Ejercicio 2

Este ejercicio es laborioso. El algoritmo podría ser algo así:

	Mediante un for (de 0 a 9) imprimir ralla (+-+-+....) superior 
		Mediante un if, cambiar el color del "+" en las posiciones 2 y 5

	Mediante un for (de 0 a 9) recorrer todas las filas de la matriz
		Imprimir "|"
		Mediante un for (de 0 a 9) recorrer las columnas
			Imprimir valor en función o " " si es VACIA
			Imprimir "|" en negro o rojo (columnas 2 y 5)
		Mediante un for (de 0 a 9) 
			Si fila 2 o 5 simplemente imprimir "+-+-+-+-+-+-+-+-+-+" en rojo.
			Si no, mediante un for  imprimir lo mismo pero con el "+" rojo en las columnas 2 y 5. 
		Imprimir salto de línea.
-->

## Ejercicio 2

### apartado a

Para añadir la capital:

	int distancias[MAX_CAPITALES][MAX_CAPITALES] = {0, 1720, 456, 1845, 1473,1093, 1720, 0, 1272, 1965, 2399, 2322, 456, 1272, 0, 1468, 1280, 1054, 1845, 1965, 1468, 0, 1130, 1519, 1473, 2399, 1280, 1130, 0, 682, 1093, 2322, 1054, 1519, 682, 0};
    
 La lectura de las dos capitales la podéis hacer con un do-while (ya que hay que volver a preguntar si los id están fuera de rango):

	do
	{
	   printf("Introduce...
	   scanf(....
	} while (id capital 1 menor que cero || id capital 1 mayor que...);

### apartado b

Para leer el número de ciudades a visitar también hay que usar un do-while (por lo mismo de antes, hay que volver a preguntar si error):

	do 
	{
	   printf("Introduce el numero de ciudades a visitar: ");
	   scanf(... );
	} while(numero de ciudades válido);

Hay dos maneras de realizar este ejercicio. Podéis calcular la distancia a medida que se va leyendo el camino o podéis guardar el camino en un vector y luego recorrerlo para calcular la distancia. La idea del ejercicio es que lo hagáis de la segunda manera pero el enunciado es ambiguo y si lo hacéis de la primera estará bien también.

Lo hagáis como lo hagáis, una vez tengamos el tamaño del camino necesitaremos un bucle para ir leyendo los ids. No obstante, si se produce un error (id incorrecto) deberemos volver a preguntar todos los ids, por lo que el bucle tendrá que ir dentro de otro bucle. 

*NOTA: Una forma elegante de detener un bucle (por ejemplo si detectamos un id erróneo) es usar una variable de estado ERROR o algo similar. También se puede salir mediante una instrucción break.*

## Ejercicio 3

### apartado a

Este apartado no tiene ninguna dificultad en particular salvo el hecho de que hay una matriz dentro de un struct. Deberéis usar bucles do-while como antes para re-preguntar si el usuario entra mal las dimensiones. Para realizar la suma de las matrices las tendréis que recorrer mediante dos for anidados haciendo:

	msuma.mat[i][j]=m1.mat[i][j]+m2.mat[i][j];

### apartado b

La matriz será simétrica si (1) tiene el mismo número de filas que de columnas y (2) para todo (i,j) m1.mat[i][j]!=m1.mat[j][i]. Si se detecta que no es simétrica el programa debe terminar, no debe esperar a recorrer toda la matriz.

### apartado c

Para calcular la traspuesta simplemente hay que, para todo (i,j), hacer mtras.mat[i][j]=m1.mat[j][i];

### apartado d

La idea aquí es calcular primero los máximos y mínimos de cada fila y columna y meterlos en 4 vectores:

	unsigned int min_fils[N], min_cols[N], max_fils[N], max_cols[N];

Una vez hecho esto se recorre la matriz y para cada punto se comprueba si es punto de silla.

### apartado e

Para multiplicar dos matrices usaremos tres bucles for anidados.




     