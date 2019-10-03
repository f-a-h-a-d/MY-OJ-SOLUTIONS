#include<stdio.h>
int main()
{
    unsigned long long int n;
    long long int sum=0;
    scanf("%llu",&n);
    sum=ceil(n/2.0);
    if(n%2==0)
        printf("%lld",sum);
        else
            printf("%lld",-sum);
    return 0;
}

