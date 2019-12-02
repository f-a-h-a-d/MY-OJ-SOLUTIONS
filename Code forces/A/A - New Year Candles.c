#include<stdio.h>
#include<ctype.h>
int main()
{
    int a,b,s;
    double sum,r,x;

    scanf("%d %d",&a,&b);
    sum=a;
    x=a;
    while(x>1)
    {
        r=(x*1.0/b*1.0);
        sum=sum+r;
        x=(x*1.0/b*1.0);
    }
    s=floor(sum);

    printf("%d",s);
    return 0;
}
