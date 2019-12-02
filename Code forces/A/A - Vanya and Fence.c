#include<stdio.h>
int main()
{
    int n,h,a,sum=0,i;
    scanf("%d %d",&n,&h);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a>h)
            sum=sum+2;
        else
            sum=sum+1;
    }
    printf("%d",sum);

    return 0;
}
