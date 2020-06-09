#include <bits/stdc++.h>
 
using namespace std;
 
#define READ_IN freopen("Input.txt","r",stdin)
#define READ_OUT freopen("Output.txt","w",stdout)
#define ll long long int
 
 
const int MAX = 30007;
 
vector <int> primes;
vector <bool> mark(MAX+2,true);
 
void seive(void)
{
    mark[0]=mark[1]=false;
 
    for(int i=4;i<=MAX;i+=2)
        mark[i]=false;
 
    for(int i=3;i*i<=MAX;i+=2)
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
        primes.push_back(i);
    }
 
}
 
vector <int> answer;
void code(int n)
{
    int x = n;
    int cnt =0;
 
    for(int i=0; primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0){
 
        while(n%primes[i]==0)
        {
            n = n/primes[i];
        }
        cnt++;
    }
 
    }
 
    if(n>1)
        cnt++;
 
    if(cnt>=3)
        answer.push_back(x);
 
}
 
int main(void)
{
    seive();
 
    for(int i=2;i<=10000;i++)
        code(i);
 
    int T; cin >> T;
 
    while(T--)
    {
        int r; cin >> r;
 
        cout << answer[r-1] << endl;
    }
 
    return 0;
} 