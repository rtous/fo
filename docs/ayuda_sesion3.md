# Ayuda para la sesión 3

TIP: Recordad que con CTRL+C podéis abortar la ejecución (es conveniente saberlo especialmente ahora que trabajaremos con bucles).

## Ejercicio 1

Aquí se trata simplemente de copiar el código del enunciado y ver si coincide con lo que uno espera.   

## Ejercicio 2

Una dificultad del ejercicio es que el último número no debe tener una coma a la derecha. Se puede hacer de diferentes maneras, pero una solución eficiente y compacta sería:

    printf("Secuencia de numeros: ");
    for (i=0; i<n; i++)
    {
        printf("%d, ", i);
    }  
    printf("%d\n", i);

TIP: Esta es una solución tipo para procesar secuencias en las que el último elemento tiene un tratamiento diferenciado.

## Ejercicio 3

### Apartado a:

En el primer scanf que se ejecute el usuario entrará toda la secuencia y pulsará ENTER. Como sabemos cuantos números contiene la secuencia podríamos hacer un único scanf que recogiera todos valores. Pero para hacerlo más flexible será mejor ir haciendo scanf dentro de un bucle: 

    for (i=0; i<10; i++)
    {
        scanf("%u%*c", &n);
        suma = suma+n;
    }  

Es importante entender que después del primer scanf toda la secuenca estará ya en el buffer. És decir, solo el primer scanf pausará el programa a la espera de la entrada del usuario. Los siguientes scanf simplemente leerán del buffer.

ACLARACIÓN: Usa %u ya que son naturales. El uso de %*c no haría falta para descartar los espacios entre números ya que el %u (al igual que %d) consume los espacios que van delante del número. No obstante, conviene dejar el %*c ya que consume el salto de línia final (el %u no lo consume).

TIP: Si el programa os da problemas una forma de ver que está pasando es añadir un printf en cada iteración:

	for (i=0; i<10; i++)
    {
        scanf("%u%*c", &n);
        printf("Leido: %u\n");
    }  

### Apartado b:

Aquí necesitamos un bucle que se detenga al leer un -1 por lo que no podemos usar un for. Podemos usar un while o un do-while. Como la secuencia podría estar vacía, hemos de vigilar de no sumar un -1 si éste fuera el primer elemento de la secuencia. Esto hace que usar un while sea una buena solución:

	scanf("%d%*c", &n); 
    while (n!=-1)
    {
        sum = sum+n;
        scanf("%d%*c", &n);
    }  

TIP: La de este ejercicio es la solución típica para situaciones en las que hay que procesar una secuencia pero ésta tiene un centinela (último elemento que marca el fin y que no hay que procesar).

TIP: Si queréis añadir un printf para ver que va leyendo usad un %d en vez de un %u o de lo contrario el -1 os aparecerá como 4294967295. 

### Apartado c:

Dado que ahora la secuencia no puede estar vacía, podemos usar un do-while muy parecido al while anterior sin peligro de que sume un -1 :

	scanf("%d%*c", &n);
    do {
        sum = sum+n;
        scanf("%d%*c", &n);
    } while (n!=-1);


## Ejercicio 4

Se trata de programar un bucle for de 1 hasta N e ir mirando para cada valor si es un divisor (n%i == 0). Para imprimir correctamente las comas mirad la solución del ejercicio 2.

## Ejercicio 5

### Apartado a:

Para calcular el factorial se programa un bucle for de i=2 hasta M, y para cada iteración se ejecuta fact = fact*i, siendo fact=1 al principio.

### Apartado b:

Aquí hay que programar un bucle for de i hasta n y para cada iteración hay que acumular un nuevo término de la serie: e = e+1/(double)factorial_de_i. Hace falta poner (double) para que no haga la división entera (ya que 1 y factorial_de_i son enteros). 

Para calcular factorial_de_i copiamos el código anterior tal cual. Cuidado que habrá que canviar los índices del for del cálculo del factorial (ya estamos usando la "i" en el bucle exterior). Quedará algo así:
	
	for (j = 2; j <= i; j++)

Más adelante veremos como podemos hacerlo de un modo más elegante mediante una función. 

## Ejercicio 6

Este ejercicio es más complejo que los anteriores y se puede resolver de diferentes maneras. El esquema de una solución sería:

	do
    {
         /* aquí un while para saltar palabra */
	     /* incrementar contador de palabras */
         /* aquí un while para saltar blancos */
    } while (c != '.');


## Ejercicio 7

### Apartado a:

Bucle for que calcula la potencia haciendo multiplicaciones. Parecido al del factorial del Ejercicio 5 pero siempre multiplicamos por el mismo valor.

### Apartado b:

Es más fácil de lo que parece. Se trata de hacer un bucle de 0 a n y dentro calcular la potencia mediante el bucle del apartado a, luego calcular el factorial mediante el bucle del Ejercicio 5 y finalmente hacer la división. 

El (-1)^i hace que se sume en las iteraciones pares y se reste en las impares. No hace falta hacer ni esa potencia ni la multiplicación. Simplemente podemos poner un if:
	
	if (i%2==0)
     cos = cos+ pot/fact;
   else
     cos = cos-pot/fact;

## Ejercicio 8

Un buen esquema para este tipo de ejercicios sería éste:

	do
    {
        /* Mostrar el menu de opciones */
        scanf("%d%*c", &opcion);  		
		switch (opcion)
		{
			case 1:
				/* Tratar opción 1 */
				break;
			case 2:
				/* Tratar opción 2 */
				break;
			...
			default:
			    printf("Opcion Incorrecta\n");
	    }
	} while (opcion!=5);

## Ejercicio 9

### Apartado a:

Para determinar si es primo miraremos si tiene algún divisor distinto de 1 y n. Si encontramos alguno paramos de buscar y determinamos que no es primo. Si llegamos al final y no hay ninguno determinamos que es primo. 

    i = 2; 
    while (i<n && n%i != 0) 
		i=i+1;

    if (n==1 || i == n)
    	/*es primo*/