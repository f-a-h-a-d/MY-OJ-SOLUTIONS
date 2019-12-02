#include<stdio.h>
int main()
{
    int i=0,n,a,x,y,max;
    scanf("%d",&n);
    max=0;
    a=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        a=a-x;
        a=a+y;
        if(a>=max)
            max=a;
    }
    printf("%d",max);
    return 0;
}
