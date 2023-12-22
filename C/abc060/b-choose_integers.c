#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, y, r;
    int found = 0;
    int i;

    if (scanf("%d %d %d", &x, &y, &r) != 3)
        return -1;

    if (x % 2 == 0 && r % 2 == 1)
    {
        /* go through */
    }
    else
    {
        for (i = 1; i < y; i++)
        {
            if ((x * i) % y == r)
            {
                found = 1;
                break;
            }
        }
    }

    if (found)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}