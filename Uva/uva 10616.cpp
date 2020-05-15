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

int n,q;
int d,m;

//int dp[205][25][13];

map<pair<int,pair<int,int>> ,int> mm;

vector<int> val;

int knap(int id,int bag1,int keep){

    if(keep>m)return 0;

    if(id>=val.size()){
        if(keep==m){
            if(bag1%d==0){
                return 1;
            }
            else
                return 0;
        }
        else return 0;
    }


    if(keep==m){
        if(bag1%d==0){
            return 1;
        }
        else return 0;
    }

   /* if(dp[id][bag1][keep]!=-1){
        return dp[id][bag1][keep];
    }*/



    if( mm.count({id,{bag1,keep}})){
        return mm[ {id,{bag1,keep}} ];
    }


    int p1=0;


    p1 = knap(id+1, (bag1+val[id]) % d,keep+1);
    int p2 = knap(id+1,(bag1 % d),keep);

    return mm[{id,{bag1,keep}}] = p1 + p2;
}

int main(void){

   // READ_IN;
   // READ_OUT;

    int f=0;

    while(cin >> n >> q){

    if(n==0 && q==0)break;

    f++;

    val.clear();
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        val.push_back(x);
    }

    cout << "SET " << f << ":" << endl;
    int ff=0;

    for(int i=0;i<q;i++){
        cin >> d >> m;
        ff++;

      mm.clear();
      cout << "QUERY " << ff << ": ";
      cout << knap(0,0,0) << endl;
    }
    }

    return 0;
}
