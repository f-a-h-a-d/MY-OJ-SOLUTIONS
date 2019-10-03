#include<stdio.h>
#include<string.h>
int main()
{
    char s[101],a[]="hello",k[101];
    int j=0;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==a[j]){
            k[j]=s[i];
            j++;
        }
    }
    k[j]='\0';
    if(strcmp(k,a)==0)
        printf("YES");
    else
        printf("NO");

    return 0;
}
