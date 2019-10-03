#include<stdio.h>
#include<string.h>
int main()
{
    char S[102],A[102];
    scanf("%s",S);
    scanf("%s",A);
    strrev(S);
    if(strcmp(S,A)==0)
        printf("YES");
    else
        printf("NO");

    return 0;
}

