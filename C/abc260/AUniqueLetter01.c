#include<stdio.h>

int main(void)
{
    char s[3];
    char b[3];
    int i;

    scanf("%s", s);

    b[0]=1, b[1]=1, b[2]=1;

    if(s[0]==s[1]) b[0]=0, b[1]=0;
    else if (s[0]==s[2]) b[0]=0, b[2]=0;
    else if (s[1]==s[2]) b[1]=0, b[2]=0;

    for(i=0;i<3;i++){
        if(b[i]){
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("%s", "-1");

}