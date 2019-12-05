#include<stdio.h>
#include<math.h>

int Mod(int B,int P,int M);

int main(void)
{
    int B,P,M,sum,i,k=0;

    while(scanf("%d %d %d",&B,&P,&M)!=EOF){

    sum = Mod(B,P,M);

    printf("%d\n",sum);
    }

    return 0;
}

int Mod(int B,int P,int M)
{
    if(P==0)
        return 1;

    if(P%2==0)
    {
        int value = Mod(B,P/2,M);
            return (value*value)%M;

    }
    else{

        return (B%M*(Mod(B,P-1,M)))%M;
    }

}
