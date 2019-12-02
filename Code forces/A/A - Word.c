#include<stdio.h>
int main()
{
    char S[102];
    int i,u=0,d=0;
    scanf("%s",&S);

    for(i=0;i<strlen(S);i++)
    {
        if(S[i]>=65 && S[i]<=90)
            u++;
        else if(S[i]>=97 && S[i]<=122)
            d++;

    }
    if(d>=u)
        printf("%s",strlwr(S));
    else
        printf("%s",strupr(S));

    return 0;
}

