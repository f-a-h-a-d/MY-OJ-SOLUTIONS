#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define MAX 100000000
 
 
vector <bool> mark(MAX+2,true);
vector <int> primes;
 
void make_seive(void)
{
    mark[0]=mark[1]=false;
 
    for(int i=3;i<=MAX;i+=2)
    {
        if(mark[i])
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
        if(mark[i])
        {
            primes.push_back(i);
        }
    }
 
    int si= primes.size();
 
    for(int i=0;i<si;i+=100)
        printf("%d\n",primes[i]);
 
}
 
 
int main(void)
{
    make_seive();
 
 
    return 0;
}