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
void colisao(int i, int moves,char movimentos[],int coluns ,int array[][coluns], int k, int l)
{
    if(i < moves)
    {
        if(movimentos[i] == 'C')
        {
            if(array[k -1][l] == 1)
            {
               k -= 1;
            }
        }
        else if(movimentos[i] == 'B')
        {
            if (array[k + 1][l] == 1)
            {
                k += 1;
            }
        }
        else if(movimentos[i] == 'D')
        {
            if (array[k][l + 1] == 1)
            {
                l += 1;
            }
        }
        else
        {
            if (array[k][l - 1] == 1)
            {
                l -= 1;
            }
        }
        colisao(i + 1, moves, movimentos, coluns, array, k, l);
    }
    else
    {
        printf("(%d,%d)", k , l);
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

    char move[moves];
    int i;

    int k, l; //onde k e l indica a posição inicial

    for(i = 0; i < moves; i++)
    {
        scanf(" %c", &move[i]);

    }

    scanf("%d\n%d", &k, &l);

    colisao(0, moves, move, coluns, matriz, k, l);

	return 0;
}
