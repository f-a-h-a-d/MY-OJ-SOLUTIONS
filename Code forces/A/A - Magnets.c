#include<stdio.h>
int main()
{
    unsigned int n,a,i,count=0,j;

    scanf("%lu",&n);
    scanf("%lu",&a);

    for(i=0;i<n-1;i++)
    {
        scanf("%lu",&j);
        if(a!=j){
            count++;
            a=j;
        }
    }
    printf("%lu",count+1);
    return 0;
}
