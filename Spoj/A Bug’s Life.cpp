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
 
#define red 1
#define blue 2
 
const int maxe = 1000005;
 
vector<vector<int>> graph;
vector<int> visited(maxe,0);
bool isbipartite(int sos){
 
    queue<int> Q;
    Q.push(sos);
    visited[sos]=red;
 
 
    while(!Q.empty()){
 
    int u = Q.front();
    Q.pop();
 
    for(auto it: graph[u]){
 
            if(it==u){
                return false;
            }
 
            if(visited[it]==visited[u]){
                return false;
            }
 
            if(visited[it]==0){
        if(visited[u]==red){
            visited[it]=blue;
            Q.push(it);
        }
        else if(visited[u]==blue){
            visited[it]=red;
            Q.push(it);
        }
 
            }
    }
 
    }
    return true;
 
 
}
 
 
int main(void){
    //READ_IN;
 
    int tt; cin >> tt;
    int ff=0;
    while(tt--){
            ff++;
 
        int n,m;
        cin >> n >> m;
 
        graph.assign(n+2,vector<int>());
        visited.assign(maxe,0);
 
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
 
        int ans = true;
        bool k;
        for(int i=1;i<=n;i++){
 
        if(visited[i]==0){
         k = isbipartite(i);
        }
 
        if(k==false){
            ans=false;
        }
 
 
        }
 
        cout << "Scenario #" << ff << ":" << endl;
        if(ans==false){
            cout << "Suspicious bugs found!" << endl;
        }
        else{
            cout << "No suspicious bugs found!" << endl;
        }
    }
 
    return 0;
}