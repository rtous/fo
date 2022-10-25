# Ayuda para la sesión 4

## Ejercicio 1

La declaración de tpiscina sería algo así:

    typedef struct 
    {
        float prof, largo, ancho_pis;
        float ph, volumen, temperatura;
        int num_carriles;
        float ancho_carril;
        char uso; 
    } tpiscina;

La inicialización de una variable p de tipo tpiscina:

    tpiscina p={2.5, 50.0, 21.0, 6.5, 2506.0, 26.5, 8, 250.0, 'N'};

Para verificar que los datos que dependen de otros son correctos (el volumen y el ancho) deberemos calcular su valor correcto y comparar. Por ejemplo con el ancho:
    
    float ancho_teorico;
    ancho_teorico = p.num_carriles*p.ancho_carril/100;

Para evitar que la comparación falle por pocos decimales podemos hacer:
    
    #define ERROR 0.1E-02

    ...

    if ((p.ancho_pis < ancho-ERROR) || (p.ancho_pis > ancho+ERROR))
        ...


TIP: Para imprimir con tabuladores como en el enunciado podéis usar \t. Por ejemplo:
  
       printf("Profundidad = %.1f\tLargo = %.1f\t\t\tAncho = %.1f\n", p.prof, p.largo, p.ancho_pis);

## Ejercicio 2

TIP: Para leer o imprimir un unsigned char (8 bits es la mitad de la mitad de 32, half half): %hhu.

Empezaremos por declarar 3 variables de tipo tpixel:

    tpixel p1, p2, pp; 

Para leer mediante scanf, por ejemplo p1:

    printf ("Introduzca primer pixel (R,G,B,A): ");
    scanf ("(%hhu,%hhu,%hhu,%hhu)%*c", &p1.R, &p1.G, &p1.B, &p1.A);

A partir de aquí la única dificultad es hacer el redondeo de la media sin utilizar funciones de math.h. Como dividimos por 2 se puede hacer simplemente así:

    pp.R =  (p1.R + p2.R)/2 + (p1.R + p2.R)%2;  

## Ejercicio 3

### apartado a

TIP: Para leer o imprimir un unsigned int: %u.

Para calcular el total de segundos simplemente:

    ...
    segundos = expr_horaria.ss + expr_horaria.mm*60 + expr_horaria.hh*3600;
    ...

### apartado b

TIP: Para imprimir enteros con 2 dígitos: %02u. 

Primero pasaremos las dos expresiones horarias a segundos (seg1 y seg2). A continuación, dependiendo de si es antes o despúes del mediodía, calculamos la diferencia con la media noche más cercana. Por ejemplo, para seg1:

    if (seg1 < 12*3600) 
        dh1 = seg1;
    else 
        dh1 = 24*3600 - seg1;

Ahora que ya tenemos la diferencia con la medianoche más cercana de cada hora (dh1 y dh2), las comparamos (y imprimimos.
    
    if (dh1 < dh2)
        ...

## Ejercicio 4

La multiplicación y la división son simples, por ejemplo la multiplicación:

    tfraccion f1, f2, res;

    ...

    res.num = f1.num*f2.num;
    res.den = f1.den*f2.den;

La suma y la resta la podemos hacer mediante producto cruzado. Si queréis obtener el mismo resultado que en el enunciado deberéis usar el mínimo común múltiplo (OPCIONAL!). Podemos obtener el MCM partiendo del máximo común divisor (MCD) ya que:

    MCM(a,b)=a*b/MCD(a,b);

Para calcular el MCD tenemos el algoritmo de Euclides basado en que MCD(a,b) = MCD(b, a%b):

    r = a%b;
    while (r!=0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    MCD = b;

## Ejercicio 5

Éste ejercicio es complejo, conviene tomárselo con calma.

### apartado a

Aquí conviene primero asignar un valor numérico a cada palo:

    #define BASTOS 0
    #define ESPADAS 1
    #define COPAS 2
    #define OROS 3

Para leer la carta:
  
    ...
    scanf("(%c,%c)%*c",&fig,&pal);

    if (fig=='s' || fig=='S') 
        c.fig=10;
    else if (fig=='c' || fig=='C') 
        ... 

    if (pal=='o' || pal=='O') 
        c.pal=OROS;
    else if (pal=='c' || pal=='C') 
        ... 

Para mostrar la carta conviene usar un par de switch:

    switch(c.fig)
    {
        case 10: printf("\n(S,");
            break;
        ...

    switch(c.pal)
    {
        case OROS:    
            cambiar_color(YELLOW);
            printf("O");
            break;  
        ...  

### apartado b

Ahora hay que leer una secuencia de cartas acabada en '.' e ir guardando cual es la carta más grande leída (será más grande si el palo es mayor o si es igual y la figura es mayor). 

Hay varias formas de hacerlo. Recordemos que un esquema eficiente para trabajar con una secuencia con centinela era:

    scanf(..., &a)
    while(a!=centinela)
        procesar a
        scanf(..., &a)

Para este ejercicio podemos hacer lo mismo pero necesitamos una variable con la carta más grande encontrada (cmax) para poder ir comparando. Una opción sería inicializar cmax con el valor más pequeño posible:
    
    char fig_char, pal_char, separador;
    tcarta carta;
    tcarta cmax = {0, 0};
    ...
    scanf("(%c,%c)%c",&fig,&pal,&separador);
    //damos valor a carta
    while(separador!='.')
        si carta mayor que cmax 
            cmax pasa a ser carta
        scanf("(%c,%c)%c",&fig,&pal,&separador);
        //damos valor a carta

Otra opción, si suponemos que como mínimo hay una carta, sería usar la primer carta para dar valor a cmax y mover el scanf del bucle al principio:

    scanf("(%c,%c)%c",&fig,&pal,&separador);
    inicializar cmax con lo leído
    while(separador!=centinela)
        scanf("(%c,%c)%c",&fig,&pal,&separador);
        //damos valor a carta
        si carta mayor que cmax 
            cmax pasa a ser carta

Escojáis la opción que escojáis para determinar si la carta es mayor:

    if (carta.pal>cmax.pal)
      cmax = carta;
    else if (carta.pal==cmax.pal)
    {
      if (carta.fig > cmax.fig)
        cmax = carta;
    }