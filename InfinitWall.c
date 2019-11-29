#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int pedagio(int contador, int numero, int x, int y, char movimento)
{ 
    int moedas;

    if (contador == numero)
    {
        return moedas;
    }
    else
    {
        if(x > y || y > x)
        {
            moedas + 1;
        }
        if(movimento == 'C')
        {
            return pedagio(contador + 1, numero, x, y + 1, movimento);
        }
        else
        {
            return pedagio(contador + 1, numero, x + 1, y, movimento);
        }
          
    }
    
}
void read(int contador, int numero)
{
    char movimento;

    int resultado, a;
    

    scanf("%c", &movimento);

   if (numero >= contador)
    {  
        a =  pedagio(0, numero, 0, 0, movimento);

       resultado += a;
    }

    read(contador + 1, numero);

    printf("%d", resultado);

   
}
int main()
{
    int numero;

    scanf("%d", &numero);

    read(0,numero);

    return 0;

}

