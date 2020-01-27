
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

const int maxe = 10000;

vector<vector<int> > vertice(maxe);

vector<bool> visited(maxe,false);
vector<int> level(maxe,0);

void dfs(int sos,int lev)
{
    queue<int> track;

    track.push(sos);

    visited[sos]=true;

    while(!track.empty()){

        int ckr = track.front();
        track.pop();


        if(level[ckr]==lev)
            return ;

        for(int i=0;i<vertice[ckr].size();i++)
        {
            int val = vertice[ckr][i];

            if(visited[val]==false)
            {
                level[val]=level[ckr]+1;


                        visited[val]=true;
                track.push(val);

            }
        }

    }


}

int main(void)
{
    //READ_IN;
    //READ_OUT;

    int n;
    int kk=0;

    while(cin >> n)
    {
        if(n==0)
            break;


       for(int i=0;i<vertice.size();i++)
       {
           vertice[i].clear();
       }

        set<int> tot;

        vector<pair<int,int>>pp;

        map<int,int> mm,MM;

        map<int,int> :: iterator it;

        for(int i=0;i<n;i++)
        {
            int x,y;
            cin >> x >> y;

            pp.push_back({x,y});

            mm[x]=0;
            mm[y]=0;

            tot.insert(x);
            tot.insert(y);
        }

        int jj=0;
        for(it=mm.begin();it!=mm.end();it++)
        {
            MM[jj]=it->first;
            it->second=jj;
            jj++;

        }


        for(int i=0;i<n;i++)
        {
            int X = mm[pp[i].first];
            int Y = mm[pp[i].second];

            //trace(X,Y);

            vertice[X].push_back(Y);
            vertice[Y].push_back(X);
        }

        int sos,lev;

        int total_val = tot.size();

        while(cin >> sos){

                cin >> lev;

        if(sos==0 && lev==0)
                break;





        visited.assign(maxe,false);
        level.assign(maxe,0);

             kk++;

             if(tot.count(sos)==0)
                {
                    cout << "Case " << kk << ": ";
                    cout << total_val << " nodes not reachable from node " << sos << " with TTL = " << lev << "." << endl;
                    continue;
                }



                if(lev==0)
                {
                    cout << "Case " << kk << ": ";
                    cout << total_val-1 << " nodes not reachable from node " << sos << " with TTL = " << lev << "." << endl;

                    continue;
                }



            dfs(mm[sos],lev);
            int cnt=0;
            for(int i=0;i<maxe;i++)
            {
                if(visited[i])
                    cnt++;
            }
            int ans = total_val-cnt;

            visited.clear();
            level.clear();


            cout << "Case " << kk << ": ";
            cout << ans << " nodes not reachable from node " << sos << " with TTL = " << lev << "." << endl;
        }

        tot.clear();


    }




    return 0;
}


