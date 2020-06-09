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
 
typedef pair<int,int> pii;
 
const int maxe = 1e5+10;
 
int n,m;
 
vector<vector<pii>> graph;
vector<int> des;
 
int DJ(int x,int y){
 
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    Q.push({0,x});
    des[x]=0;
    
    while(!Q.empty())
    {
        pii top = Q.top();
        int wi = top.first;
        int node = top.second;
        Q.pop();
 
        for(auto it: graph[node]){
 
            int d_wi = it.first;
            int d_node = it.second;
 
            if(des[d_node]>des[node]+d_wi){
                des[d_node]=des[node]+d_wi;
                Q.push({des[d_node],d_node});
            }
 
        }
    }
 
    return des[y];
 
}
 
 
int main(void){
    //READ_IN;
 
    int tt;
  
    scanf("%d",&tt);
 
    while(tt--){
 
    int n,m;
  
 
    scanf("%d %d",&n,&m);
 
    int x,y;
 
    scanf("%d %d",&x,&y);
 
    graph.assign(maxe,vector<pii>());
 
    des.assign(maxe,Infi);
 
    for(int i=0;i<m;i++){
        int a,b,wi;
        scanf("%d %d %d",&a,&b,&wi);
 
        graph[a].push_back({wi,b});
        graph[b].push_back({wi,a});
    }
 
    int ans = DJ(x,y);
 
    if(ans==Infi){
        printf("NONE\n");
    }
    else{
        printf("%d\n",ans);
    }
 
    }
 
    return 0;
}