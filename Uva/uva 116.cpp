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

const int mydx[] = {0,+1,-1};
const int mydy[] = {+1,+1,+1};
int row,col;

vector<vector<int>> grid;

ll dp[13][105];

//vector<vector<pair<int,int>>> path;

map< pair<int,int>,pair<int,int> >  path;

//int path[13][105];

ll make(int x,int y){

    if(y==col-1)return 0;

    if(dp[x][y]!=-1)return dp[x][y];

    ll p1 = Infi;

    int path_x=0,path_y=0;

    for(int i=0;i<3;i++){

        int xu = x+mydx[i];
        int yu = y+mydy[i];

        if(xu==row){
                xu = 0;
        }

        if(xu==-1){
                xu=row-1;
        }

        if(xu>=0 && xu<row && yu>=0 && yu<col){

            ll f1 = make(xu,yu) + grid[xu][yu];

            if(f1<p1){
                p1 = f1;
                path_x = xu;
                path_y = yu;

            }
            else if(f1==p1){

                p1 = f1;

                if(xu<path_x)path_x=xu;
            }

        }
    }

    ///path[x][y]={path_x,path_y};

    path[{x,y}] = {path_x,path_y};

    return dp[x][y] = p1;

}

int main(void){
   //READ_IN;
  // READ_OUT;

    while(cin >> row >> col){

    memset(dp,-1,sizeof(dp));

    path.clear();

    grid.clear();

    grid.assign(row,vector<int>(col,0));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> grid[i][j];
        }
    }

    ll ans = Infi;

    int start_x,start_y;

    for(int i=0;i<row;i++){
        ll f1 = make(i,0) + grid[i][0] ;

        if(f1<ans){
            ans = f1;
            start_x = i;
            start_y = 0;
        }
        else if(f1==ans){
            ans =f1;
            if(i<start_x){
                start_x = i;
                start_y = 0;
            }
        }

    }

    pair<int,int> pp = {start_x,start_y};

    while( path.count(pp) ){

        cout << pp.first +1  << " ";

        pp = path[pp];
    }

    cout << pp.first +1 << endl;

    cout << ans << endl;

    }

    return 0;
}
