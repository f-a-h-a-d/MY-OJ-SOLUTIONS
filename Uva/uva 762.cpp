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

const int maxe = 1000;

vector<int> parent(maxe,0);
vector<bool> visited(maxe,false);
vector<int> level(maxe,0);

vector<vector<int> > finar(maxe);

bool bfs(int sos,int des)
{


    queue<int> q;

    q.push(sos);


    parent[sos]=sos;
    visited[sos]=true;

    while(!q.empty())
    {
        int track = q.front();
        q.pop();

        //visited[track]=true;

        if(des==track)
            return true;

        for(int i=0;i<finar[track].size();i++)
        {
            int val = finar[track][i];
            if(visited[val]==false)
            {
                visited[val]=true;
                parent[val]=track;
                    q.push(val);
            }
        }
    }
    return false;
}



int main(void)
{
    //READ_IN;
    //READ_OUT;

    int n;

    int ck=0;
    while(cin >> n){

            if(ck>=1)
            cout << endl;

            ck++;

            parent.assign(maxe,0);
            visited.assign(maxe,false);
            finar.assign(maxe,vector<int>());


    vector<string> a,b;

    map<string,int> mm;
    map<string,int> :: iterator it;

    for(int i=0;i<n;i++)
    {
        string x,y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        mm[x]=0;
        mm[y]=0;

    }
    int i=0;
    for(it= mm.begin();it!=mm.end();it++)
    {
        it->second = i;
        i++;
    }

    map<int,string> another;

    for(it= mm.begin();it!=mm.end();it++){
        another[it->second]=it->first;

        //trace(it.second,it.first);

    }

    string x,y;
    cin >> x >> y;

    int source,des;

    if(mm.count(x)==1)
    source = mm[x];

        if(mm.count(y)==1)
    des = mm[y];


    for(int i=0;i<a.size();i++)
    {
        int fir = mm[a[i]];
        int sec = mm[b[i]];

        //trace(fir,sec);

        finar[fir].push_back(sec);
        finar[sec].push_back(fir);
    }



    vector<string> ma_ans;

    if(x==y){
        cout << x << " " << y << endl;
    }
    else if(mm.count(x)==false || mm.count(y)==false){

            cout << "No route"<< endl;
    }
    else if(bfs(source,des))
    {
        while(parent[des]!=des){
        int A = des;
        int B = parent[des];
        ma_ans.push_back(another[A]);
        ma_ans.push_back(another[B]);
        des = B;

        }
        reverse(ma_ans.begin(),ma_ans.end());

        for(int i=0;i<ma_ans.size();i+=2)
        {
            cout << ma_ans[i] << " " << ma_ans[i+1] << endl;

        }


    }
    else
    {
        cout << "No route" << endl;
    }

    mm.clear();
    another.clear();

    }

    return 0;
}

