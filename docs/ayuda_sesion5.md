# Ayuda para la sesión 5

## Ejercicio 1 

Para declarar e inicializar un vector de caracteres se puede hacer de dos maneras. Así (como para cualquier vector):

    char frase[200]={'E', 's', 't', 'o'... '.'};

O así (más práctico):

    char frase[200]="Esto es una frase.";

*NOTA: Los carácteres del vector no utilizados se rellenarán con 0s.* 

Para mostrarlos:
 
    for (i = 0; i<200 && frase[i]!='.'; i++) {
        printf("%c", frase[i]);
        i++;
    }
    printf("\n");

*NOTA: En C existe el concepto "string", un vector de caracteres terminado en el carácter null o '\0' (valor numérico 0). De momento no trabajaremos de ese modo y trabajaremos los vectores de caracteres igual que los otros (de enteros, etc.). En el futuro, cuando trabajemos con strings de C podremos imprimirlos simplemente con el especificador de formato %s y al inicializarlos deberemos reservar una posición para el centinela.*

Para declarar e inicializar las fechas tenéis que crear primero un typedef struct tfecha (como en la sesión anterior) y luego, en el main hacer simplemente:

    tfecha vfechas[5]={{1,1,1945}, {7,7,1999}, {12,4,2000}, {16,10,1989}, {8,3,2012}};


## Ejercicio 2 

En sesiones anteriores siempre leíamos los datos y los procesábamos a la vez, en un único bucle. Ahora, como tenemos vectores, los guardaremos primero en el vector (un bucle) y luego los procesaremos (otro bucle).

Para leer la frase podemos utilizar el esquema de siempre:

    i = 0; 
    scanf("%c", &frase[i]);
    while (frase[i]!='.')
    {
        i++;
        scanf("%c", &frase[i]);
    }
    scanf("%*c"); //para descartar el \n

Pero como esta vez no hay que hacer nada después del scanf podría ser práctico también un do-while (en sesiones anteriores teníamos que procesar lo leído excepto el centinela y si usábamos un do-while teníamos que añadir un if para no procesar el centinela):

    i = 0;
    do {
        scanf("%c", &frase[i]);
        i++;
    } while (frase[i-1] != '.');
    scanf("%*c"); //para descartar el \n

Para mostrar la frase codificada podemos usar un while o un for:

    for (i = 0; frase[i] != '.'; i++) {
        //imprimir carácter codificado
    } 
    printf("\n");

Para codificar el carácter deberemos distinguir por casos mediante un if (si letra mayúscula, si letra minúscula, si dígito, otra cosa). Por ejemplo, parar letras mayúsculas sería:

    if (frase[i]>='A' && frase[i]<='Z')
        c = 'A'+(frase[i]-'A'+4)%('Z'-'A'+1);
    ...

*NOTA: Hace falta hacer el módulo con 'Z'-'A'+1 para que si el resultado de sumar 4 supera el número de letras mayúsculas vuelva a contar por el principio.*

## Ejercicio 3

Este es un **EJERCICIO CLÁSICO** de búsqueda de un elemento en un vector (no ordenado y ordenado). 

*NOTA: Conviene prestar atención a los ejercicios marcados como EJERCICIO CLÁSICO.**

### apartado a

Para buscar un elemento en un vector desordenado no queda otra que ir recorriendo el vector hasta dar con él. Una vez encontrado no hay que seguir buscando. La solución clásica sería:

    i=0;
    while (i<DIM && vdesord[i]!=valor)
      i++;

    if (i==DIM)
      //no se ha encontrado
    else
      //se ha encontrado en la posición i

### apartado b

Si el vector está ordenado de mayor a menor podemos parar de buscar cuando vorden[i] sea menor o igual que el que buscamos (ya que seguro que no aparecerá después). Simplemente tenemos que modificar la condición del while del apartado a así: 
    
    while (i<DIM && vorden[i]>valor)

Y luego ver si se detuvo la búsqueda por haberlo encontrado o por pasarse el valor:

    if (i<DIM && vorden[i]==valor)
      //se ha encontrado en la posición i
    else
      //no se ha encontrado

## Ejercicio 4 

Este es un **EJERCICIO CLÁSICO** de eliminación e inserción de un elemento en un vector ordenado. 

En ambos apartados se empieza por buscar en que posición está el elemento a eliminar o en que posición debería ir el elemento a insertar. Es una búsqueda en un vector ordenado como en el ejercicio anterior (aunque ahora de menor a mayor):

    i=0;
    while (i<vect.nelem && valor>vect.vector[i])
        i++;

Al igual que en el ejercicio anterior hay que usar un if para determinar si se ha encontrado la posición:

    if (i<vect.nelem && valor==vect.vector[i]) 
        //elemento encontrado en la posición i
    else
        //elemento no encontrado

Dependiendo de cada apartado habrá que hacer una cosa u otra dentro del if.

### apartado a

Para eliminar un elemento de la posición pos hay que copiar el elemento de la posición pos+1 a la posición pos, etc. Finalmente hay que decrementar el campo nelem.

    for (i=pos; i<vect.nelem-1; i++)
        vect.vector[i]=vect.vector[i+1];

    vect.nelem--;
     
