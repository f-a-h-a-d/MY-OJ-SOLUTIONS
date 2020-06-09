#include<bits/stdc++.h>
#define READ_IN freopen("Input.txt","r",stdin);
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
 
const int maxe = 100005;
 
vector<ll> ar;
vector<pii> tree;
 
void make(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].first=ar[b];
        return;
    }
 
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
 
    make(left,b,mid);
    make(right,mid+1,e);
 
    tree[node].first=(tree[left].first+tree[right].first);
}
 
ll ck(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(i>e || j<b)
        return 0;
 
    if(b>=i && e<=j)
        return tree[node].first+carry*(e-b+1);
 
    ll left = node*2;
    ll right = node*2+1;
    ll mid  = (b+e)/2;
    ll p1 = ck(left,b,mid,i,j,carry+tree[node].second);
    ll p2 = ck(right,mid+1,e,i,j,carry+tree[node].second);
 
    return p1+p2;
}
 
void update(ll node ,ll b,ll e,ll i,ll j,ll newvalue)
{
    if(i>e || j<b)
        return ;
 
    if(b>=i && e<=j)
    {
        tree[node].first+=(e-b+1)*newvalue;
        tree[node].second += newvalue;
        return;
    }
 
     ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
 
    update(left,b,mid,i,j,newvalue);
    update(right,mid+1,e,i,j,newvalue);
 
    tree[node].first=(tree[left].first+tree[right].first+(e-b+1)*tree[node].second);
 
}
 
int main(void)
{
    //READ_IN
 
    ll tt; cin >> tt;
 
    while(tt--){
 
            ar.assign(maxe,0);
            tree.assign(maxe*4,{0,0});
 
    ll n; cin >> n;
    ll c; cin >> c;
 
    make(1,1,n);
 
    while(c--){
        ll a;
        cin >> a;
 
        if(a==0){
                ll p,q;
                cin >> p >> q;
                ll v; cin >> v;
            update(1,1,n,p,q,v);
        }
        else{
               ll p,q;
                cin >> p >> q;
                ll ans = ck(1,1,n,p,q);
                cout << ans << endl;
        }
    }
 
    }
  
    return 0;
}