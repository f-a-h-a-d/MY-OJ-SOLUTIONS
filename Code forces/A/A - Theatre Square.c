#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long  int n,m;
    unsigned long long int sum;
    double a;

    scanf("%llu %llu %lf",&n,&m,&a);

    sum = ceil(m/a)*ceil(n/a);
    printf("%llu",sum);


    return 0;
}
