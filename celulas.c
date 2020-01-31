#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ler_matriz(int i, int j, int n, int m, int array[][m])// i and j are the counters
{
    if (i < n)
    {
        if ( j == m)
        {
            ler_matriz(i + 1, 0, n, m, array);
        }
        else
        {
            scanf("%d", &array[i][j]);

            ler_matriz(i, j + 1, n, m, array);
        }
    }
}
void printar_linha(int i, int j, int m, int array[][m])
{
    if ( j < m)
    {
        if (j + 1 == m)
        {
            printf("%d\n", array[i][j]);
        }
        else
        {
            printf("%d ", array[i][j]);
        }
        printar_linha(i, j + 1, m, array);
    }
}
void printar_matriz(int i, int n, int m, int array[][m])
{
    if (i < n)
    {
        printar_linha(i, 0, m, array);

        printar_matriz(i + 1, n, m, array);
    }
}
void linha_matriz_de_atk(int i, int j, int n,int m,  int array[][m], int celulas, int atks)
{  
    if (i < n)
    {
        if (j < m)
        {
            if(array[i][j] == 1)
            {
                if(atks > 0)
                {
                    array[i][j] = 0;

                    atks -= 1;
                }
                else
                {
                    celulas += 1;
                }
            }
            linha_matriz_de_atk(i, j + 1,n, m, array, celulas, atks);
        }
        else
        {
            linha_matriz_de_atk(i + 1, 0, n, m, array, celulas, atks);
        }
    }
    else
    {
        printar_matriz(0, n, m, array);

        printf("%d %d", atks, celulas);
    }
}
void limpar_matriz_impar(int i, int j, int n, int m, int array[][m], int celulas, int atks)
{
    for (j; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (array[i][j] == 1)
            {
                if (atks > 0)
                {
                    array[i][j] = 0;
                    atks -= 1;
                }
                else
                {
                    celulas += 1;
                }
                
            }
        }
    }
    printar_matriz(0, n, m, array);

    printf("%d %d", atks, celulas);

}
int main()
{
    int n, m, atks;// n is lines, m is coluns

    scanf("%d %d", &n, &m);

    int matriz[n][m];

    ler_matriz(0, 0, n, m, matriz);

    scanf("%d", &atks);

    if (n % 2 == 0)
    {
        linha_matriz_de_atk(0 , 0, n, m, matriz, 0, atks);
    }
    else
    {
        limpar_matriz_impar(0,0, n, m, matriz, 0, atks);
    }
    

	return 0;
}
