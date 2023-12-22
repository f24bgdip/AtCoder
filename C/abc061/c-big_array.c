#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int MAX = 10000;

    /* input 1 */
    long n;
    long long k;
    if (scanf("%ld %lld", &n, &k) != 2)
        goto fail;

    /* input 2 */
    long long *cnt = NULL;
    cnt = (long long *)calloc(MAX, sizeof(long long));
    if (cnt == NULL)
        goto fail;

    long val, times;
    for (long i = 0; i < n; i++)
    {
        if (scanf("%ld %ld", &val, &times) != 2)
            goto fail;

        cnt[val] += times;
    }

    /* process */
    for (val = 1; val < MAX; val++)
    {
        if (cnt[val] >= k)
            break;
        else
            k -= cnt[val];
    }

    /* output */
    printf("%ld\n", val);

pass:
    free(cnt);
    return 0;

fail:
    free(cnt);
    return -1;
}
