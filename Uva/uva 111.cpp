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

//vector<int> index(100,0);
//vector<int> indexs(100,0);
int inde[50],indexs[50];
vector<int> ar;
int n;
int dp[50];
int LIS(int id){

    if(dp[id]!=-1)return dp[id];

    int ans = 0;
    for(int i=id+1;i<=n;i++){

        if(inde[ar[i-1]]>inde[ar[id-1]]){
           // trace(index[i],index[id]);
            ans = max(ans,1+LIS(i));
            //trace(ans);
        }
    }
    return dp[id] = ans;

}


int main(void){

    //READ_IN;
    //READ_OUT;


        string s;
        getline(cin,s);

        stringstream sf(s);
        sf >> n;

            memset(dp,-1,sizeof(dp));

            string st;
            getline(cin,st);

                stringstream ss(st);

                int val;
                int cnt=1;

                memset(inde,0,sizeof(inde));

                while(ss>>val){

                    inde[cnt]=val;
                    cnt++;
                }

                while(getline(cin,st)){

                        memset(dp,-1,sizeof(dp));

                        if(st[0]=='\0')
                        return 0;

                    stringstream ss(st);
                    int val;

                    ar.clear();

                    memset(indexs,0,sizeof(indexs));

                    int cnt=1;
                    while(ss>>val){

                    indexs[val]=cnt;
                    cnt++;
                    }

                    if(cnt==2){
                        n = val;
                        break;
                    }

                    int ans = 0;

                    for(int i=1;i<=n;i++){
                        ar.push_back(indexs[i]);
                    }

                    for(int i=1;i<=n;i++){
                        ans = max(ans,LIS(i));

                    }
                    cout << ans+1 << '\n';


                }





    return  0;
}
