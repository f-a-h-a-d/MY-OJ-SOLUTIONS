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
 
#define red 1
#define blue 2
 
typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int> pii;
 
const int maxe = 30000+56;
 
vector<vector<pii>> graph;
 
vector<int> des;
 
pair<int,int> dj(int sos){
 
    priority_queue<pii,vector<pii>,greater<pii>> Q;
 
    int min_des = Infi;
    int nn=sos;
 
    des[sos]=0;
    Q.push({0,sos});
 
    //trace("--");
 
    while(!Q.empty()){
 
 
 
        pii u = Q.top();
        Q.pop();
 
        //trace(u);
 
        int wi= u.first;
        int node = u.second;
 
        for(int i=0;i<graph[node].size();i++){
 
            pii v = graph[node][i];
 
            int x =  v.first;
            int y = v.second;
 
            if(des[y]>des[node]*(-1)+x){
                des[y]=des[node]+x;
                Q.push({des[y],y});
 
                if(des[y]<min_des){
                    min_des=des[y];
                    nn = y;
                }
            }
        }
    }
 
    return {nn,des[nn]};
 
}
 
int main(void){
 
    //READ_IN;
    int tt;
    
    scanf("%d",&tt);
 
    int n;
    for(int kk=1;kk<=tt;kk++){
            
            scanf("%d",&n);
 
    graph.assign(n+2,vector<pii>());
 
    for(int i=0;i<n-1;i++){
        int a,b,wi;
        
        scanf("%d %d %d",&a,&b,&wi);
        wi= -wi;
        
        graph[a].push_back({wi,b});
        graph[b].push_back({wi,a});
 
    }
 
    des.assign(maxe,Infi);
    pii p = dj(0);
 
    //trace(p);
    des.assign(maxe,Infi);
 
    pii x = dj(p.first);
 
    //trace(x);
    printf("Case ");
    printf("%d: ",kk);
    printf("%d\n",(-1)*x.second);
 
    //cout << "Case "<< kk  << ": "<< (-1)*x.second << endl;
 
 
    }
    return 0;
}