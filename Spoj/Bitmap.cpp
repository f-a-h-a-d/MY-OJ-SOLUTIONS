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
 
const int maxe = 200;
 
vector<vector<int>> total;
int n,m;
queue<pair<int,int>> Q;
 
int main(void){
    int tt;cin >> tt;
 
    while(tt--){
 
        cin >> n >> m;
 
        total.assign(n,vector<int>(m,-1));
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
 
                char x;
                cin >> x;

                if(x=='1'){
                    Q.push({i,j});
                    total[i][j]=0;
                }
            }
        }
  while(!Q.empty()){
 
    pii p = Q.front();
    Q.pop();
 
    int x = p.first;
    int y = p.second;
 
 
    for(int j=0;j<4;j++)
    {
        int xs = x+dx[j];
        int ys = y+dy[j];
 
 
        if(xs>=0 && xs<n && ys>=0 && ys<m  && total[xs][ys]==-1)
        {
            Q.push({xs,ys});
 
            total[xs][ys]=total[p.first][p.second]+1;
        }
    }
}
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << total[i][j] <<  " ";
            }
            cout << endl;
        }
        total.clear();
 
 
    }
 
    return 0;
}