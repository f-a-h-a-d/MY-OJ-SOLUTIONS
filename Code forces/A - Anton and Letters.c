#include<stdio.h>
#include<string.h>
int main()
{
    char S[1001],x[1001],d[1001];
    scanf("%[^\n]",&S);
    int i,j=0,count=0;
    for(i=0;i<strlen(S);i++)
    {
        if(S[i]>=97 && S[i]<=122){
            x[j]=S[i];
            j++;
        }
    }
    x[j+1]='\0';

    for(i=0;i<strlen(x);i++)
    {
        d[x[i]]=1;
    }

    for(i=97;i<=122;i++)
            {
                if(d[i]==1)
                    count++;
            }
    printf("%d",count);
    return 0;
}

