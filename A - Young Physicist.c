#include<stdio.h>
int main()
{
    int i,j,n,x=0,y=0,z=0,a[101][3];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        x=x+a[i][0];
    }
    for(i=0;i<n;i++)
    {
        y=y+a[i][1];
    }
    for(i=0;i<n;i++)
    {
        z=z+a[i][2];
    }
    if(x==0 && y==0 && z==0)
    printf("YES");
    else
        printf("NO");


    return 0;
}

