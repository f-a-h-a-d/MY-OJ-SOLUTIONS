#include<stdio.h>
#include<ctype.h>
int main()
{
    int x,y,z,t1,t2,t3,sum_s,sum_k,total;
    scanf("%d %d %d %d %d %d",&x,&y,&z,&t1,&t2,&t3);

        total=abs(x-y)+abs(x-z);

    sum_k=(total*t2)+(3*t3);
    sum_s=abs(x-y)*t1;

    if(sum_s>=sum_k)
        printf("YES");
    else
        printf("NO");
    return 0;
}
