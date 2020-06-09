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
 
#define white  0
#define grey  1
#define black  2
 
vector<vector<pair<int,int>>> graph;
vector<int> visited;
int ans=0;
 
int id;
void dfs(int sos,int sum,int val){
 
   int myval=sum+val;
 
   if(ans<myval){
    ans=myval;
    id=sos;
 
   }
 
    if(visited[sos]==black)return;
 
    visited[sos]=grey;
 
    for(int i=0;i<graph[sos].size();i++){
 
        int ad = graph[sos][i].first;
        int val = graph[sos][i].second;

 
        if(visited[ad]==white){
 
 
            dfs(ad,myval,val);
 
        }
 
    }
 
    visited[sos]=black;
 
}
 
 
 
int main(void){
   // READ_IN;
 
    int tt;
    cin >> tt;
 
    while(tt--){
 
            id=-1;
 
            int n;
            cin >> n;
            graph.assign(n+2,vector<pair<int,int>>());
            visited.assign(n+2,0);
 
            int a,b,wi;
 
            for(int i=1;i<=n-1;i++){
                    cin >> a >> b >> wi;
                graph[a].push_back({b,wi});
                graph[b].push_back({a,wi});
            }
 
                visited.assign(n+2,0);
                dfs(1,0,0);
                ans=0;
                visited.assign(n+2,0);
                
                dfs(id,0,0);
 
            cout << ans << endl;
            ans=0;
 
    }
 
    return 0;
}