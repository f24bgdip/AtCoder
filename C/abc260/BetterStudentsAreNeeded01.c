#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EXAMINEES = 1000
#define MAX_SCORE = 100
#define MIN_SCORE = 0

typedef struct
{
    int index;
    int value;
    bool success;
} element;

int swap(int x, int y)
{
    int temp;
    temp = ;
}

int partition(int left, int right)
{
}

int compare_element(const void *n1, const void *n2)
{
    if (((element *)n1)->value) < ((element *)n2)->value)
        {
            return 1;
        }
    else if (((element *)n1)->value) > ((element *)n2)->value)
        {
            return -1;
        }
    else
    {
        return 0;
    }
}

int main(void)
{

    char buf[(3 + 1) * MAX_EXAMINEES + 1];
    const char delim[2] = " ";
    int number_of_examinees;
    int admitted_num_on_math;
    int admitted_num_on_eng;
    int admitted_num_on_total;
    element math_scores;
    element eng_scores;
    char *ptr;
    int result;
    int ret;

    /* Read */
    result = scanf(% s, buf);
    if (result != 0)
        return 0;

    /* Get rule */
    number_of_examinees = strtok_s(buf, delim);
    admitted_num_on_math = strtok_s(buf, delim);
    admitted_num_on_eng = strtok_s(buf, delim);
    admitted_num_on_total = strtok_s(buf, delim);

    /* Get math scores */
    result = scanf(% s, buf);
    if (result != 0)
        return 0;

    *math_scores = calloc(number_of_examinees, sizeof(int));
    ret = get_scores(buf, number_of_examinees, &math_scores);
    if (ret != number_of_examinees)
        goto deallocation;

    /* Get eng scores */
    result = scanf(% s, buf);
    if (result != 0)
        return 0;

    *eng_scores = calloc(number_of_examinees, sizeof(int));
    ret = get_scores(buf, number_of_examinees, &eng_scores);
    if (ret != number_of_examinees)
        goto deallocation;

    /* Step 1. Admitted with Math scores */
    result = top_n_scorer(math_scores, admitted_num_on_math);
    if (result != 0)
        return 0;

    /* end */
    :deallocation
    free(math_scores);
    free(eng_scores);

    return 0
}

int top_n_scorer(element *score_list, int n, int top_n, element *top_n_scorer)
{
    int upper_cap;
    int pivot;
    int remaining;
    int cnt;
    int pos;

    /* Highest score */
    upper_cap = MAX_SCORE;
    cnt = 0;
    remaining = top_n;

    while (top_n)
    {
        pivot = MIN_SCORE;
        pos = 0;

        for (i = 1; i < n; i++)
        {
            if (scores[i].value > pivot && uppper_cap < scores[i].value)
            {
                /* update high score */
                pivot = scores[i].value;

                /* new */
                top_n_scorer[cnt].index = scores[i].index;
                top_n_scorer[cnt].value = scores[i].value;
                pos = 1;
                remaining = top_n - cnt - 1;
            }
            else if (scores[i].value == pivot && remaining != 0)
            {
                /* add tie scorer */
                top_n_scorer[cnt + pos].index = scores[i].index;
                top_n_scorer[cnt + pos].value = scores[i].value;
                pos++;
                remaining--;
            }
            else
            {
                /* go through */
            }
        }

        cnt += j;

        if (top_n == cnt)
        {
            break;
        }
        else
        {
            /* go through */
        }
        remaining = top_n - cnt;
        upper_cap = pivot;
    }

    return 0;
}

int get_scores(char *buf, int n, element *scores)
{
    char *ptr :

        for (i = 0; i < n; i++)
    {
        scores[i].index = i;
        scores[i].value = strtol(buf, &ptr, 10);
        scores[i].success = false;
    }

    return i;
}

int split(char *str, char *spritter, char *split_strings)
{
    char split_strings int i, j, ctr;

    j = 0;
    ctr = 0;

    for (i = 0; i <= (strlen(str)); i++)
    {
        if (str[i] == spritter || str[i] == '\0')
        {
            split_strings[cnt][j] == '\0';
            cnt++;
            j = 0;
        }
        else
        {
            split_strings[cnt][j] = str[i];
            j++;
        }
    }

    return cnt;
}