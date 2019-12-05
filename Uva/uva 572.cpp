#include<bits/stdc++.h>

using namespace std;
char a[105][105];

 int n,m;

void check(int r,int c)
{

    if(a[r][c]=='@')
    {
        a[r][c]='*';

        if(a[r][c+1]=='@' && (r!=m+1 || r!=0) && (c!=n+1 || c!=0))
            check(r,c+1);

            if(a[r][c-1]=='@' &&  (r!=m+1 || r!=0) && (c!=n+1 || c!=0))
            check(r,c-1);

            if(a[r+1][c]=='@' && (r!=m+1 || r!=0) && (c!=n+1 || c!=0))
            check(r+1,c);

            if(a[r+1][c-1]=='@' && (r!=m+1 || r!=0) && (c!=n+1 || c!=0))
            check(r+1,c-1);

            if(a[r+1][c+1]=='@' && (r!=m+1 || r!=0) && (c!=n+1 || c!=0))
            check(r+1,c+1);

            if(a[r-1][c+1]=='@' && (r!=m+1 || r!=0) && (c!=n+1 || c!=0))
            check(r-1,c+1);

            if(a[r-1][c]=='@' && (r!=m+1 || r!=0) && (c!=n+1 || c!=0))
            check(r-1,c);

            if(a[r-1][c-1]=='@' && (r!=m+1 || r!=0) && (c!=n+1 || c!=0))
            check(r-1,c-1);

    }


}

int main(void)
{


    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(m==0)
            break;



        int i,j;
         for( i= 0; i<m; i++){
                cin.ignore();
            for( j= 0; j<n; j++){
                a[i][j]= cin.get();
            }

        }
            int cnt=0;

           for(int i=0;i<m;i++)
            for(int j=0;j<=n;j++)
            {
                if(a[i][j]=='@')
                {

                    check(i,j);
                    cnt++;
                }


            }

           printf("%d\n",cnt);


    }



    return 0;
}
