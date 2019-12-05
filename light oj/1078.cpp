#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
void Div(ll int n,ll int digit,int cas)
{
     int before = digit;
    int cnt=1;
    while(digit%n!=0)
    {
        digit=digit*10+before;
        digit=digit%n;
        cnt++;
 
    }
 
 
 
    printf("Case %d: %d\n",cas,cnt);
}
 
 
int main(void)
{
    int T;
    ll int n,digit;
    scanf("%d",&T);
 
    for(int i=1;i<=T;i++)
    {
 
        scanf("%lld %lld",&n,&digit);
 
        Div(n , digit, i);
    }
 
 
    return 0;
}
 