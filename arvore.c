#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(int t[7][2], int a)
{
    if (a == -1)
    {
        return;
    }
    printf("%d-->", a);
    print(t, t[a][0]);
    print(t,t[a][1]);
}
int main()
{
    int t[7][2], k = 3, i,p;

    menset(t, -1, sizeof(t));
    for (i = 0; i <= k; i++)
    {
        scanf("%d", &p);
        scanf("%d %d", &t[p][0], &t[p][1]);
    }
    print(t, 0)
}
