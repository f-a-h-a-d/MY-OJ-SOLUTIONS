#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
void code(ll n)
{
    map<ll,int> f;
 
    while(n%2==0)
    {
        n=n/2;
 
        f[2]++;
    }
 
        int si= sqrt(n)+1;
 
    for(int i=3;i<=si;i+=2)
    {
        while(n%i==0)
        {
            n=n/i;
            f[i]++;
        }
    }
 
    if(n>1)
        f[n]++;
 
    for(map<ll,int> :: iterator k=f.begin();k!=f.end();k++)
    {
        cout << k->first << "^" << k->second << " ";
    }
 
    cout << endl;
 
    f.clear();

}
 
int main(void)
{
    ll n;
 
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
 
        code(n);
 
    }
 
    return 0;
}