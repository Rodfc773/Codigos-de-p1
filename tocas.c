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
void formar_parcial(int i, int n, int array1[], int array2[], int aux)
{
    if(i < n)
    {
        if(array2[array1[i]] == 0)
       {
            array2[array1[i]] = 1;

            if (array2[array1[i + 1]] == 1)
            {
                aux += 1;
            }
       }
       formar_parcial(i + 1, n, array1, array2, aux);
    }
    else
    {
        printf("%d", aux);
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
