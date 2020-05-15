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

vector<vector<int>> vec;

int dp[25][25][10005];


int make(int idone ,int idtwo,int val){


    if(idone>=vec.size()){
        return val;
    }

    if(dp[idone][idtwo][val]!=-1){
        return dp[idone][idtwo][val];
    }


    int ans1=Infi;
    int ans2=Infi;
    int ans3=Infi;

    if(idtwo==0){
            int x = make(idone+1,1,val+vec[idone][0]);
           int y = make(idone+1,2,val+vec[idone][0]);

            ans1 = min(x,y);
    }
    else if(idtwo==1){
        int x = make(idone+1,0,val+vec[idone][1]);
       int y = make(idone+1,2,val+vec[idone][1]);

       ans2 = min(x,y);
    }
    else if(idtwo==2){
        int x  = make(idone+1,0,val+vec[idone][2]);
        int y  = make(idone+1,1,val+vec[idone][2]);
        ans3 = min(x,y);
    }
    return  dp[idone][idtwo][val] = min(ans1,min(ans2,ans3));
}

int main(void){

   // READ_IN;
   // READ_OUT;

    int tt;
    scanf("%d",&tt);

    for(int ff=1;ff<=tt;ff++){

        int n;
        scanf("%d",&n);
        vec.clear();
        vec.assign(n,vector<int>());

        for(int i=0;i<=23;i++){
            for(int j=0;j<=23;j++){
                for(int k=0;k<=10004;k++){
                    dp[i][j][k]=-1;
                }
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<3;j++){
                int x;
                scanf("%d",&x);
                vec[i].push_back(x);
            }
        }
        int ans = make(0,0,0);
        int ans1 = make(0,1,0);
        int ans2 = make(0,2,0);


        printf("Case ");
        printf("%d",ff);
        printf(": ");
        printf("%d\n",min(ans,min(ans1,ans2)));


    }



    return 0;
}
