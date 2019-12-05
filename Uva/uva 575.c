#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
    char s[50];
    long long int sum=0,i,j,length=0;

    while(scanf("%s",s)!=EOF){

        if(strcmp(s,"0")==0)
            break;

        sum=0;

     length=strlen(s);

     j=1;

    for(i=length-1;i>=0;i--)
    {
        sum+=(s[i]-48)*(pow(2,j)-1);
        j++;
    }

    printf("%lld\n",sum);

    while((getchar())!='\n');

    }

    return 0;
}
