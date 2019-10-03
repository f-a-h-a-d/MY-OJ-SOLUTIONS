#include<stdio.h>
#include<ctype.h>
int main()
{
    int ara[5][5];
    int i,j,x=3,y=3,a,b;
    int d,p;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&ara[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(ara[i][j]==1)
            {
                a=i+1;
                b=j+1;
            }
        }
    }
    d=abs(a-x);
    p=abs(b-y);
    printf("%d",d+p);

    return 0;
}

