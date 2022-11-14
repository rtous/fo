# Ayuda para la sesión 7

## General

### Posición de la función en el código fuente y prototipos sin código.

Para poder usar una función en C, recordad que, o bien la función completa aparece antes de su llamada en el código fuente:

	int suma_digitos (int num)
	{ 
	  ...
	}

	main () 
	{ 
	  ...
	  sum_dig = suma_digitos(x);
	  ...
	}

o bien aparece primero su prototipo:

	int suma_digitos (int num);

	int main () 
	{ 
	  ...
	  sum_dig = suma_digitos(x);
	  ...
	}

	int suma_digitos (int num)
	{ 
	  ...
	}

De lo contrario, si el compilador ve una llamada a una función de la que no tiene ninguna información se quejará. 

## Ejercicio 1 (primer ejemplo de función)

Para no tener que poner primero el código de suma_digitos podemos poner su prototipo así:

	int suma_digitos (int num);

	main ()
	{ 
	  int x, sum_dig;

	    
	  printf ("\nIntroduza un valor natural:\n");
	  scanf ("%d%*c", &x);

	  sum_dig = suma_digitos(x);

	  printf("La suma de los digitos de %d es %d\n\n", x, sum_dig);
	}

A continuación viene el código de suma_digitos. En un bucle iremos procesando los dígitos uno a uno. Primero haremos num%10 para obtener el dígito de la derecha y luego haremos num/10 para descartarlos y seguir con el siguiente. La función tendría esta estructura:

	int suma_digitos (int num)
	{ 
	  int sum=0;
	  while (num!=0)
	  {
	    ...
	  }
	  return sum; //A veces se pone el resultado entre paréntesis pero no es necesario.
	}

## Ejercicio 2 (ejecutar el ejercicio anterior en bucle)

Recordad que lo mejor para recorrer una secuencia con centinela era hacer un primer scanf fuera del while y luego un while:

	printf ("\nIntroduza una secuencia de numeros acabada en -1:\n");
    scanf ("%d%*c", &x);
    while (x!=-1)
    {
         //... (procesar elemento)
         scanf ("%d%*c", &x); 
    }

## Ejercicio 3 (programa con menú de operaciones (factorial, etc.))

### apartado a

Se trata de poner al principio del programa los prototipos:

	int menu();
	float potencia(float b, unsigned e);
	unsigned long factorial(unsigned num);
	unsigned long combinatorio(unsigned m, unsigned n);

### apartado b

El main llamará a menu(), y en función de la opción devuelta por la función, se encargará de ejecutar las acciones pertinentes:

	do
	  {
	    opc = menu();
	    switch (opc)
	    {
	      case 1: printf("\nHa escogido la opcion calcular potencia\n"); 
	              //... pedir parámetros
	              //... llamar a la función potencia
	              //... mostrar resultados
	              break;

	      //...
	    }	  
	  } while(opc != 4);
	}

La función menu:

	int menu()
	{
	  int opcion;
	  do
	  {
	    //... mostrar menu
	    //... pedir opción  
	    //... si opción incorrecta mostrar mensaje de "vuelva a intentarlo"
	  } while(opcion<1 || opcion>4); 
	  return opcion ;
	}

### apartado c, d 

Copiad los códigos de potencia y factorial que ya teníais de otras sesiones dentro de funciones.

### apartado e

Recordad que el combinatorio de m sobre n es:

	factorial(m)/(factorial(m-n)*factorial(n));


## Ejercicio 4 (programa para operar con fracciones)

**IMPORTANTE: Aquí trabajaremos con funciones y structs.**

*NOTA: Por lo que a las funciones respecta, los structs son como cualquier tipo básico (int, etc.). Al pasarlos como parámetro pasamos una copia íntegra del struct.*

### apartado a

La función leer_fraccion será algo así:

	tfraccion leer_fraccion()
	{
	  tfraccion f;

	  //... pedir al usuario la fracción
	  
	  return(f);
	}

### apartado b

Simplemente mostrar el contenido de la fracción tal y como se describe en el enunciado.

### apartado c

Aquí se trata de aprovechar el código que teníais de otras sesiones. La función operacion_fracciones tendría la siguiente estructura:

	tfraccion operacion_fracciones(char operador, tfraccion f1, tfraccion f2)
	{
	  tfraccion res;
	  switch(operador)
	  {
	    case '+': //...
	    case '-': //... 
	    case '*': //...
	    case '/': //...
	  }
	  return(res);
	}

Si no queremos repetir la parte común dl código de suma y resta podemo hacer:
	
	case '+': 
	case '-': // calculo común suma y resta
			  // if (operador == '+')...
			  // else...

### apartado d

Aquí se trata de ir leyendo las fracciones de izquierda a derecha e ir operando. Primero leeremos dos y a partir de ahí vamos leyendo una y operando contra el resultado que ya teníamos:

	main()
	{
	  //...
	  //leer facción 1
	  //leer operador
	  //leer fracción 2
	  while(fracción 2 no sea 0/0)
	  {
	    //res = operar las dos fracciones
	    //fracción 1 = res;
	    //leer operador
	    //leer fracción 2
	  }
	  /...
	}

## Ejercicio 5 (eliminar de un vector ordenado, pero con una función)

** IMPORTANTE: Aquí trabajaremos con punteros. **

Por primera vez aquí pasaremos a una función un puntero. Lo haremos para que, desde dentro de la función "eliminar_elemento" se modifique un struct que está declarado en el main.

* NOTA: Para pasar un puntero hacemos &p y para acceder a lo que apunta *p. En el caso de los punteros structs, para acceder a un campo en vez de hacer (*p).a podemos hacer p->a. *

Para llamar a la función:

	int main ()
	{ 
	    tvector v={16,{3,15,19, 19, 23, 32, 38, 53, 123, 321, 543, 1000, 1123, 6578, 6660, 7999}};
	    //...
	    aux = eliminar_elemento(val, &v);
	    //...
	}

La función:

	int eliminar_elemento(int elem, tvector *v)
	{
		//...
	    //Accederemos al campo del struct haciendo v->nelem


