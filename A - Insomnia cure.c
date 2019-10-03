#include<stdio.h>
int main()
{
    unsigned long int i,k,l,m,n,d,a[100002],b=0,j=0,p=0,q=0,count=0;
    scanf("%lu %lu %lu %lu %lu",&k,&l,&m,&n,&d);
    for(i=1;i<=d;i++)
    {
        a[i]=0;
    }
    while(b<=d && k<=d)
    {
        b=b+k;
        a[b]=1;
    }
    while(j<=d && l<=d){
        j=j+l;
        a[j]=1;
}
while(p<=d && m<d){
        p=p+m;
        a[p]=1;
}
while(q<=d && n<d)
        {
        q=q+n;
        a[q]=1;
    }

    for(i=1;i<=d;i++)
    {

        if(a[i]==1){
            count++;
        }
    }
    printf("%lu",count);
    return 0;
}

