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
 
const int maxe = 100005;
 
vector<bool> visited;
 
vector<int> primes;
void seive(int n)
{
    vector <bool> fahad(n+1,true);
 
    fahad[0]=fahad[1]=false;
 
    for( int i=4;i<=n;i+=2)
        fahad[i]=false;
 
     int s = sqrt(n)+1;
 
    for( int i=3;i<=s;i+=2)
    {
        if(fahad[i]==true)
        {
            for( int j=i*i;j<=n;j+=i)
            {
                fahad[j]=false;
            }
        }
    }
 
    primes.push_back(2);
 
    for(int i=3;i<=n;i+=2)
    {
        if(fahad[i]==true)
            primes.push_back(i);
    }
 
}
 
vector<int> node[maxe];
vector<int> level;
void fac(int n){
 
    int id = n;
    for(int i=0;i<primes.size();i++){
 
 
 
 
            if(n%primes[i]==0 && n>primes[i]){
                   // trace(primes[i]);
                //n=n/primes[i];
                node[id].push_back(primes[i]);
            }
 
        }
 
 
}
 
int bfs(int sos,int des){
 
    queue<int> Q;
 
    Q.push(sos);
    visited[sos]=true;
 
    while(!Q.empty()){
 
            int u = Q.front();
            Q.pop();
 
            if(u==des){
                return level[u];
            }
 
 
 
            for(auto it: node[u]){
 
                    int x = it;
                    if(visited[u+it]==false && u+it<=des){
                    Q.push(u+it);
                    visited[u+it]=true;
                    level[u+x]=level[u]+1;
                    }
            }
 
 
    }
    return -1;
 
}
 
int main(void){
    seive(100005);
 
    for(int i=2;i<=1002;i++){
        fac(i);
    }
 
    int tt;
    cin >> tt;
 
    for(int kk=1;kk<=tt;kk++){
        int s,t;
        cin >> s >> t;
        visited.assign(maxe,false);
 
        level.assign(maxe,0);
 
        fac(s);
        int ck = bfs(s,t);
        cout << "Case " << kk << ": ";
        if(ck==-1){
            cout << -1 << endl;
        }
        else{
            cout << ck << endl;
        }
    }
 
    return 0;
}