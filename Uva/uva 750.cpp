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

const int maxe = 100;
int n = 8;

vector<bool> row,col,dig1,dig2;

vector<vector<int>> grid;

vector<vector<int>> ans;

int x,y;
int cnt  = 0;
void make(int c,int send){

    if(c==n)
        {

       // cout << " " << cnt+1 << "      ";

        printf("%2d      ",cnt+1);

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    cout << j+1;
                    if(i!=n-1){
                        cout << " ";
                    }

                }
            }
        }

        cout << endl;

        cnt++;
        return ;
    }

    if(c==y){

        if(row[x]==false && dig1[y+x]==false && dig2[y-x+n-1]==false){
            row[x]= dig1[y+x] = dig2[y-x+n-1] = true;
            //ans.push_back(y);
            grid[x][y]=1;
            make(c+1,send+1);
            grid[x][y]=0;
            //ans.pop_back();
            row[x]= dig1[y+x] = dig2[y-x+n-1] = false;
        }
        return;
    }


    for(int i=0;i<=7;i++){


        if(row[i]==false && dig1[i+c]==false && dig2[c-i+n-1]==false){

            row[i]= dig1[i+c] = dig2[c-i+n-1] = true;

            grid[i][c]=1;
            make(c+1,send+1);
            grid[i][c]=0;

            row[i]= dig1[i+c] = dig2[c-i+n-1] = false;
        }
    }

}

int main(void){

    //READ_IN;
    //READ_OUT;

    int tt;
    cin >> tt;

    while(tt--){

        cin >> x >> y;
        x--;
        y--;


        grid.assign(n,vector<int>(n,0));

        row.assign(maxe,false);

        dig1.assign(maxe,false);
        dig2.assign(maxe,false);

        cnt = 0;

        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl;
        cout << endl;

        make(0,0);
        if(tt!=0)
        cout << endl;
    }

    return 0;
}
