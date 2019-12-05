#include<bits/stdc++.h>


using namespace std;

int main(void)
{

   int T,N,u=0;
   scanf("%d",&T);

   while(T--)
   {
       u++;
       scanf("%d",&N);
       set<int> a;
       int p[50];

       for(int i=0;i<N;i++)
       {
           int input;
           cin >> input;
           a.insert(input);
       }



       int cnt=floor((a.size()/2));

       int i=0;
       for(set <int> :: iterator k=a.begin();k!=a.end();k++)
       {

           p[i]=*k;
           i++;
       }

       printf("Case %d: %d\n",u,p[cnt]);
   }


    return 0;
}
