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

int n,m;
char land,water;

vector<string> grid;
//vector<vector<char>> visited;
int cnt = 0;
void dfs(int x,int y){

    cnt++;

    if(grid[x][y]==water)return ;

    grid[x][y]=water;

    for(int i=0;i<4;i++){
        int ux = x + dx[i];
        int uy = y + dy[i];

        if(uy==-1){
            uy = m-1;
        }

        if(uy==m){
            uy = 0;
        }

        if(ux>=0 && ux<n && uy>=0 && uy<m && grid[ux][uy]==land){

            dfs(ux,uy);
        }
    }


}

int main(void){


    //READ_IN;
    //READ_OUT;

   while(cin >> n >> m){


    cin.ignore();

    grid.clear();

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        grid.push_back(s);

    }

    set<char> ss;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ss.insert(grid[i][j]);
        }
    }

    int x,y;
    cin >> x >> y;

     land = grid[x][y];

    ss.erase(land);

     water = *ss.begin();

    trace(land,water);

    dfs(x,y);



   int ans = 0;



   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

        if(grid[i][j]==land){
                cnt = 0;
                dfs(i,j);

            ans = max(ans,cnt);
        }



    }
   }
   cout << ans << endl;

   }
    return 0;
}
