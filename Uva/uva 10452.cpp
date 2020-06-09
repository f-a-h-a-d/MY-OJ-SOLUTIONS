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

const int maxe = 1000;

vector<string> grid;

const int movex[] = { -1, +0, +0};
const int movey[] = { +0, +1 , -1};

#define right 1
#define left 2
#define forth 3

string need = "IEHOVA#";

vector<int> ans;
vector<vector<bool>> visited;
int n,m;

void dfs(int x,int y,int id){

    if(id>=need.size()){

        for(int i=0;i<ans.size();i++){
            if(ans[i]==forth){
                cout << "forth";
            }
            else if(ans[i]==left){
                cout << "left";
            }
            else if(ans[i]==right){
                cout << "right";
            }
            if(i!=ans.size()-1)
            cout << " ";

        }
        cout << endl;
        return ;
    }

    for(int i=0;i<3;i++){

        int xx = x + movex[i];
        int yy = y + movey[i];

        if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]==need[id]){

                if(movey[i]==0){
                    ans.push_back(forth);
                }
                else if(movey[i]==1){
                    ans.push_back(right);

                }
                else if(movey[i]==-1){
                    ans.push_back(left);
                }
                dfs(xx,yy,id+1);

        }
    }

}

int main(void){

    READ_IN;
    READ_OUT;

    int tt;
    cin >> tt;

    while(tt--){

        cin >> n >> m;

        int lastx,lasty,startx,starty;

        grid.clear();
        ans.clear();

        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            grid.push_back(s);

            for(int j=0;j<s.size();j++){
                if(s[j]=='#'){
                    lastx = i;
                    lasty = j;
                }
            }

            for(int j=0;j<s.size();j++){
                if(s[j]=='@'){
                    startx = i;
                    starty = j;
                }
            }

        }

        visited.assign(maxe,vector<bool>(maxe,false));

        dfs(startx,starty,0);
    }

    return 0;
}
