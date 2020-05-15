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


int sos_x,sos_y;
int des_x,des_y;

ll dp[40][40];

map<pair<pair<int,int>,pair<int,int>>,int> mm;

int n;
ll make(int x,int y){


    if(x==des_x && y==des_y)return 1;


    if(dp[x][y]!=-1)return dp[x][y];

    int xu = x;
    int yu = y+1;

    ll p1 =0;
    ll p2 =0;

    if(xu>=1 && xu<=n && yu>=1 && yu<=n){
        if(mm.count({{x,y},{xu,yu}})){

        }
        else{
           p1 =  make(xu,yu);
        }
    }

    int xv = x+1;
    int yv = y;

    if(xv>=1 && xv<=n && yv>=1 && yv<=n){
        if(mm.count({{x,y},{xv,yv}})){

        }
        else{
            p2 = make(xv,yv);
        }
    }

    return dp[x][y] = p1+p2;

}

int main(void){

    //READ_IN;
    //READ_OUT;

    int tt;
    cin >> tt;

    while(tt--){

        mm.clear();

        memset(dp,-1,sizeof(dp));

        cin >> n;

        cin >> sos_x >> sos_y;
        cin >> des_x >> des_y;

        int w;
        cin >> w;

        for(int i=0;i<w;i++){
            int a,b;
            cin >> a >> b;
            char s;
            cin >> s;

            if(s=='S'){
                mm[{{a,b-1},{a,b}}]=1;
            }
            else if(s=='W'){
                mm[{{a-1,b},{a,b}}]=1;
            }
            else if(s=='E'){
                mm[{{a,b},{a+1,b}}]=1;
            }
            else{
                mm[{{a,b},{a,b+1}}]=1;
            }

        }
        ll ans = make(sos_x,sos_y);

        cout << ans << endl;
    }

    return 0;
}
