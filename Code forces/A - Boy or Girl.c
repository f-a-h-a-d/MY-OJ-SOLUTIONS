#include<stdio.h>
int main()
{
    char S[101],x[130];
    int length,count=0,i;
    scanf("%s",S);

    length=strlen(S);

    for(i=0;i<length;i++)
    {
        x[S[i]]=1;
    }

    for(i=97;i<=122;i++)
    {
        if(x[i]==1)
            count++;
    }
    if(count%2==0)
        printf("CHAT WITH HER!");
    else
        printf("IGNORE HIM!");

    return 0;
}
