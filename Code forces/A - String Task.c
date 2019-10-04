#include<stdio.h>
int main()
{
    int i,j=0;
    char a[101],x[101];

    scanf("%s",a);
    strlwr(a);

    for(i=0;i<strlen(a);i++)
    {
        if(a[i]!='a' && a[i]!='o' && a[i]!='y' && a[i]!='e' && a[i]!='u' && a[i]!='i')
        {
            x[j]=a[i];
            j++;
        }
    }
    x[j]='\0';

    for(i=0;i<strlen(x);i++)
    {
        printf(".");
        printf("%c",x[i]);
    }
    return 0;
}

