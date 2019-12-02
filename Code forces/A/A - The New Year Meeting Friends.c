#include<stdio.h>
#include<ctype.h>
int main()
{
    int x1,x2,x3,mid,sum;

    scanf("%d %d %d",&x1,&x2,&x3);

    if(x1>x2 && x1>x3){
        if(x2>x3)
        mid=x2;

    else
        mid=x3;

    }
    else if(x2>x1 && x2>x3){
        if(x1>x3)
        mid=x1;

    else
        mid=x3;

    }
    else if(x3>x2 && x3>x1)
    {
        if(x2>x1)
            mid=x2;
        else
            mid=x1;
    }

sum=abs(mid-x1)+abs(mid-x2)+abs(mid-x3);
    printf("%d",sum);

    return 0;
}

