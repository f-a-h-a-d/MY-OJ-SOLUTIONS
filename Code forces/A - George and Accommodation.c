#include<stdio.h>
int main()
{
    int i,j,n,a[101][2],count=0,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        sum=a[i][1]-a[i][0];
        if(sum>=2)
            count++;
    }
    printf("%d",count);
    return 0;
}
