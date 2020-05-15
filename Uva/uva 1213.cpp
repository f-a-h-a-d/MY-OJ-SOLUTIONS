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

vector<int> primes;
void seive(int n)
{
    vector <bool> fahad(n+1,true);

    fahad[0]=fahad[1]=false;

    for(int i=4;i<=n;i+=2)
        fahad[i]=false;

     int s = sqrt(n)+1;

    for( int i=3;i<=s;i+=2)
    {
        if(fahad[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
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

vector<int> val;
int n,K;
vector<int> cker;

int dp[200][1300][17];

int knap_s(int id,int sum,int k){

    if(sum==n && k==K){
            //trace(cker);
            return 1;
    }
    if(sum>n)return 0;

    if(id>=val.size()){
        return 0;
    }

    if(dp[id][sum][k]!=-1){
        return dp[id][sum][k];
    }

    int p1 =0;
    if(k<K){
    //cker.push_back(val[id]);
     p1 = knap_s(id+1,sum+val[id],k+1);
     //cker.pop_back();
    }
    int p2 = knap_s(id+1,sum,k);

    return dp[id][sum][k] = p1+p2;
}

int main(void){

    //READ_IN;

    seive(1300);

    while(cin >> n >> K){

            if(n==0 && K==0)break;

        val.clear();

        for(int i=0;primes[i]<=n;i++){
            val.push_back(primes[i]);
        }

        memset(dp,-1,sizeof(dp));

        cout << knap_s(0,0,0) << endl;

    }


    return 0;
}
