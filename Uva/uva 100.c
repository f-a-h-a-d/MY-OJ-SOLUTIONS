#include<stdio.h>
int main()
{
    unsigned int i,j,x,p,q,temp,count=0,n,max=0,sub;

    while(scanf("%u %u",&i,&j)!=EOF){
            if(j>i){
            sub=j-i+1;
            p=i;
            q=j;
            }
            else{
                sub=i-j+1;
                p=j;
                q=i;
            }
            max=0;

        for(x=p;x<=q;x++){
                n=x;

                count=0;
            while(1){

                    if(n==1){
                            count++;
                        break;
                    }
                if(n%2!=0){
                   n=(3*n)+1;
                }
        else{
            n=n/2;
        }
        count++;
            }
         if(count>max){
            max=count;
         }
        }
        printf("%u %u %u\n",i,j,max);
}
    return 0;
}

