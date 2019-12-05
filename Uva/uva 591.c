#include<stdio.h>
int main()
{
    unsigned int n,h[51],i,sum=0,total=0,count=0,j=0;
    while(scanf("%u",&n)!=EOF)
    {

        if(n==0)
            break;
            j++;
            sum=0;
            total=0;
            count=0;
        for(i=0;i<n;i++)
        {
            scanf("%u",&h[i]);
            sum=sum+h[i];
        }
        total=sum/n;
        for(i=0;i<n;i++)
        {
            if(h[i]!=total)
                count++;
        }
        printf("Set #%u\nThe minimum number of moves is %u.\n",j,count);
    }

    return 0;
}
