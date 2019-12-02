#include<stdio.h>
int main()
{
    int n,i,count=0;
    char s[4];
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        if(strcmp(s,"X++")==0 || strcmp(s,"++X")==0)
        {
            count++;
        }

        else
        {
            count--;
        }

    }
    printf("%d",count);

    return 0;
}
