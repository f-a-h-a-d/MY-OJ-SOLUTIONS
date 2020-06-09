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
 

 
typedef long long int           ll;
typedef unsigned long long int  llu;
 
typedef pair<int,int> pii;
 
const int maxe = 22;
 
int n,m;
vector<string> graph;
vector<vector<bool>> visited;
vector<vector<int>> level;
 
int mydirty=0;
 
int bfs(int x_sos,int y_sos){
 
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
 
        if((xs>=0 && xs<n) && (ys>=0 && ys<m) && (graph[xs][ys]!='x') && (visited[xs][ys]==false))
        {
 
            if(graph[xs][ys]=='*')mydirty++;
 
            Q.push({xs,ys});
            visited[xs][ys]=true;
            level[xs][ys]=level[p.first][p.second]+1;
        }
 
    }
    }
 
    return mydirty;
}
 
int bfs2(int x_sos,int y_sos,int x_des,int y_des){
 
    visited.assign(maxe,vector<bool>(maxe,false));
    level.assign(maxe,vector<int>(maxe,0));
 
    queue<pair<int,int>> Q;
 
    Q.push({x_sos,y_sos});
    visited[x_sos][y_sos]=true;
 
    while(!Q.empty()){
 
    pii p = Q.front();
    Q.pop();
 
    int x = p.first;
    int y = p.second;
 
    if(x==x_des && y==y_des)return level[x_des][y_des];
 
    for(int j=0;j<4;j++)
    {
        int xs = x+dx[j];
        int ys = y+dy[j];
 
        if((xs>=0 && xs<n) && (ys>=0 && ys<m) && (graph[xs][ys]!='x') && (visited[xs][ys]==false))
        {
 
            Q.push({xs,ys});
            visited[xs][ys]=true;
            level[xs][ys]=level[p.first][p.second]+1;
        }
 
    }
}
 
}
 
vector<pair<int,int>> allnodes;
 
int dp[25][8048];
 
int make(int x,int y,int mask,int cnt,int id){
 
    if(cnt==mydirty)return 0;
 
    if(dp[id][mask]!=-1)return dp[id][mask];
 
    int ans = Infi;
 
    for(int i=0;i<allnodes.size();i++){
 
        if(check(mask,i)==false){
            int a,b;
            tie(a,b) = allnodes[i];
            int dis = bfs2(x,y,a,b);
            ans = min(ans, dis + make(a,b,Set(mask,i),cnt+1,i+1) );
        }
    }
 
    return dp[id][mask] = ans;
}
 
 
 
int main(void){
 
   // READ_IN;
 
    while(cin >> m >> n){
 
    if(m==0 && n==0){
            break;
        }
 
    graph.clear();
 
    for(int i=0;i<n;i++){
        string ss; cin >> ss;
        graph.push_back(ss);
    }
 
    visited.assign(maxe,vector<bool>(maxe,false));
    level.assign(maxe,vector<int>(maxe,0));
 
    allnodes.clear();
 
    int x_init;
    int y_init;
    int dirty=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
            if(graph[i][j]=='o'){
                x_init = i;
                y_init = j;
            }
 
            if(graph[i][j]=='*'){
                allnodes.push_back({i,j});
                dirty++;
            }
        }
    }
    mydirty = 0;
    int val = bfs(x_init,y_init);
 
    if(val != dirty){
        cout << -1 << endl;
        continue;
    }
    int mask = 0;
    memset(dp,-1,sizeof(dp));
    int ans = make(x_init,y_init,mask,0,0);
    cout << ans << endl;
 
    }
 
    return 0;
}