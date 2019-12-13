#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <sys/resource.h>

int ler_array(int contador, int *counter,int array[],int aux)
{
    if (scanf("%d", &array[contador]) != EOF)
    {
        ( *counter) += 1;

        if(array[contador] > aux)
        {
            aux = array[contador];
        }
        return ler_array(contador + 1, counter, array, aux);
    }
    else
    {
        return aux;
    }
    
}
void zerar_array(int contador,int numero, long int array[])
{
    if (contador < numero + 1)
    {
        array[contador] = 0;

        zerar_array(contador + 1, numero, array);
    }
}
void adc_array(int contador,int *counter, int array[], long int array1[])
{
    if(contador < counter)
    {
        array1[array[contador]] += 1;

        adc_array(contador + 1, counter, array, array1);
    }
}
void printar_array(int contador, int aux,int array1[])
{
    if(contador < aux + 1)
    {
        if(array1[contador] != 0)
        {

        }
    }
}
int main() 
{
    struct  rlimit rl;
    getrlimit(RLIMIT_STACK, &rl);
    rl.rlim_cur = 25 *1024 * 1024;
    setrlimit(RLIMIT_STACK, &rl);
   
    int array[500000], aux, counter = 0;


    aux = ler_array(0, &counter, array, 0);


    long int *array1 =(long int*)malloc((aux + 1) *sizeof(long int));

    zerar_array(0, aux, array1);

    adc_array(0, &counter, array, array1);

	return 0;
}