*NOTA: La i termina en N-2 (i<vect.nelem-1)*

### apartado b

Aquí solo insertaremos si no se encuentra el elemento, es decir dentro del else. Pero también hay que verificar que haya sitio suficiente, de modo que habrá que anidar otro if:

    else { //No se había encontrado el valor
        if (vect.nelem==DIM)
            //No hay sitio
        else {
            //Aquí pondremos el código para insertar
        }
    }

Para instertar un elemento en la posición pos hay que hacerle sitio desplazando todos los elementos una posición. Una forma de hacerlo es:

    for (i=vect.nelem; i>pos; i--) 
        vect.vector[i]=vect.vector[i-1];
    
Finalmente insertamos el valor y actualizamos el tamaño del vector:

    vect.vector[pos]=valor;
    vect.nelem++;

## Ejercicio 5 (difícil)

Este ejercicio consiste en ordenar un vector, pero en vez de ser un vector de datos básicos se trata de un vector de cartas. Conviene separar las dificultades:

### ordenación de un vector de enteros

Es recomendable empezar por hacer un programa que ordene un vector de enteros. El ejercicio da libertad para escoger el algoritmo de ordenación, el más sencillo sería BUBBLE SORT:

- Buscamos el elemento menor en el vector y lo intercambiamos por el primero (i=0).
- Ahora que ya tenemos el primer elemento ordenado, tenemos que ordenar el resto del vector. 
```
    for (i=0; i<N-1; i++) {
        posmin=i;
        for (j=i+1; j<N; j++) { //Buscamos un valor más pequeño.
            if v[j] < v[posmin] 
                posmin=j;
        }
        //Intercambiamos el primer elemento por el más pequeño encontrado.
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
```
### ordenación de un vector de cartas

Se trata de aplicar el mismo algoritmo pero con el detalle de que no podemos aplicar directamente el operador menor (<) a las cartas. Para determinar si una carta es menor que otra deberemos hacer lo mismo que en el ejercicio 5 de la anterior sesión de laboratorio. Será menor si el palo es menor o si, si es igual, si la figura es menor. 


## Ejercicio 6 (difícil)

Este es un **EJERCICIO CLÁSICO** de unión de listas. Es importante tener en cuenta que:

- Las listas no están vacías.
- Las listas no contienen repetidos.
- La lista resultante no debe contener repetidos.
- En el apartado a las listas no están ordenadas, en el b sí.

### apartado a

Dado que ni las listas están ordenadas ni el resultado tiene que estarlo se trata de concatenar las dos listas. Para ello podemos empezar por copiar la primera lista a la lista unión. Dado que son structs podemos hacer simplemente:

    tlista_matriculas lunion;
   
    lunion=lista1;

*NOTA: Podemos hacerlo ya que en C la asignación entre structs realiza una copia. No se podría hacer lo mismo si fueran dos simples vectores ya que en C los vectores son punteros a una dirección de memoria y lo quer haría sería que los dos apuntaran al mismo sitio.*

Ya tenemos la primera lista, ahora solo hay que concatenar la otra pero dice el enunciado que no se deben repetir valores en el resultado. Tendremos que recorrer la segunda lista y, para cada elemento, mirar si está en la primera (una búsqueda). Si no está lo añadimos a la lista resultante.

    for (i=0; i<lista2.nmat; i++) { //recorremos la segunda lista
        Aquí búsqueda del elemento i de lista2 en toda lista1
        if (!encontrada) { 
            lunion.lmat[lunion.nmat]=lista2.lmat[i];
            lunion.nmat++;
        }
    }

### apartado b

Dado que ahora las listas están ordenadas y el resultado también lo enfocaremos de un modo distinto. La idea será la siguiente (en realidad se trata del algoritmo MERGE SORT):

- Para cada lista declararemos un índice que actuará como un puntero que iremos desplazando por la lista. El índice apuntará al primer elemento que todavía no está en la lista unión. 
- Inicialmente los dos indices apuntarán al primer elemento de cada lista.
- Iterativamente haremos avanzar el índice que apunte al valor menor y lo iremos guardando en la lista unión.
- Al hacerlo así será fácil evitar repetidos ya que si en algún momento los dos ínidices apuntan a elementos con el mismo valor solo copiaremos uno de ellos a la lista unión.
```
    i = 0; //puntero de lista1
    j = 0; //puntero de lista 2
    while(i < lista1.nmat || j < lista2.nmat) {
      if (i == lista1.nmat)  { //lista 1 finalizada
        copiamos el elemento de lista2
        j++;
      } else if (j == lista2.nmat) { //lista 2 finalizada
        copiamos el elemento de lista1
        i++;
      }  else if (el elemento de lista 1 menor) {
        copiamos el elemento de lista 1
        i++;
      } else if (matrículas iguales) {
        copiamos cualquiera de los dos
        j++;
        i++;
      } else  { //el elemento de lista 2 menor
        copiamos el elemento de lista 2
        j++;
      }
      lunion.nmat++;
    }
```

