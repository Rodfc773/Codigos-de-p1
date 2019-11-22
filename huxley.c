#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int fatorial(int numero)
{
    if (numero == 0)
    {
        return 1;
    }
    else
    {
        return numero * fatorial(numero - 1);
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
int proximoPrimo ( int numero) 
{

    if (numerosprimos(1, numero + 1)) 
    {
        return (numero + 1);
    }
    else
    {
        return proximoPrimo( numero + 1);
        
    }
}
int sequencia(int contador,int numero)
{
    double resultado;

    resultado += fatorial(contador) / proximoPrimo(contador);

    if (contador == numero)
    {

        return resultado;
    }
    else
    {
        return sequencia(contador + 1, numero);
    }
}

int main() 
{
    int numero;
    double resultado;

    scanf("%d", &numero);

    if (numero == 0)
    {
        printf("0.00\n");
    }
    else
    {
        resultado = sequencia(0, numero);
        printf("%.0lf\n", resultado);
    }
    
	return 0;
}
