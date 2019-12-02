#include<stdio.h>
int main()
{
    int n,a[31][3],count=0,i,j;
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
        for(j=0;j<n;j++)
        {
            if(a[i][0]==a[j][1])
                count++;
        }
    }
    printf("%d",count);
    return 0;
}

