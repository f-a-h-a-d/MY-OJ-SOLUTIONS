#include<stdio.h>
int main()
{
    unsigned long long int n,r;
    int bol=0;
    scanf("%llu",&n);
    while(n>0)
    {
        r=n%10;
        if(r==4 || r==7)
            bol++;
        n=n/10;
    }
    if(bol==4 || bol==7)
        printf("YES");
    else
        printf("NO");

    return 0;
}

