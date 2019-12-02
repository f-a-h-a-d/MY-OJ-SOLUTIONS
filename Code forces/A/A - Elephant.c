#include<stdio.h>
int main()
{
    unsigned long int x,count=0;
    scanf("%lu",&x);

    while(x>0)
    {
        if(x>=5){
            x=x-5;
            count++;
        }
        else if(x>=4){
            x=x-4;
            count++;
        }
        else if(x>=3){
            x=x-3;
            count++;
        }
        else if(x>=2){
            x=x-2;
            count++;
        }
        else if(x>=1){
            x=x-1;
            count++;
        }
    }
    printf("%lu",count);
    return 0;
}
