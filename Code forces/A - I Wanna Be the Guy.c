#include<stdio.h>
int main()
{
    int n,p,q,a[101],b[101],x[101],i,count=0;
    scanf("%d",&n);
    scanf("%d",&p);
    for(i=1;i<=p;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1;i<=p;i++)
    {
        x[a[i]]=1;
    }
    for(i=1;i<=q;i++)
    {
            x[b[i]]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(x[i]==1){
            count++;
        }
    }
    if(count==n)
        printf("I become the guy.");
    else
        printf("Oh, my keyboard!");

    return 0;
}
