
#include<stdio.h>
int main()
{
    int n,m,sum;
    scanf("%d %d",&n,&m);
    if(n==m)
        sum=n;
    else{
        if(n<m)
            sum=n;
        else
            sum=m;
    }
    if(sum%2==0)
        printf("Malvika");
    else
        printf("Akshat");

    return 0;
}
