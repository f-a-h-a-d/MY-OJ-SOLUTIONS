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
 
vector<vector<int>> graph;
vector<vector<int>> dis;
int n,m;
void bfs(int sos_x,int sos_y,int des_x,int des_y){
    
 
    queue<pii> Q;
    Q.push({sos_x,sos_y});
    dis[sos_x][sos_y]=graph[sos_x][sos_y];
 
    while(!Q.empty()){
 
        pii A = Q.front();
        int x=A.first;
        int y=A.second;
        Q.pop();
 
        for(int i=0;i<4;i++){
 
            int u = x+dx[i];
            int v = y+dy[i];
 
            if(u>=0 && u<n && v>=0 && v<m){
 
 
                    if(dis[u][v]>dis[x][y]+graph[u][v]){
 
                        dis[u][v]=dis[x][y]+graph[u][v];
                        Q.push({u,v});
                    }
 
            }
        }
 
    }
 
}
 
 
int main(void){
    //READ_IN;
 
    int tt;
    cin >> tt;
 
    while(tt--){
 
        cin >> n >> m;
 
        graph.assign(n+2,vector<int>(m+1,0));
        dis.assign(n+2,vector<int>(m+1,Infi));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> graph[i][j];
 
 
            }
        }
        int a,b,T;
        cin >> a >> b >> T;
        a--;
        b--;
 
        bfs(0,0,a,b);
 
         int ans = dis[a][b];
 
         if(ans<=T){
            cout << "YES" << endl;
            cout << T-ans << endl;
         }
         else{
            cout << "NO" << endl;
         }
 
    }
 
    return 0;
}