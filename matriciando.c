#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void read_matriz(int i, int j, int n, int m, int array[][m])
{
    for (i; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
}
int somaP(int i, int j, int n, int m, int array[][m], int aux)
{
    if (i < n && j < m)
    {
        if(array[i][j] > 0)
        {
            aux += array[i][j];
        }
    somaP(i + 1, j + 1, n, m, array, aux);
    }
    else
    {
        return aux;
    }
    
}
int somaS(int i, int n, int m, int array[][m], int aux)
{
    int j;
    for(i; i < n; i++)
    {
        for(j = m - 1; j > 0; j--)
        {
            aux -= array[i][j];
        }
    }
    return aux;
}
void ordenar_matriz(int i, int j, int n, int m, int array[][m])
{
    if (i < n)
    {
        if (j < m)
        {
            if (array[i][j] > array[i][j + 1])
            {
                int aux;

                aux = array[i][j];
                array[i][j] = array[i][j + 1];
                array[i][j + 1] = aux;
            }
            ordenar_matriz(i, j + 1 ,n, m, array);
        }
        else
        {
            ordenar_matriz(i + 1, 0, n, m, array);
        }
        
    }
}
void ordenar_coluna(int i, int j, int n, int m, int array[][m])
{
    for (j; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (array[i][j] > array[i + 1][j])
            {
                int aux;
                aux = array[i][j];
                array[i][j] = array[i + 1][j];
                array[i + 1][j] == aux;
            }
        }
    }
}
int main()
{
    int n, m;// n and m are the size of array

    scanf("%d %d", &n, &m);

    if((n <= 0 || m <= 0) || (n != m))
    {
        printf("erro");
    }
    else
    {
        int matriz[n][m];
        int principal, secundaria;

        read_matriz(0, 0, n, m, matriz);

        principal = somaP(0, 0, n, m, matriz, 0);
        secundaria = somaS(0,n, m, matriz, 0);

        ordenar_matriz(0, 0, n, m, matriz);

        int i = 0;

        while ( i < n)
        {
            if (i == 0)
            {
                printf("[%d,", matriz[i][m - 1]);
            }
            else if(i + 1 == 0)
            {
                printf("%d]\n", matriz[i][m - 1]);
            }
            else
            {
                printf(" %d, \n", matriz[i][m - 1]);
            }
            i++;
        }
        //ordenar_coluna()
    }
    return 0;
    
}
