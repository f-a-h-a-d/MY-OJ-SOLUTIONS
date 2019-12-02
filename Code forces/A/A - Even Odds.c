#include<stdio.h>
int main()
{
    unsigned long long int k,n,num,x,even,odd;

    scanf("%llu %llu",&n,&k);

    if(n%2==0)
        x=n/2;
    else
        x=ceil(n/2.0);

    if(k>x)
    {
        even=k-x;
        num=even*2;
    }
    else
    {
        num=(k*2)-1;
    }
    printf("%llu",num);
    return 0;
}
