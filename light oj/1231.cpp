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

const int MOD = 100000007;

const int maxe1= 55;
const int maxe2 = 1005;

vector<int> coin;
vector<int> oc;

int dp[55][25][1002];
int cnt=0;

int change(int id,int k){

    if(k<0)return 0;

    if(id>=coin.size()){
        if(k==0){
                cnt++;
                return 1;
        }
        else return 0;
    }

    if(dp[id][oc[id]][k]!=-1){
        return dp[id][oc[id]][k];
    }

    int make1 = change(id+1,k);
    int make2=0;
    if(oc[id]>0){
    oc[id]--;
     make2 = change(id,k-coin[id]);
    oc[id]++;
    }

    return  dp[id][oc[id]][k]= (make2%MOD+make1%MOD)%MOD;

}

int main(void){

   //READ_IN;
    int tt;
    cin >> tt;
    int g=0;
    while(tt--){
        g++;
        int n,k;
        cin >> n >> k;

        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            coin.push_back(x);
        }
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            oc.push_back(x);
        }

        for(int i=0;i<55;i++){
                for(int j=0;j<25;j++)
                for(int k=0;k<1002;k++){
                    dp[i][j][k]=-1;
                }
        }

        int ans = change(0,k);
        cout << "Case " << g << ": ";
        cout << ans << endl;
        //trace(cnt);
        cnt=0;
        coin.clear();
        oc.clear();

    }

    return 0;
}

