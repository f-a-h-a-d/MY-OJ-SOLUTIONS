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
 
#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))
 
 
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
 
vector<int> b1,b2;
vector<int> t1,t2;
 
int n;
 
int dp[1005][3];
 
int make(int id,int num){
 
 
    if(id==n-1){
        if(num==1){
            return b1[id];
        }
        else{
            return b2[id];
        }
    }
 
    if(dp[id][num]!=-1)return dp[id][num];
 
 
    int p1,p2;
 
    if(num==1){
     p1 = make(id+1,1)+ b1[id];
     p2 = make(id+1,2)+ b1[id] + t1[id];
 
    }
    else{
         p1 = make(id+1,2) + b2[id];
         p2 = make(id+1,1) + b2[id] + t2[id];
    }
 
    return dp[id][num] = min(p1,p2);
 
}
 
int main(void){
 
 
    int tt;
    cin >> tt;
 
    int kk=0;
 
       while(tt--){
 
        kk++;
        cin >> n;
 
        b1.clear();
        b2.clear();
        t1.clear();
        t2.clear();
 
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            b1.push_back(x);
        }
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            b2.push_back(x);
        }
        for(int i=0;i<n-1;i++){
            int x;
            cin >> x;
            t1.push_back(x);
        }
        for(int i=0;i<n-1;i++){
            int x;
            cin >> x;
            t2.push_back(x);
        }
 
        memset(dp,-1,sizeof(dp));
 
        int p1 = make(0,1);
 
        memset(dp,-1,sizeof(dp));
 
        int p2 = make(0,2);
 
        cout << "Case " << kk << ": ";
 
        cout << min(p1,p2) << endl;
    }
 
    return 0;
}