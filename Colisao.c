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
void validar_move(int i , int moves, char array[]) /*função para guardar em um array os movimentos feitos para poderem ser validados*/
{
    if (i < moves)
    {
        scanf("%c", &array[i]);

        validar_move(i + 1, moves, array);
    }
}
void colisao(int i, int moves,char movimentos[],int coluns ,int array[][coluns], int k, int l, int aux1, int aux2)
{
    if(i < moves)
    {
        if(movimentos[i] == 'C')
        {
            if(array[k -1][l] == 1)
            {
                aux1--;
            }
        }
        else if(movimentos[i] == 'B')
        {
            if (array[k + 1][l] == 1)
            {
                aux1++;
            }
        }
        else if(movimentos[i] == 'D')
        {
            if (array[k][l + 1] == 1)
            {
                aux2++;
            }
        }
        else
        {
            if (array[k][l - 1] == 1)
            {
                aux2--;
            }
        }
        colisao(i + 1, moves, movimentos, coluns, array, k, l, aux1, aux2);
    }
    else
    {
        printf("(%d,%d)", k + aux1, l + aux2);
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

    int k, l; //onde k e l indica a posição inicial

    validar_move(0, moves, move);

    scanf("%d\n%d", &k, &l);

    colisao(0, moves, move, coluns, matriz, k, l, 0, 0);

	return 0;
}
