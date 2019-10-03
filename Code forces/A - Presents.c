#include<stdio.h>
int main()
{
    int n,a[102],x[102],i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

    }

    for(i=1;i<=n;i++)
    {
        x[a[i]]=i;

    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",x[i]);
    }
    return 0;
}

