#include<bits/stdc++.h>
 
using namespace std;
 
#define MAX 32000
#define ll long long int
 
vector <int> keep;
 
void primes(void)
{
    vector <bool> prime(32000,true);
 
    prime[0]=prime[1]=false;
 
    int s=sqrt(MAX)+1;
 
    for(int i=3;i<=s;i+=2)
    {
        if(prime[i]==true)
        {
            for(int j=i+i;j<MAX;j+=i)
            {
                prime[j]=false;
            }
        }
    }
 
    keep.push_back(2);
 
    for(int i=3;i<MAX;i+=2)
    {
        if(prime[i]==true)
        keep.push_back(i);
    }
 
}
 
void segmented(ll l, ll r)
{
    vector<bool> seg(r-l+1,true);
    if(l==1)
        seg[0]=false;
 
    for(int i=0;keep[i]*keep[i]<=r;i++)
    {
        int c_prime=keep[i];
 
        ll base = (l/c_prime)*c_prime;
 
        if(base<l)
            base=base+c_prime;
 
        for(ll j=base;j<=r;j+=c_prime)
        {
            seg[j-l]=false;
        }
 
        if(base==c_prime)seg[base-l]=true;
    }
 
    for(int i=0;i<r-l+1;i++)
    {
        if(seg[i])
            cout << i+l << endl;
    }
    cout << endl;
 
 
}
 
 
 
int main(void)
{
    ll l,r;
    int query;
    primes();
    cin >> query;
 
    while(query--){
    cin >> l >> r;
 
        segmented(l,r);
    }
 
 
    return 0;
}