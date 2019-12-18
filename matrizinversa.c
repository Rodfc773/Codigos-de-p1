#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void ler_linha(int j, int m, int i, int array[][m])
{
    if (j < m)
    {
        scanf("%d", &array[i][j]);

        ler_linha(j + 1, m, i, array);
    }
}
void ler_matriz(int i, int n, int m, int array[n][m])
{
    if (i < n)
    {
        ler_linha(0, m, i, array);

        ler_matriz(i + 1, n, m, array);
    }
}
void linha_trasnposta(int i, int n, int j,int m, int array[n][m], int array2[m][n])
{
    if(i < n)
    {
        array2[j][i] = array[i][j];

        linha_trasnposta(i + 1, n, j, m, array, array2);
    }
}
void matriz_transposta(int i, int n, int j, int m, int array[n][m], int array2[m][n])
{
    if(j < m)
    {
        linha_trasnposta(i, n, j, m, array, array2);

        matriz_transposta(i, n, j + 1, m, array, array2);
    }
}
void imprimr_linha(int j, int m, int i ,int array[][m])
{
    if (j < m)
    {
       if(j + 1 == m )
       {
            printf("%d\n", array[i][j]);
       }
       else
       {
           printf("%d ", array[i][j]);
       }
        imprimr_linha(j + 1, m, i, array);
    }
}
void imprimir_matriz(int i, int n, int m, int array[n][m])
{
    if (i < n)
    {
        imprimr_linha(0, m, i, array);

        imprimir_matriz(i + 1, n, m, array);
    }
    
}
int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    int array[n][m];
    int trasnposta[m][n];

    ler_matriz(0, n, m,array);

    imprimir_matriz(0, n, m, array);

    matriz_transposta(0, n, 0, m, array, trasnposta);

    imprimir_matriz(0, m, n, trasnposta);

}
