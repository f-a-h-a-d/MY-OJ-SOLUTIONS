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
 
const int maxe = 10005;
 
typedef pair<int,int> pii;
 
vector<pii> graph[maxe];
 
vector<int> des(maxe);
 
int dj(int sos,int dis){
 
    set<pii> Q;
 
    des[sos]=0;
    Q.insert({0,sos});
 
    while(!Q.empty()){
 
        pii u = *Q.begin();
 
        Q.erase(u);
 
        int wi= u.first;
        int node = u.second;
 
        for(int i=0;i<graph[node].size();i++){
 
            pii v = graph[node][i];
 
            int x =  v.first;
            int y = v.second;
 
            if(des[y]>des[node]+x){
                Q.erase({des[y],y});
                des[y]=des[node]+x;
                Q.insert({des[y],y});
            }
        }
    }
 
    return des[dis];
}
 
int main(void){
    //READ_IN;
 
    int tt;
    cin >> tt;
    while(tt--){
 
        des.assign(maxe,Infi);
        int n;
        cin >>n;
 
        map<string,int> mp;
 
        for(int i=1;i<=n;i++){
            string ss;
            cin >> ss;
            mp[ss]=i;
 
            int lp; cin >> lp;
            for(int j=1;j<=lp;j++){
                int a,wi;
                cin >> a >> wi;
 
                graph[i].push_back({wi,a});
            }
 
        }
 
        int r; cin >> r;
 
        for(int k=0;k<r;k++){
            string x,y;
            cin >>x >> y;
            des.assign(maxe,Infi);
            int val = dj(mp[x],mp[y]);
            cout << val << endl;
        }
 
        for(int k=0;k<=maxe;k++){
            graph[k].clear();
        }
 
    }
 
    return 0;
}