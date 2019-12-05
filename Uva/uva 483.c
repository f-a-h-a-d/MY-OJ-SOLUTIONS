#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    int length,intial,i,last,j;


    while(gets(s))
    {
        int length=strlen(s);

        s[length]=' ';
        s[length+1]='\0';

        intial=0;

        for(i=0;i<length+1;i++)
        {
            if(s[i]==' ')
            {
                last=i-1;

                for(j=last;j>=intial;j--)
                {
                    printf("%c",s[j]);
                }
                if(i!=length)
                printf(" ");

                intial=i+1;

            }

        }

    printf("\n");

    }

    return 0;
}
