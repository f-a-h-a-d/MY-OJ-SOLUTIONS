#include<stdio.h>
#include<string.h>
int main()
{
    char name[1000];
    int i,j;
    int count=0;
    while(scanf("%[^\n]",name))
    {
        count=0;

        for(i=0;i<strlen(name);i++){
        if((name[i]>='A' && name[i]<='Z') || (name[i]>='a' && name[i]<='z'))
            {
                if((name[i+1]<'A' || name[i+1]>'Z') && (name[i+1]<'a' || name[i+1]>'z'))
                    count++;
            }
        }
        printf("%d\n",count);

        while ((getchar()) != '\n');
    }

    return 0;
}
