#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int fatorial(numero)
{
    if (numeroz == 0)
    {
        return 1;
    }
    else
    {
        return numeroz * fatorial(numeroz - 1);
    }
}
int numerosprimos(int contador, int numero)
{
    if (contador > sqrt(numero))
    {
        return 1;
    }
    else
    {
        if (numero % contador == 0)
        {
            return 0;
        }
        else
        {
            return numerosprimos(contador + 1, numero);
        }
    }
}
int proximoPrimo (int numero) 
{

    if (numerosprimos(numero+1, 2)) 
    {
        return numero + 1;
    } 
    else
    {
        return proximoPrimo(numero + 1);
    }
}

int main() 
{
    int numero;

    scanf("%d", &numero);

    proximoPrimo(2, numero);
    
	return 0;
}
