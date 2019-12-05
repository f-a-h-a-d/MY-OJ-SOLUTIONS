#include<stdio.h>
#include<string.h>
int main()
{
    char N[15000];
    int i,length=0;
    while(gets(N))
    {
    length=strlen(N);
    for(i=0;i<length;i++)
    {
        N[i]=N[i]-7;
    }
    puts(N);
    }
    return 0;
}
