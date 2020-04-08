#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void pontos(int i, int k, int array[])
{
      int min, max;

      if (i < k)
      {
            scanf("%d %d", &min, &max);

            for (min; min <= max; min++)
            {
                  array[min] += 1;
            }

            pontos(i + 1, k, array);
      }

}
int maior_ponto(int i, int n,int array[], int aux)
{
      if (i < n)
      {
            if (array[i] > aux)
            {
                  aux = array[i];
            }
        	
            return maior_ponto(i + 1, n, array, aux);
      }
      else
      {
            printf("%d\n", aux);
        	return aux;
      }
      
}
void print_seq(int i, int n, int array[], int maior)
{
  if (i < n)
  {
    if (array[i -1] != maior && array[i] == maior)
    {
      printf("%d", i);
    }
    if (array[i] == maior && array[i + 1] != maior)
    {
      printf(" %d\n", i);
    }
    print_seq(i + 1, n, array, maior);
  }
}
int maior_seq(int i, int n, int array[], int seq[], int cont, int maior)
{
  if(i < n)
  {
    if (array[i] == maior)
    {
      cont += 1;
      seq[i] = cont;
    }
    else
    {
      cont = 0;
    }
    maior_seq(i + 1, n, array, seq, cont, maior);
  }
  else
  {
    int aux = 0;
    for (int j = 0; j < n; j++)
    {
      if (seq[j] > aux)
      {
        aux = seq[j];
      }
    }
    printf("maior sequencia: %d\n", aux);
    return aux;
  }
}
void inicio_fim(int i, int n, int seq[], int maior, int aux)
{
    if (i < n)
    {
        if(seq[i] == maior)
        {
            aux = i;
            i = n;
        }
        inicio_fim(i + 1, n, seq, maior, aux);
    }
    else
    {
        for(int m = aux; m >= 0; m--)
            if(seq[m] == 1){
                printf("comeca em: %d", m);
                break;
            }
        printf("\ntermina em: %d\n", aux);
    }
}
int main()
{
    int n, k; // n is the size of array and k is the number of persons  

    scanf("%d %d", &n, &k);

    int array[n];
  	int seq[n];
   		
    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
    }
    for( int m = 0; m < n; m++ )
    {
      seq[m] = 0;
    }

      pontos(0, k, array);

      for (int i = 0; i < n; i++)
      {
            printf("%d%c", array[i], i < n - 1 ? ' ' : '\n');
      }

      int aux = maior_ponto(0, n, array, 0);
  
  	  print_seq(0, n, array, aux);
  		
 	  int aux2 = maior_seq(0, n, array, seq, 0, aux);

      inicio_fim(0, n, seq, aux2, 0);
    
 return(0);
}
