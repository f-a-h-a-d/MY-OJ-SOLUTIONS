#include<stdio.h>
int main()
{
    char S[101];
    scanf("%s",S);
    if(strstr(S,"0000000")!=NULL || strstr(S,"1111111")!=NULL)
    {
       printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
