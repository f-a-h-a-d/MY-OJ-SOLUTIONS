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
 
vector<vector<bool>> grid(8+1,vector<bool>(8+1,false));
map<pii,pii> parent;
map<pii,int> dis;
void bfs(int sos_x,int sos_y,int des_x,int des_y){
 
    queue<pii> Q;
    Q.push({sos_x,sos_y});
    
 
    parent[{sos_x,sos_y}]={-1,-1};
    dis[{sos_x,sos_y}]=0;
 
    while(!Q.empty()){
 
        pii A = Q.front();
        int x=A.first;
        int y=A.second;
        Q.pop();
 
        for(int i=0;i<8;i++){
 
            int u = x+kx[i];
            int v = y+ky[i];
 
            if(u>=0 && u<8 && v>=0 && v<8){
 
                    int wi = x*u+y*v;
 
                    if(dis[{u,v}]>(dis[{x,y}]+wi)){
 
                        dis[{u,v}]=dis[{x,y}]+wi;
                        Q.push({u,v});
                        parent[{u,v}]={x,y};
                    }
 
            }
        }
 
    }
 
}
 
int main(void){
 
    //READ_IN;
 
    int a,b;
 
    int x,y;

    while(cin >>a >> b >> x >> y){
 
            parent.clear();
 
            for(int i=0;i<=9;i++){
                for(int j=0;j<=9;j++){
                    dis[{i,j}]=Infi;
                }
            }
 
     grid.assign(9,vector<bool>(9,false));
     bfs(a,b,x,y);
 
     int p=x;
     int q = y;
     ll sum =0;
     while(1){
 
        pii D = parent[{p,q}];
 
        if(D.first==-1 && D.second==-1)
            break;
 
        sum+= D.first*p + D.second*q;
 
        p=D.first;
        q=D.second;
 
 
     }
    cout << sum << endl;
 
    }
 
    return 0;
}