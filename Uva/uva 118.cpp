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

vector<vector<int>> grid;
int n,m;
char pos;
int x,y;
bool cker(char ch){

    if(ch=='R'){
        if(pos=='N'){
            pos = 'E';
        }
        else if(pos=='E'){
            pos = 'S';
        }
        else if(pos=='S'){
            pos = 'W';
        }
        else if(pos=='W'){
            pos = 'N';
        }
    }
    else if(ch=='L'){
        if(pos=='N'){
            pos = 'W';
        }
        else if(pos=='E'){
            pos = 'N';
        }
        else if(pos=='S'){
            pos = 'E';
        }
        else if(pos=='W'){
            pos = 'S';
        }
    }
    else if(ch=='F'){
            int prex=x;
            int prey=y;
        if(pos=='N'){
            y=y+1;
        }
        else if(pos=='E'){
            x=x+1;
        }
        else if(pos=='S'){
            y=y-1;
        }
        else if(pos=='W'){
            x=x-1;
        }

        if(x<0 || x>n || y<0 || y>m){

                if(grid[prex][prey]==-1){
                        x = prex;
                        y = prey;
                    return true;
                }

            cout << prex << " " << prey << " " << pos << " " << "LOST" << endl;
            grid[prex][prey]=-1;
            return false;
        }
    }

    return true;
}

int main(void){
    READ_IN;

    cin >> n >> m;

    grid.assign(n+1,vector<int>(m+1,0));
    char ch;
    while(cin >> x >> y >> ch){
            pos = ch;
            string s;
            cin >> s;
            bool bol;
            for(int i=0;i<s.size();i++){
                 bol =cker(s[i]);
                if(bol==false)break;
            }
            if(bol)
            cout << x << " " << y << " " << pos << endl;

    }

    return 0;
}
