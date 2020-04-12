//Md Fahad
// CSE 18

#include<bits/stdc++.h>

using  namespace  std;

#define PI              acos(-1.0)
#define lcm(a,b)        (a * (b / __gcd(a,b)))
#define en '\n'

#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);
#define Infi                0x3f3f3f3f

const int fx[] = {+1,-1,+0,+0};                         // 4 X directions
const int fy[] = {+0,+0,+1,-1};                         // 4 Y directions
const int fx8[] = {+0,+0,+1,-1,-1,+1,-1,+1};            // King X Moves
const int fy8[] = {-1,+1,+0,+0,+1,+1,-1,-1};            // King Y Moves
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

const int maxe = 10;


vector<vector<int>> grid(maxe,vector<int> (maxe,0));
vector<vector<bool>> visited(maxe,vector<bool> (maxe,false));
vector<vector<int>> level(maxe,vector<int> (maxe,0));

void bfs(int x_sos,int y_sos,int x_des,int y_des)
{
    queue<pii> Q;

    Q.push({x_sos,y_sos});

    visited[x_sos][y_sos]=true;

    while(!Q.empty()){

        pii p = Q.front();
        Q.pop();

        int x =p.first;
        int y=p.second;

        for(int i=0;i<8;i++)
        {
            int xx = x+kx[i];
            int yy = y+ky[i];

            if( xx>=1 && xx<=8  && yy>=1 && yy<=8 && visited[xx][yy]==false)
            {
                visited[xx][yy]=true;

                Q.push({xx,yy});

                level[xx][yy]=level[x][y]+1;
            }
        }

    }


}


int main(void)
{
    //READ_IN;
   // READ_OUT;

    map<char,int> mm;

    char ch='a';
    for(int i=1;i<=8;i++)
    {
        mm[ch]=9-i;
        ch++;
    }

    grid.assign(maxe,vector<int> (maxe,0));


    string a,b;

    while(cin >> a>> b)
    {
        level.assign(maxe,vector<int> (maxe,0));
        visited.assign(maxe,vector<bool>(maxe,false));

        char x = (char)a[0];
        int y = (int)a[1]-'0';

        char X = (char)b[0];
        int Y = (int)b[1]-'0';

    bfs(mm[x],y,mm[X],Y);

    int ans = level[mm[X]][Y];

    cout << "To get from "<< a <<" to "<< b <<" takes "<< ans <<" knight moves." << endl;

    }



    return 0;
}


