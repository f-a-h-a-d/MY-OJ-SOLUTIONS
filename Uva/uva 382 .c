#include<stdio.h>

int N;

void cool(void);

int main(void)
{
    int i=0;


    while(scanf("%d",&N)!=EOF)
    {
        if(i==0)
            printf("PERFECTION OUTPUT\n");


        if(N==0)
            break;

        i++;
        cool();

    }

printf("END OF OUTPUT\n");
    return 0;
}


void cool(void)
{
    int i,sum=0;

    for(i=1;i<=N/2;i++)
    {
        if(N%i==0)
        {
            sum+=i;
        }
    }
    if(sum==N)
        printf("%5d  PERFECT\n",N);
    else if(N>sum)
        printf("%5d  DEFICIENT\n",N);
    else
        printf("%5d  ABUNDANT\n",N);

}
