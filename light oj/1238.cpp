#include<bits/stdc++.h>
 
using  namespace  std;
 
#define PI              acos(-1.0)
#define lcm(a,b)        (a * (b / __gcd(a,b)))
#define en '\n'
 
#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);
#define Infi                0x3f3f3f3f
#define long_Infi           1e17 +10;
 
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
 
typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int> pii;
 
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<int>> level;
 
int row,col;
int lv_a,lv_b,lv_c;
void bfs(int x_sos,int y_sos)
{
    queue<pair<int,int>> Q;
 
    Q.push({x_sos,y_sos});
 
    visited[x_sos][y_sos]=true;
 
    while(!Q.empty()){
 
    pii p = Q.front();
    Q.pop();
 
    int x = p.first;
    int y = p.second;
 
    for(int j=0;j<4;j++)
    {
        int xs = x+dx[j];
        int ys = y+dy[j];
 
        if((xs>=0 && xs<row) && (ys>=0 && ys<col) && (grid[xs][ys]=='.'|| grid[xs][ys]=='a' || grid[xs][ys]=='b' || grid[xs][ys]=='c') && (visited[xs][ys]==false))
        {
            Q.push({xs,ys});
            visited[xs][ys]=true;
            level[xs][ys]=level[p.first][p.second]+1;
 
            if(grid[xs][ys]=='a'){
                lv_a = level[xs][ys];
            }
 
            if(grid[xs][ys]=='b'){
                lv_b = level[xs][ys];
            }
 
            if(grid[xs][ys]=='c'){
                lv_c = level[xs][ys];
            }
        }
    }
 
    }
 
}
 
int main(void){
    //READ_IN;
 
    int tt; cin >> tt;
 
    for(int kk=1;kk<=tt;kk++){
 
    int n,m; cin >> n >> m;
    row = n;
    col = m;
    grid.clear();
 
    for(int i=0;i<n;i++){
        string s; cin >> s;
        grid.push_back(s);
    }
 
    int x,y;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='h'){
                    x=i;
                    y=j;
            }
        }
    }
 
    level.assign(100,vector<int>(100,0));
    visited.assign(100,vector<bool>(100,0));
    bfs(x,y);
 
    cout << "Case "<< kk  << ": ";
 
    cout << max(lv_a,max( lv_b , lv_c)) << endl;
 
    }
    return 0;
}