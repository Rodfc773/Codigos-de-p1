#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ler_matriz(int i, int j, int lines, int coluns, int array[][coluns])
{
    if (i < lines)
    {
        if(j < coluns)
        {
            scanf("%d", &array[i][j]);

            ler_matriz(i , j + 1, lines, coluns, array);
        }
        else
        {
            ler_matriz(i + 1, 0, lines, coluns, array);
        }
    }   
}
void colisao(int i, int moves, char move, int m, int k, int l, int array[][m])
{
    if (i < moves)
    {
        scanf("%c", &move);

       
    else
    { 
        int k, l; //onde k e l indica a posição inicial]

        scanf("%d\n%d", &k, &l);
        
        printf("(%d,%d)", k, l);
    }
    
    
}
int main() 
{
    int lines, coluns;

    scanf("%d\n%d", &lines, &coluns);

    int matriz[lines][coluns];

    ler_matriz(0 , 0, lines, coluns, matriz);

    int moves;

    scanf("%d", &moves);

    int k, l; //onde k e l indica a posição inicial]

    scanf("%d\n%d", &k, &l);

    char move;

    colisao(0, moves, move, coluns, k, l, matriz);

	return 0;
}
