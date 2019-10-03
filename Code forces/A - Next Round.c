#include<stdio.h>
int main()
{
    unsigned int n,k,a[51],sum,i,count=0;
    scanf("%u %u",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%u",&a[i]);
        if(i==k-1)
            sum=a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!=0){
        if(a[i]>=sum)
            count++;
        }
    }
    printf("%u\n",count);
    return 0;
}
