#include<stdio.h>
#include<string.h>
int main()
{
    char s[101];
    int i,bol=0;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
        {
            bol=1;
            break;
        }
    }
    if(bol==1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
