#include<stdio.h>
int main()
{
    long int i,j,max=0,count=0,n,a[100002];
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }

    for(i=0,j=i+1;i<n-1,j<n;i++,j++)
    {
        if(a[i]<=a[j])
            count++;
        else{
                if(count>=max)
                    max=count;
            count=0;
        }
    }
    if(count>=max)
        max=count;
    printf("%d",max+1);

    return 0;
}
