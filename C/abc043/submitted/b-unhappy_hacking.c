#include <stdio.h>

void main(void)
{
    char s[10];
    unsigned int i, n;

    if (scanf("%s", s) == 0)
        return;

    n = 0;
    for (i = 0; i <= 10; i++)
    {
        switch (s[i])
        {
        case '0':
            s[n] = '0';
            n++;
            break;
        case '1':
            s[n] = '1';
            n++;
            break;
        case 'B':
            if (n > 0)
                n--;
            break;
        case '\0':
            s[n] = '\0';
            goto terminate;
        }
    }

terminate:
    printf("%s", s);

    return;
}
