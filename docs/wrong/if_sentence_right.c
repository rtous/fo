#include <stdio.h>	

main ()
{
    char c, cn;
    int es_letra=0;

    printf("Introduzca un caracter: ");
    scanf("%c%*c", &c);

    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {        
        printf("Es una letra\n");
        es_letra=1;
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'U' ||
            c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u')
        {   
            printf("Es una vocal\n");
            printf("No es una consonante\n");
        }
        else
        {
            printf("No es una vocal\n");
            printf("Es una consonante\n");
        }
    }
    else
    {    printf("No es una letra\n"); 
         printf("No es una vocal\n");
         printf("No es una consonante\n");
    }
    if (c >= 'a' && c <= 'z')
    {
        printf("No es una mayuscula\n"); 
        printf("Es una minuscula\n"); 
        cn = c - ('a'-'A');
    }
    else if (c >= 'A' && c <= 'Z')
    {
        printf("Es una mayuscula\n");
        printf("No es una minuscula\n");
        cn = c + ('a'-'A');
    }
    else
    {     
        printf("No es una mayuscula\n");
        printf("No es una minuscula\n");
    }
    if (c >= '0' && c <= '9')
        printf("Es un digito\n");
    else
        printf("No es un digito\n");

    if (es_letra==1)
      printf("El caracter con la capitalizacion invertida es %c\n\n", cn);
}
   

