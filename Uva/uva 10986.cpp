
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
typedef pair<int,int> pii;

const int maxe = 20005;

vector<vector<pii>> graph;

vector<ll> des;

int dj(int sos,int dis){

    priority_queue<pii,vector<pii>,greater<pii>> Q;

    des[sos]=0;
    Q.push({0,sos});

    while(!Q.empty()){

        pii u = Q.top();
        Q.pop();

        int wi= u.first;
        int node = u.second;
        if(des[node]<wi) continue;    // more efficient

        if(node==dis){ return des[dis];} // more efficient

        for(int i=0;i<graph[node].size();i++){

            pii v = graph[node][i];

            int x =  v.first;
            int y = v.second;

            if(des[y]>des[node]+x){
                des[y]=des[node]+x;
                Q.push({des[y],y});
            }
        }
    }

    return des[dis];

}

int main(void){


   // READ_IN;
   // READ_OUT;

    int tt; cin >> tt;

    for(int k = 1;k<=tt;k++){
        int n,m,s,t;
        cin >> n >> m >> s >> t;

        graph.assign(n+1,vector<pii>());

        for(int i=0;i<m;i++){
            int a,b,wi;
            cin >> a >> b >> wi;

            graph[a].push_back({wi,b});
            graph[b].push_back({wi,a});

        }
        des.assign(maxe,Infi);
        ll ans = dj(s,t);

        if(ans!=Infi)
        cout << "Case #" << k << ": " << ans << endl;
        else
            cout << "Case #" << k << ": " << "unreachable" << endl;

    }

    return 0;
}
