#include<stdio.h>
int main()
{
    int n,sum;
    scanf("%d",&n);
    if(n%2==0){
        sum=n-8;
        printf("%d %d",8,sum);
    }
    else{
        sum=n-9;
        printf("%d %d",9,sum);
    }


    return 0;
}
