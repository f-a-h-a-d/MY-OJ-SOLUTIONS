#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
 
template <typename T>using ordered_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
 
#define PI              acos(-1.0)
#define en '\n'
#define Infi 0x3f3f3f3f
#define LInfi 0x3f3f3f3f3f3f3f3f
 
 
 
#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);
 
 
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
 
typedef long long int  ll;
typedef unsigned long long int llu;
 
vector<int> primes;
 
 
void seive(int n)
{
    vector <bool> fahad(n+1,true);
 
    fahad[0]=fahad[1]=false;
 
    for(int i=4;i<=n;i+=2)
        fahad[i]=false;
 
    int s = sqrt(n)+1;
 
    for(int i=3;i<=s;i+=2)
    {
        if(fahad[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                fahad[j]=false;
            }
        }
    }
 
    primes.push_back(2);
 
    for(int i=3;i<=n;i+=2)
    {
        if(fahad[i]==true)
            primes.push_back(i);
    }
 
}
 
 
vector<vector<int>> graph;
 
bool cker(int a,int b){
 
    string sa= to_string(a);
    string sb= to_string(b);
    int cnt=0;
    for(int i=0;i<sa.size();i++){
        if(sa[i]==sb[i])cnt++;
    }
    if(cnt==3){
 
            return true;
    }
    else return false;
}
 
const int maxe = 1e5;
 
vector<int> level(maxe,0);
vector<bool> visited(maxe,false);
 
int bfs(int sos,int des)
{
    queue<int> track;
 
    track.push(sos);
 
    visited[sos]=true;
 
    while(!track.empty()){
 
        int ckr = track.front();
        track.pop();
 
        for(int i=0;i<graph[ckr].size();i++)
        {
            int val = graph[ckr][i];
 
            if(visited[val]==false)
            {
                level[val]=level[ckr]+1;
                visited[val]=true;
                track.push(val);
 
            }
        }
 
    }
    return level[des];
}
 
 
 
int main(void){
 
    graph.assign(100000,vector<int>());
    seive(100000);
 
    vector<int> ar;
 
    for(int i=168;i<=1229;i++)
    {
        ar.push_back(primes[i]);
    }
 
    for(int j=0;j<ar.size();j++){
 
    for(int i=0;i<ar.size();i++){
 
            bool bol = false;
 
            bol =  cker(ar[j],ar[i]);
 
            if(bol){
                graph[ar[j]].push_back(ar[i]);
 
            }
    }
 
}
    int tt; cin>> tt;
 
    while(tt--){
 
    int a,b; cin >> a >> b;
 
    level.assign(maxe,0);
    visited.assign(maxe,false);
 
    int ans = bfs(a,b);
    cout << ans << endl;
 
    }
 
    return 0;
}