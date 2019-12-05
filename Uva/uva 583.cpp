#include<bits/stdc++.h>

using namespace std;

#define MAX 46340


vector <int> primes;

void seive(void)
{
    vector <bool> mark(MAX+5,true);

    int si= sqrt(MAX)+1;

    for(int i=3;i<=si;i+=2)
    {
        if(mark[i]==true)
        {
            for(int j=i+i;j<=MAX;j+=i)
            {
                mark[j]=false;
            }
        }
    }

    primes.push_back(2);

    for(int i=3;i<=MAX;i+=2)
    {
        if(mark[i]==true)
            primes.push_back(i);
    }


}

void check(int g)
{
    vector <int> answer;
    int N;

    if(g>0)
        N=g;
    else
        N=abs(g);

    int i=0;

      int vtsize = primes.size();

      for(int i=0;i<vtsize;i++)
      {
          while(N%primes[i]==0)
          {
              answer.push_back(primes[i]);
              N=N/primes[i];
          }
      }

      if(N>1)
        answer.push_back(N);


    if(g>0)
    {
        cout << g << " = " ;

        for(int i=0;i<answer.size();i++)
        {
            cout << answer[i];

            if(answer.size()!=i+1)
                cout << " x ";
        }
    }
    else
    {
        cout << g << " = " ;
        cout << -1 ;
        cout << " x ";

        for(int i=0;i<answer.size();i++)
        {
            cout << answer[i];

            if(answer.size()!=i+1)
                cout << " x ";
        }
    }

    answer.clear();

    cout << endl;

}


int main(void)
{
    seive();

    int g;

    while(scanf("%d",&g)!=EOF)
    {
        if(g==0)
            break;

        check(g);


    }



    return 0;
}
