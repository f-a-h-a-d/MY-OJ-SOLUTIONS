#include <bits/stdc++.h>
 
using namespace std;
 
#define READ_IN freopen("Input.txt","r",stdin)
#define READ_OUT freopen("Output.txt","w",stdout)
#define ll int 
 
const ll MAX = 3200;
 
vector <ll> primes;
vector <bool> mark(MAX+2,true);
 
void seive(void)
{
 
    mark[0]=mark[1]=false;
 
    for(ll i=4;i<=MAX;i+=2)
        mark[i]=false;
 
    for(ll i=3;i*i<=MAX;i+=2)
    {
        if(mark[i])
        {
            for(ll j=i+i;j<=MAX;j+=i)
            {
                mark[j]=false;
            }
        }
    }
 
    primes.push_back(2);
 
    for(ll i=3;i<=MAX;i+=2)
    {
        if(mark[i])
        primes.push_back(i);
    }
 
}
 
 
void code(int n)
{
    vector <ll> answer;
    
    answer.push_back(1);
 
    for(ll i=0; primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0){
 
        while(n%primes[i]==0)
        {
            n = n/primes[i];
 
            answer.push_back(primes[i]);
        }
 
    }
 
    }
 
    if(n>1)
        answer.push_back(n);
 
    for(ll i=0;i<answer.size();i++){
 
        if(i<answer.size()-1){
        printf("%d",answer[i]);
        printf(" x ");
    }
        else
             printf("%d",answer[i]);
    }
    
    printf("\n");
 
}
 
 
int main(void)
{
    seive();
 
    ll r;
 
    while(scanf("%d",&r)!=EOF)
    {
        code(r);
    }
 
    return 0;
} 
