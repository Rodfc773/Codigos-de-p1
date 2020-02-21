#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct monstros
{
    int id;
    int xp;
    int dano;
    int vida;  
};
struct player
{
    int vida;
    int dano;
    int exp;
};
void ler_dados(int i, int t, struct monstros monstro[])
{
    if (i < t)
    {
        scanf("%d %d %d %d", &monstro[i].id, &monstro[i].xp, &monstro[i].vida, &monstro[i].dano);

        ler_dados(i + 1, t, monstro);
    }
}
void ler_matriz(int i, int j, int n, int m, int array[][m])
{
    for (i; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
}
int verificar(int i, int m,int array[][m], int x, int y, struct monstros monstro[], int t)
{
    if(i < t)
    {
        if (array[x][y] == monstro[i].id)
        {
            return monstro[i];
        }
        else
        {
            verificar(i + 1 ,m,  array, x, y, monstro,t);
        }
    }
    else
    {
        return -1;
    }
}
int combate(struct player ansa, struct monstros monstro[], int i2)
{
    if ((ansa.vida/monstro[i2].dano + ansa.vida % monstro.[i2]) >= (monstro[i2].vida/ansa.dano + monstro[i2].vida % ansa.dano)
    {
        return monstro[i2].exp;
    }
    
void movimentos(int i, int moves, int x, int y, int n, int m, int array[][m], struct monstros monstro[], struct player ansa, int t, int mortos, int exp)
{
     if (i < moves)
    {
        int direcao;

        scanf("%d", &direcao);

        if(i != 0)
        {
            int i2 = verificar(0, m,array, x, y, monstro, t);

            ansa.exp = combate(0, ansa, monstro, i2);

            if (ansa.exp != 0)
            {
                mortos++;
            }
            exp += ansa.exp;
        }
        if (direcao == 1)
        {
            if (x - 1 < 0)
            {
                x = n - 1;
            }
            else
            {
                x -= 1;
            }
        }
        else if (direcao == 2)
        {
            if (y + 1 >= m)
            {
                y = 0;
            }
            else
            {
                y += 1;
            }
        }
        else if (direcao == 3)
        {
            if (x + 1 >= n)
            {
                x = 0;
            }
            else
            {
                x += 1;
            }
        }
        else
        {
            if (y - 1 < 0)
            {
                y = m -1;
            }
            else
            {
                 y -= 1;
            }
        }
        
        //printf("(%d)\n",ansa.vida);

        movimentos(i + 1, moves, x, y, n , m, array, monstro, ansa,t, mortos,exp);
    }
    else
    {
        //exp += combate(monstro, ansa, x, y, m, array, t, 0, 0);
        printf("ansa derrotou: %d monstros\n", mortos);
        printf("ansa conseguiu: %d pontos de experiencia\n", exp);
        printf("posicao final: (%d, %d)\n", x, y);
    }

}
void print(int i, int j, int n, int m, int array[][m])
{
    if(i < n)
    {
        if (j < m)
        {
            if (j + 1 == m)
            {
                printf("%d\n", array[i][j]);
            }
            else
            {
                printf("%d ", array[i][j]);
            }
            print(i, j + 1, n, m, array);
        }
        else
        {
            print(i + 1, 0, n, m, array);
        }
    }
}
int main()
{
    int n, m, t;// t = quantidade de monstros, n = linhas e m = colunas;

    scanf("%d", &t);

    //printf("%d\n\n", t);
    
    struct monstros monstro[t];

    ler_dados(0, t, monstro);

    scanf("%d %d", &n, &m);

    int matriz[n][m];

    ler_matriz(0, 0, n, m, matriz);

    struct player ansa;

    scanf("%d %d", &ansa.vida, &ansa.dano);

    int x, y;

    scanf("%d %d", &x, &y);

    int moves;

    scanf("%d", &moves);

    //printf("%d\n\n\n",moves);


    movimentos(0, moves, x, y, n, m, matriz, monstro, ansa, t, 0, 0);

    //print(0, 0, n, m, matriz);


    return 0;
}
