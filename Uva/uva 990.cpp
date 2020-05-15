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

vector<int> depth,gold;

int w;

int dp[35][1005];
int path[35][1005];

int make(int id,int W){


    if(W==0)return 0;
    if(W<0)return -Infi;
    if(id>=depth.size())return 0;

    if(dp[id][W]!=-1)return dp[id][W];

    int p1 = make(id+1,W-3*depth[id]*w) + gold[id];
    int p2 = make(id+1,W);


    if(p1>p2){
        path[id][W]=1;
    }
    else{
        path[id][W]=2;
    }

    return dp[id][W] = max(p1,p2);

}

int main(void){


    //READ_IN;
    //READ_OUT;


   int weight;
   int tr=0;
   while(cin >> weight >> w){

   if(tr!=0)
    cout << endl;

   tr++;


    int n;
    cin >> n;

    depth.clear();
    gold.clear();

    for(int i=0;i<n;i++){
        int d,g;
        cin >> d >> g;

        depth.push_back(d);
        gold.push_back(g);
    }

    memset(dp,-1,sizeof(dp));

    memset(path,-1,sizeof(path));

    int ans = make(0,weight);

    cout << ans << endl;

    int id = 0;
    int W = weight;

    vector<pair<int,int>> vec;

    int cnt =0;

    while(1){

        if(id>=depth.size())break;

        if(path[id][W]==1){

            vec.push_back({depth[id],gold[id]});

            cnt++;

            W=W-(3*depth[id]*w);

           id=id+1;
        }
        else if(path[id][W]==2)
        id=id+1;
        else if(path[id][W]==-1)
            id=id+1;

    }
    cout << cnt << endl;

    for(auto it : vec){
        cout << it.first << " " << it.second << endl;
    }

   }

    return 0;
}
