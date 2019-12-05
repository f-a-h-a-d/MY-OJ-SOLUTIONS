#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 1000005

int a[MAX],d[1000001],count=0,n;

void seive(void);

int main(void)
{
    int i,min=0,a,b,L;

    seive();

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;



            for(i=0;d[i]<=n;i++)
    {
        L=n-d[i];

        if(a[L]==0)
        {
           if(L>min)
           {
                a=d[i];
                b=L;
                min=L;
           }
        }

    }



        printf("%d = %d + %d\n",n,a,b);

    }


    return 0;
}

void seive(void)
{

    int i,j,count=0;

    for(i=0;i<=MAX;i++)
        a[i]=0;



    a[0]=1;
    a[1]=1;

    for(i=4;i<=MAX;i+=2)
        a[i]=1;

    for(i=3;i<=sqrt(MAX);i=i+2)
    {
        if(a[i]==0)
        {
            for(j=i+i;j<=MAX;j=j+i)
            {
                a[j]=1;
            }
        }


    }
    count=0;

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
