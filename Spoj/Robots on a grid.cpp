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

const int movex[] = {+0,+1};
const int movey[] = {+1,+0};

vector<string> grid;
int n;

ll dp[1002][1002];

const ll mod = (ll)(1LL<<31)-1;

ll dfs(int sos_x,int sos_y){

    if(sos_x==n-1 && sos_y==n-1)return 1;


    ll &ret = dp[sos_x][sos_y];

    if(ret!=-1)return ret;

    ll ans = 0;

    for(int i=0;i<2;i++){
        int x = sos_x + movex[i];
        int y = sos_y + movey[i];

        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]=='.'){
                 ans += (dfs(x,y)%mod);
                 ans = ans % mod;
        }
    }
    return ret= (ans%mod);

}

bool bfs(int x_sos,int y_sos,int x_des,int y_des)
{

    vector<vector<bool>> visited;
    visited.assign(1002,vector<bool>(1002,false));

    queue<pair<int,int>> Q;

    Q.push({x_sos,y_sos});

    visited[x_sos][y_sos]=true;

    while(!Q.empty()){

    pii p = Q.front();
    Q.pop();

    int x = p.first;
    int y = p.second;

    if(x==x_des && y==y_des)return true;


    for(int j=0;j<4;j++)
    {
        int xs = x+dx[j];
        int ys = y+dy[j];

        if((xs>=0 && xs<n) && (ys>=0 && ys<n) && grid[xs][ys]!='#' && (visited[xs][ys]==false))
        {
            Q.push({xs,ys});
            visited[xs][ys]=true;

        }
    }


    }

    return false;

}

int main(void){


    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    //trace(mod);

    memset(dp,-1,sizeof(dp));

    ll ans = dfs(0,0);

    if(ans!=0)
    cout << ans << endl;
    else{

        bool ck = bfs(0,0,n-1,n-1);


        if(ck){
            cout << "THE GAME IS A LIE" << endl;
        }
        else{
            cout << "INCONCEIVABLE" << endl;
        }
    }

    return 0;
}
