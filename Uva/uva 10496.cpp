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

typedef pair<int,int> pii;

const int maxe = 100;

int row,col;

vector<pair<int,int>> cord;

int init_x,init_y;
int q;

int dp[25][(1<<12)+2];

int make(int id,int x,int y,int mask){


    if(mask==(1<<q)-1){
        int dis = abs(x-init_x) + abs(y-init_y);
        return dis;
    }

    if(dp[id][mask]!=-1)return dp[id][mask];

    int ans = Infi;

    for(int i=0;i<q;i++){

        if(check(mask,i)==0){
            int a,b;
            tie(a,b) = cord[i];
            //int dis = bfs(x,y,a,b);
            int dis = abs(x-a) + abs(y-b);
            ans = min(ans, make(i,a,b,Set(mask,i)) +  dis);

        }
    }
    return   dp[id][mask] = ans;

}


int main(void){

    //READ_IN;
    //READ_OUT;

    int tt;
    cin >> tt;

    while(tt--){
        int n,m;
        cin >> n >> m;
        row =n;
        col =m;

        cin >> init_x >> init_y;
        cord.clear();
        cin >> q;
        int f = q;
        while(f--){
            int a,b;
            cin >> a >> b;

            cord.push_back({a,b});
        }

        int mask = 0;
        memset(dp,-1,sizeof(dp));
        int ans = make(0,init_x,init_y,mask);
        cout << "The shortest path has length ";
        cout << ans << endl;
    }

    return 0;
}
