#include<stdio.h>
int main()
{
    int n,m,i,j,x;

    scanf("%d %d",&n,&m);
    x=0;
    for(i=1;i<=n;i++)
    {
        if(i%2!=0){
        for(j=1;j<=m;j++)
        {
            printf("#");
        }
        }

        if(i%2==0)
        {
            x++;
            if(x%2!=0){
            for(j=1;j<=m-1;j++)
            {
                printf(".");

            }
            printf("#");
            }
            else
            {
                printf("#");
                for(j=1;j<=m-1;j++)
                {
                    printf(".");
                }
            }
        }
        printf("\n");
    }

    return 0;
}

