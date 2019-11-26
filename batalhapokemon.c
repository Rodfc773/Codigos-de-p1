#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void batlle(int life1,int life2,int damage1, int damage2)
{
	if (life1 - damage2 <= 0)
	{
		printf("Bezaliel\n");
	}
	if (life2 - damage1 <= 0)
	{
		printf("Clodes\n");
	}
	else
	{
		batlle(life1 - damage2,life2 - damage1, damage1, damage2);
	}
}
void read(int number, int counter)
{
	int life1, life2, damage1, damage2;

	scanf("%d %d %d %d", &life1, &life2, &damage1, &damage2);

	if (counter < number) 
	{
		batlle(life1, life2, damage1, damage2);
	}
	read(number, counter + 1);
	
}

int main() 
{
	int numero;

	scanf("%d", &numero);
	
	read(numero, 0);

	return 0;
}
