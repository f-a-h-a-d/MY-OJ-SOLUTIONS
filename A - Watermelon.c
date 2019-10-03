#include<stdio.h>
int main()
{
    unsigned int T;
    scanf("%u",&T);
    if(T>2 && T%2==0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
