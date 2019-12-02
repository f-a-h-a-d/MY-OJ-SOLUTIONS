#include<stdio.h>
#include<string.h>
int main()
{
    char S[100001];
    unsigned int n,countA=0,countD=0,i;

    scanf("%u",&n);
    scanf("%s",S);
    for(i=0;i<strlen(S);i++)
    {
        if(S[i]=='A')
            countA++;
        else
            countD++;
    }
    if(countA>countD)
        printf("Anton");
    else if(countA==countD)
            printf("Friendship");
    else
      printf("Danik");

    return 0;
}

