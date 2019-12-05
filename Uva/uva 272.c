#include<stdio.h>
#include<string.h>
int main()
{
    char c;
    int count=0;
    while(scanf("%c",&c)!=EOF)
    {

        if(c=='"'){
        count++;
            if(count%2!=0)
            printf("%s","``");
            else
            printf("%s","''");
        }
        else{
     printf("%c",c);
        }
    }


    return 0;
}
