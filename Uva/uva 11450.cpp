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

vector<vector<int>> val;

int dp[30][30][250];

int make(int id,int W){

    if(W<0)return -Infi;
    //if(W==0)return 0;
    if(id>=val.size()){
        return 0;
    }

    //if(dp[id][W]!=-1)return dp[id][W];

    int p1 = -Infi;
    for(int i=0;i<val[id].size();i++){

        int k1;

        if(dp[id][i][W]!=-1)k1= dp[id][i][W];
        else{
        k1 = val[id][i] + make(id+1,W-val[id][i]);
        dp[id][i][W]=k1;
        }
        p1 = max(p1,k1);

    }

    return  p1;

}

int main(void){

    //READ_IN;
    //READ_OUT;

    int tt;
    cin >> tt;

    while(tt--){

    memset(dp,-1,sizeof(dp));
    int m,c;
    cin >> m >> c;

    val.assign(c,vector<int>());

    for(int i=0;i<c;i++){
        int x;
        cin >> x;
        for(int j=0;j<x;j++){
            int a;
            cin >> a;
            val[i].push_back(a);
        }
    }

    int ans = make(0,m);

    if(ans<0){

        cout << "no solution" << endl;
    }
    else{
        cout << ans << endl;
    }

    }

    return 0;
}
