#include<stdio.h>
#include<math.h>

#define MAX 100005

int a[MAX],d[MAX],count=0;

void seive(void);

int main(void)
{
    int i,n,L,sum=0;

     seive();

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;

            sum=0;

            for(i=0;d[i]<=n/2;i++)
            {
              L = n-d[i];

               if(a[L]==0)
                sum++;

            }

            printf("%d\n",sum);
    }


    return 0;
}

void seive()
{
    int i,j;

    for(i=0;i<=MAX;i++)
        a[i]=0;

    a[0] = 1;
    a[1] = 1;

    for(i=4;i<=MAX;i+=2)
        a[i]=1;

    for(i=3;i<=sqrt(MAX);i+=2)
    {
        if(a[i]==0)
        {
            for(j=i+i;j<=MAX;j=j+i)
            {
                a[j]=1;
            }

        }
    }

    for(i=2;i<=MAX;i++)
    {
        if(a[i]==0)
        {
            d[count]=i;
            count++;
        }
    }
    d[count]='\0';

}

