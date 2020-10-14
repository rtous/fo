//
//  sesion2_ej9.c
//  
//
//  Created by XXXXXXXX 02/10/2020.
//

#include <stdio.h>

int main()
{
    char caracter;
  
    printf("Introduzca un caracter:");
    scanf("%c%*c",&caracter);
    
    if((caracter>'A'||caracter=='A')
       &&(caracter<'Z'||caracter=='Z')
       &&(caracter=='A'||caracter=='E'||caracter=='I'||caracter=='O'||caracter=='U'))
        
    {
        printf("Es una letra\n");
        printf("Es una vocal\n");
        printf("Es una mayuscula\n");
        printf("No es una cosonant\n");
        printf("No es una minuscula\n");
        printf("No es un digit\n");
        
        caracter=caracter+32;
        
        printf("El caracter con la capitalizacion invertida es %c\n",caracter);
    }
    
        else
        {
            
        if((caracter>'A'||caracter=='A')
        &&(caracter<'Z'||caracter=='Z')
        &&(caracter!='A'||caracter!='E'||caracter!='I'||caracter!='O'||caracter!='U'))
        {
            printf("Es una letra\n");
            printf("No es una vocal\n");
            printf("Es una mayuscula\n");
            printf("Es una cosonant\n");
            printf("No es una minuscula\n");
            printf("No es un digit\n");
            
            caracter=caracter+32;
            
            printf("El caracter con la capitalizacion invertida es %c\n",caracter);
        }
            else{
            if((caracter>'a'||caracter=='a')&&(caracter<'z'||caracter=='z')&&(caracter=='a'||caracter=='e'||caracter=='i'||caracter=='o'||caracter=='u'))
            {
                    printf("Es una letra\n");
                    printf("Es una vocal\n");
                    printf("No es una mayuscula\n");
                    printf("No es una cosonant\n");
                    printf("Es una minuscula\n");
                    printf("No es un digit\n");
                    
                    caracter=caracter-32;
                    
                    printf("El caracter con la capitalizacion invertida es %c\n",caracter);
                }
            else{
                if((caracter>'a'||caracter=='a')&&(caracter<'z'||caracter=='z')&&(caracter!='a'||caracter!='e'||caracter!='i'||caracter!='o'||caracter!='u'))
                       {
                           printf("Es una letra\n");
                           printf("No es una vocal\n");
                           printf("No es una mayuscula\n");
                           printf("Es una cosonant\n");
                           printf("Es una minuscula\n");
                           printf("No es un digit\n");
                           
                           caracter=caracter-32;
                           
                           printf("El caracter con la capitalizacion invertida es %c\n",caracter);
                       }
                

                            else{
                                          printf("No es una letra\n");
                                          printf("No es una vocal\n");
                                          printf("No es una mayuscula\n");
                                          printf("No es una cosonant\n");
                                          printf("No es una minuscula\n");
                                          printf("Es un digit\n");
                                      }
                    
                }
            

            }
        }
        
        
            
          
        
}

    

         
