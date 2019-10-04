#include<stdio.h>
int main()
{
    int n,m,sum,j=1;
    scanf("%d %d",&n,&m);
    sum=n;

    while(sum!=0)
    {

        if(j%m==0)
        sum=sum-1+1;
        else
            sum=sum-1;
        j++;
    }
    printf("%d",j-1);
    return 0;
}
