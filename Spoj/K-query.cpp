#include<bits/stdc++.h>
 
using  namespace  std;
 
#define PI              acos(-1.0)
#define lcm(a,b)        (a * (b / __gcd(a,b)))
#define en '\n'
 
#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);
#define Infi                0x3f3f3f3f
 
const int dx[] = {+1,-1,+0,+0};                         // 4 X directions
const int dy[] = {+0,+0,+1,-1};                         // 4 Y directions
const int dx8[] = {+0,+0,+1,-1,-1,+1,-1,+1};            // King X Moves
const int dy8[] = {-1,+1,+0,+0,+1,+1,-1,-1};            // King Y Moves
const int kx[] = {-2, -2, -1, -1,  1,  1,  2,  2};      // Knight X Moves
const int ky[] = {-1,  1, -2,  2, -2,  2, -1,  1};      // Knight Y Moves
 
 
 
int  Set    (int N,int pos) {return N=N | (1<<pos);}    /// turn a bit on
int  reset  (int N,int pos) {return N= N & ~(1<<pos);}  /// turn a bit off
bool check  (int N,int pos) {return (bool)(N & (1<<pos));} /// check, if a bit is on or not
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define trace(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define trace(x...)
#endif
 
typedef long long int           ll;
typedef unsigned long long int  llu;
 
const int maxe = 50000;
vector<int> ar(maxe,1);
 
int tree[maxe*4];
 
void make(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ar[b];
        return;
    }
 
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
 
    make(left,b,mid);
    make(right,mid+1,e);
 
    tree[node]=tree[left]+tree[right];
}
 
int ck(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
 
    if(b>=i && e<=j)
        return tree[node];
 
    int left = node*2;
    int right = node*2+1;
    int mid  = (b+e)/2;
    int p1 = ck(left,b,mid,i,j);
    int p2 = ck(right,mid+1,e,i,j);
 
    return p1+p2;
}
 
void update(int node ,int b,int e,int i,int newvalue)
{
    if(i>e || i<b)
        return ;
 
    if(b==i && e==i)
    {
        tree[node]=newvalue;
        ar[b]=newvalue;
        return;
    }
 
     int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
 
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
 
    tree[node]=(tree[left]+tree[right]);
 
}
 
 
 
int main(void){
 
   // READ_IN;
 
    int n;
  
    scanf("%d",&n);
 
    vector<pair<int,int>> aa;
 
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        
        int index = i+1;
        aa.push_back({val,index});
 
    }
    sort(aa.begin(),aa.end());
 
    int q;
    scanf("%d",&q);
 
    vector<pair<int,pair<int,int>>> ansq;
    vector<pair<int,pair<int,int>>> cker;
 
    for(int i=0;i<q;i++){
        int l,r,k;
        
        scanf("%d %d %d",&l,&r,&k);
 
        cker.push_back({k,{l,r}});
        ansq.push_back({k,{l,r}});
    }
 
    sort(cker.begin(),cker.end());
 
    map<pair<int,pair<int,int>>,int> an;
 
 
    make(1,1,n);
 
    int gone = 0;
 
    for(auto it : cker){
 
            int k = it.first;
            int L = it.second.first;
            int R = it.second.second; 
 
            for(int j=gone;j<aa.size();j++){
 
                gone=j;
 
                int ckval = aa[j].first;
                int ckid = aa[j].second;
 
                if(k>=ckval){
                       
                    update(1,1,n,ckid,0);
 
                }
                else{
                    break;
                }
 
            }

 
            int ans = ck(1,1,n,L,R);
 
            an[{k,{L,R}}]=ans;
 
    }
 
    for(auto it:ansq){
        
        printf("%d\n",an[it]);
    }
 
 
 
    return 0;
}