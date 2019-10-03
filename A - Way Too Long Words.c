#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char S[101];

    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",S);
        int length=strlen(S);
        if(length>10)
        {
            printf("%c%d%c\n",S[0],length-2,S[length-1]);
        }
        else
            printf("%s\n",S);
    }

    return 0;
}
