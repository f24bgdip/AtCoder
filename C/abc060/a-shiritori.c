#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[3][10 + 1] = {'\0'};
    int i, j;

    for (i = 0; i < 3; i++)
    {
        if (scanf("%s[a-z]", &s[i][0]) != 1)
            return -1;
    }

    int ans = 0;
    for (i = 0; i < 3 - 1; i++)
    {
        for (j = 1; j < 10; j++)
        {
            if (s[i][j] == '\0')
                break;
        }
        if (s[i][j - 1] == s[i + 1][0])
            ans++;
    }

    if (ans == 3 - 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
