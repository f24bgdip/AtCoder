#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n;
    unsigned long long x = 1;
    unsigned long long d = pow(10, 9) + 7;
    int i;

    if (scanf("%u", &n) != 1)
        return -1;

    for (i = 1; i <= n; i++)
        x = (x * i) % d;

    printf("%llu\n", x);

    return 0;
}
