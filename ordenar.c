#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void leituradearray(int contador, int numero,int array[])
{
    if (contador < numero)
    {
        scanf("%d", &array[contador]);
        leituradearray(contador + 1, numero, array);
    }
}
void ordenardordearray(int contador, int numero, int array[])
{
    int aux;

    if(contador < numero - 1)
    {
        if (array[contador] > array[contador + 1])
        {
            aux = array[contador];
            array[contador] = array[contador + 1];
            array[contador + 1] = aux;

            ordenardordearray(contador + 1, numero, array);
        }
    } 
}
void chamarordenar(int contador, int numero, int array[])
{
    if(contador < numero )
    {
        ordenardordearray(contador + 1, numero,array);

        chamarordenar(contador + 1,numero, array);
    }
}
void printararray(int contador, int numero, int array[])
{
    if(contador < numero)
    {
        if (contador == numero - 1)
        {

            printf("%d\n", array[contador]);
        }
        else
        {
            printf("%d ", array[contador]);
        }
        printararray(contador + 1, numero, array);
    }
    
}
int main()
{   
    int n;

    scanf("%d", &n);

    int array[n];

    leituradearray(0, n, array);

    ordenardordearray(0, n, array);
    
    chamarordenar(0, n, array);

    printararray(0, n, array);

}
