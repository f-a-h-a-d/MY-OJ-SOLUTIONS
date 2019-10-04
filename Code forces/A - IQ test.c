
#include<stdio.h>
int main()
{
    int n,i,dif=0,a[101],countO=0,countE=0,indexE,indexO;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

   for(i=0;i<n;i++)
   {
       if(a[i]%2==0)
       {
           countE++;
           indexE=i;
       }
       else
       {
           countO++;
           indexO=i;
       }
   }
    if(countO==1)
        printf("%d",indexO+1);
    else
        printf("%d",indexE+1);

    return 0;
}

