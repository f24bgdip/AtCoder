#include<stdio.h>

int main(void)
{
    char s[3];
    int result;

    result = scanf("%s", s)

    if(result <= 3){

        if(s[0]!=s[1]&&s[0]!=s[2]) printf("%c", s[0]);
        else if (s[1]!=s[0]&&s[1]!=s[2]) printf("%c", s[1]);
        else if (s[2]!=s[0]&&s[2]!=s[1]) printf("%c", s[2]);

        return 0;
    }

    puts("-1");

    return 0;
}