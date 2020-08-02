#include<bits/stdc++.h>
 
using  namespace  std;
 
#define PI              acos(-1.0)
#define lcm(a,b)        (a * (b / __gcd(a,b)))
#define en '\n'
 
#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);
#define Infi                0x3f3f3f3f
 
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
 
const int maxe = 25;
 
vector<string> graph;
vector<vector<bool>> visited;
int row,col;
 
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
        //trace(row,col);
 
        if((xs>=0 && xs<row) && (ys>=0 && ys<col) && graph[xs][ys]!='#' && (visited[xs][ys]==false))
        {
            //trace("YYYYYY");
            Q.push({xs,ys});
            visited[xs][ys]=true;
            graph[xs][ys]='p';
 
        }
    }
 
 
    }
 
}
 
 
 
int main(void){
    //READ_IN;
 
    int tt;
    cin >> tt;
 
    for(int kk = 0;kk<tt;kk++){
 
        graph.clear();
        int w,h;
        cin >> w >> h;
        row = h;
        col = w;
 
        for(int i=0;i<h;i++){
            string ss; cin >> ss;
            graph.push_back(ss);
        }
 
        int xx,yy;
 
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                    if(graph[i][j]=='@'){
                xx = i;
                yy = j;
                    }
 
            }
        }
 
        //trace(xx,yy);
 
    visited.assign(maxe,vector<bool>(maxe,false));
 
    bfs(xx,yy);
    int ans = 0;
    for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                    //cout << graph[i][j];
                    if(graph[i][j]=='p'){
                        ans++;
                    }
 
            }
           // cout << endl;
        }
        cout << "Case " << kk+1 << ": "  << ans+1 << endl;
 
    }
 
    return 0;
}