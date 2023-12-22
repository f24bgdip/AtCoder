#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num_city, num_road;
    int city[50] = {0};
    int i;

    if (scanf("%d %d", &num_city, &num_road) != 2)
        return -1;

    int from, to;
    for (i = 0; i < num_road; i++)
    {
        if (scanf("%d %d", &from, &to) != 2)
            return -1;

        city[from - 1]++;
        city[to - 1]++;
    }

    for (i = 0; i < num_city; i++)
    {
        printf("%d\n", city[i]);
    }

    return 0;
}