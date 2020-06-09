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
 
#define white  0
#define grey  1
#define black  2
 
typedef long long int  ll;
typedef unsigned long long int llu;
 
const int maxe = 10004;
 
vector<vector<int>> graph;
 
vector<int> visited(maxe,white);
 
bool dfs(int sos){
 
    if(visited[sos]==grey)return false;
 
    visited[sos]=grey;
 
    bool bol = true;
 
    for(int i=0;i<graph[sos].size();i++){
 
        int ad = graph[sos][i];
        if(visited[ad]==white){
            bol = dfs(ad);
 
            if(bol==false){
                return false;
            }
 
        }
        else if(visited[ad]==grey){
            bol = false;
            return bol;
        }
    }
    visited[sos]=black;
 
    return bol;
 
}
vector<int> st;
 
void toppsort(int sos){
 
    if(visited[sos]==black)return;
 
    visited[sos]=grey;
 
    for(int i=0;i<graph[sos].size();i++){
 
        int ad = graph[sos][i];
        if(visited[ad]==white){
            toppsort(ad);
        }
    }
 
    st.push_back(sos);
    visited[sos]=black;
 
}
 
 
int main(void){
    int n,m;
    cin >> n >> m;
 
    graph.assign(maxe,vector<int>());
 
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
 
    }
 
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end(),greater<int>());
    }
 
    bool bol = true;
    for(int i=1;i<=n;i++){
 
        bol = dfs(i);
        if(bol==false)break;
 
    }
 
 
    if(bol){
 
        visited.assign(maxe,0);
 
        for(int i=n;i>=1;i--)
        {
            if(visited[i]==white){
            toppsort(i);
            }
        }
        reverse(st.begin(),st.end());
        for(auto it: st){
            cout << it << " ";
        }
        st.clear();
 
    }
    else{
        cout << "Sandro fails." << endl;
    }
 
    return 0;
}
 