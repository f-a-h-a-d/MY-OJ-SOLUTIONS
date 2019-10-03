#include<stdio.h>
int main()
{
    int n,i,a[3],j,count=0,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]==1)
                count++;
        }
        if(count>=2)
            sum++;
    }
    printf("%d",sum);

    return 0;
}
