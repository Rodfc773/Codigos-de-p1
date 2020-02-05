#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ler_array(int i, int n, int array[])
{
    if (i < n)
    {
        scanf("%d", &array[i]);

        ler_array(i + 1, n, array);
    }
}
void zerar_array(int i, int n, int array[])
{
    for (i; i < n; i++)
    {
        array[i] = 0;
    }
}
int prox_numero(array[],int i, int n)
{
    if (i < n)
    {
        if (array[i] == 0)
        {
            return i;
        }
        prox_numero(array, i + 1, n);
    }
        }
}
void formar_parcial(int i, int array1[], int array2[], int aux) // função para adicionar um no array secundario
{
    if(i != -1)
    {
        if(array2[i] == 1)  
        {
            aux++;
            i = prox
        }  
    }
}
int main() 
{
    int n; // quantidade de buracos para formar tocas

    scanf("%d", &n);

    int buracos[n];

    ler_array(0, n, buracos);

    int aux[n];

    zerar_array(0, n, aux);

    formar_parcial(0, n, buracos, aux, 0);
    
	return 0;
}
