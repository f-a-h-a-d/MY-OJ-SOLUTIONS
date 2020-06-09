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
 
typedef pair<double,int> pii;
 
const int Maxe = 105;
 
vector<vector<pii>> graph;
 
vector<double> des;
int n;
 
double DJ(int sos){
 
    queue<pii> Q;
 
    des[sos]=-1.0;
    Q.push({-1.0,sos});

 
    while(!Q.empty()){
 
        pii u = Q.front();
        Q.pop();
 
        double wi= u.first;
        int node = u.second;
 
        for(int i=0;i<graph[node].size();i++){
 
            pii v = graph[node][i];
 
            double x =  v.first;
            int y = v.second;
 
            if(des[y]>des[node]*x*(-1)){
                des[y]=des[node]*x*(-1);
                
                Q.push({des[y],y});
            }
        }
    }
 
    return des[n];
 
 
}
 
 
 
int main(void){
 
    int m;
    while(cin >> n){
            if(n==0)break;
 
    cin >> m;
 
    graph.assign(n+2,vector<pii>());
    des.assign(n+2,Infi);
   
 
    for(int i=0;i<m;i++){
        int a,b,wi;
        cin >> a >> b >> wi;
 
        double W = wi/100.0;
        W=-W;
 
        graph[a].push_back({W,b});
        graph[b].push_back({W,a});
    }
 
 
 
    double ans = DJ(1);
    cout << fixed << setprecision(10) << ans*(-1)*100 << " " << "percent" << endl;
 
    }
    return 0;
}