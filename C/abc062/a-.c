#include <stdio.h>

int main(void)
{
    /* input */
    int x[2] = {0};

    if (scanf("%d %d", &x[0], &x[1]) != 2)
        return -1;

    /* process */
    /*
     * g = 1: 1 3 5 7 8 10 12
     * g = 2: 4 6 9 11
     * g = 3: 2
     */
    int g[2] = {0};
    int r;

    for (int i = 0; i < 2; i++)
    {
        if (x[i] == 2)
        {
            g[i] = 3;
            continue;
        }

        r = x[i] % 2;
        if (x[i] > 7)
        {
            if (r == 0)
            {
                g[i] = 1;
                continue;
            }
            else
            {
                g[i] = 2;
                continue;
            }
        }
        else
        {
            if (r == 0)
            {
                g[i] = 2;
                continue;
            }
            else
            {
                g[i] = 1;
                continue;
            }
        }
    }

    /* output */
    if (g[0] == g[1])
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
