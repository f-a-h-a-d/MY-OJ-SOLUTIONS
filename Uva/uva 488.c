#include<stdio.h>
int main()
{
    int t,a,f,i,j,k,m;
    scanf("%d",&t);

    for(i=1;i<=t;i++){

        scanf("%d %d",&a,&f);
        for(j=1;j<=f;j++){
            for(k=1;k<=a;k++){
                for(m=1;m<=k;m++){
                    printf("%d",k);
                }
                printf("\n");
            }
            for(k=a-1;k>=1;k--){
                for(m=1;m<=k;m++){
                    printf("%d",k);
                }
                printf("\n");
            }
            if(j<f){
            printf("\n");
           }
        }
        if(i<t)
            printf("\n");

    }

return 0;
}
