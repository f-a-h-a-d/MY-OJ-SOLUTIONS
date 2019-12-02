#include<stdio.h>
#include<string.h>
int main()
{
    char ara[101],ara1[101],n[101];
    int i;
    scanf("%s",ara);
    scanf("%s",ara1);

    for(i=0;i<strlen(ara1);i++)
    {
        if(ara[i]==ara1[i])
            n[i]='0';
        else
            n[i]='1';
    }
    n[i]='\0';
    printf("%s",n);
    return 0;
}
