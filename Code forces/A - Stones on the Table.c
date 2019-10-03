
#include<stdio.h>
#include<string.h>
int main()
{
    char S[52];
    int n,i,j,count=0;
    scanf("%d",&n);
    scanf("%s",S);
    for(i=0,j=1+i;i<n-1,j<n;i++,j++)
    {
        if(S[i]=='R'){
            if(S[j]=='R')
                count++;
        }
        else if(S[i]=='G'){
            if(S[j]=='G')
            count++;
        }
        else if(S[i]=='B'){
            if(S[j]=='B')
            count++;
        }
    }
    printf("%d",count);

    return 0;
}
