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

const int maxe = 300;
vector<vector<ll>> val;
vector<vector<ll>> dp;
int n;
int monkey(int i,int j){

    if(i>=0 && i<2*n-1 && j>=0 && j<n){

            if(dp[i][j]!=-1){
                return dp[i][j];
            }

        ll ret = -LInfi;
        ll val1,val2;
        if(i<n-1){
         val1 = max(ret , monkey(i+1,j+1)+val[i][j]);
         val2 = max(ret, monkey(i+1,j)+val[i][j]);
        }
        else{
            val1 = max(ret,monkey(i+1,j-1)+val[i][j]);
            val2 = max(ret, monkey(i+1,j)+val[i][j]);
        }

        return dp[i][j] = max(val1 , val2);
    }
    else{
        return 0;
    }
}


int main(void){

   //READ_IN;
    int tt;
    cin >> tt;
    int f=0;
    while(tt--){
            f++;
            val.assign(maxe,vector<ll>(maxe,0));
            dp.assign(maxe,vector<ll>(maxe,-1));
    cin >> n;
    int i=0;
    for( i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> val[i][j];
        }
    }
    int k=n;
    for(;i<2*n-1;i++){
        for(int j=0;j<k-1;j++){
            cin >> val[i][j];
        }
        k--;
    }


    int ans = monkey(0,0);
    cout << "Case " << f <<": ";
    cout << ans << en;


    }
    return 0;
}

