#include<stdio.h>
int main()
{
    unsigned long long int n,m,a[100002],sum=0,total=0,i,x;

    scanf("%llu %llu",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%llu",&a[i]);
    }
    x=1;
    for(i=0;i<m;i++)
    {
        if(a[i]>x)
        {
            sum=a[i]-x;
            total=total+sum;
            x=a[i];
        }
        else if(a[i]<x)
        {
            sum=n+a[i]-x;
            total=total+sum;
            x=a[i];
        }
        else if(a[i]==x)
        {
            total=total+0;
            x=a[i];
        }
    }
    printf("%llu",total);

    return 0;
}

