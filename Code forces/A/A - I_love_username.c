#include<stdio.h>
int main()
{
    int n,max,min,count=0,d,i,x;

    scanf("%d",&n);
    scanf("%d",&d);

    max=min=d;
    for(i=1;i<n;i++)
    {
        scanf("%d",&x);
        if(x>max)
        {
            count++;
            max=x;
        }
        else if(x<min){
            count++;
            min=x;
        }
    }
    printf("%d",count);

    return 0;
}

