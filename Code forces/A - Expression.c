
#include<stdio.h>
int main()
{
    int a,b,c;
    int sum1,sum2,sum3;
    scanf("%d %d %d",&a,&b,&c);
    sum1=a+b+c;

   if(sum1<=a+(b*c))
    sum1=a+(b*c);

     if(sum1<=a*(b+c))
    sum1=a*(b+c);

      if(sum1<=a*b*c)
    sum1=a*b*c;

      if(sum1<=a*(b+c))
    sum1=a*(b+c);

      if(sum1<=(a+b)*c)
    sum1=(a+b)*c;

printf("%d",sum1);
    return 0;
}
