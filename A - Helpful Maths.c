#include<stdio.h>
int main()
{
    char S[101],temp;
    int i,j;
    scanf("%s",S);
    for(i=0;i<strlen(S)-1;i=i+2)
        for(j=i+2;j<strlen(S);j=j+2)
    {
        if(S[i]>=S[j])
        {
            temp=S[i];
            S[i]=S[j];
            S[j]=temp;
        }
    }
    printf("%s",S);

    return 0;
}
