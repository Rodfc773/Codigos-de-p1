#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int leitura_dias(int contador,int numero,int moedas,int x,int y, char movanterior ,char mov)
{
    movanterior = mov;

    
    if (contador == numero)
    {  
        return moedas;   
    }
    else 
    { 
        scanf("\n%c", &mov);

         if (mov == 'C')
        {  
            
            y += 1;
        }
        if(mov =='D')
        {
            
            x +=1;
        }  
         if (mov == movanterior)
        {
            if (x - 1 == y && mov == 'D')
            {
                moedas += 1;
            }
            else if(y - 1 == x && mov == 'C')
            {
                moedas += 1;
            }
        }
        
       return leitura_dias(contador + 1,numero, moedas, x, y, movanterior,mov);
    }
}
int main()
{
    int numero, resultado;
    char mov,movanterio;

    scanf("%d",&numero);

    resultado = leitura_dias(1, numero, 0, 0,0, movanterio, mov);

    printf("%d", resultado);

}
