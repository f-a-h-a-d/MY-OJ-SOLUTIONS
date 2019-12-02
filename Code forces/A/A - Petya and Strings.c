#include<stdio.h>
int main()
{
    char S[101],S1[101];
    gets(S);
    gets(S1);
    strlwr(S);
    strlwr(S1);
    if(strcmp(S,S1)==0)
        printf("%d",0);
    else if(strcmp(S1,S)>0)
        printf("%d",-1);
    else
        printf("%d",1);

    return 0;
}
