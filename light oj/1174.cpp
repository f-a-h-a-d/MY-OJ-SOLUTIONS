#include<bits/stdc++.h>
 
using  namespace  std;
 
#define PI              acos(-1.0)
#define lcm(a,b)        (a * (b / __gcd(a,b)))
#define en '\n'
 
#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);
#define Infi                0x3f3f3f3f
#define long_Infi           1e17 +10;
 
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
 
vector<vector<int>> graph;
vector<int> level;
vector<int> level2;
vector<bool> visited;
 
void bfs(int sos)
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
 
 
}
 
 
void bfs2(int sos)
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
                level2[val]=level2[ckr]+1;
                 visited[val]=true;
                track.push(val);
 
            }
        }
 
    }
 
 
}
 
 
int main(void){
    //READ_IN;
 
    int tt; cin >> tt;
 
    for(int kk=1;kk<=tt;kk++){
 
        int n; cin >> n;
        graph.assign(n+1,vector<int>());
 
        int r; cin >> r;
 
        while(r--){
            int a,b;
            cin >>a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int s,d;
        cin >> s >> d;
 
        level.assign(n+1,0);
        level2.assign(n+1,0);
        visited.assign(n+1,false);
        bfs(s);
        visited.assign(n+1,false);
        bfs2(d);
 
        int ans = 0;
        for(int i=0;i<n;i++){
           
            ans = max(ans,level2[i]+level[i]);
        }
        cout << "Case " << kk <<": ";
        cout << ans << endl;
 
    }
 
    return 0;
}