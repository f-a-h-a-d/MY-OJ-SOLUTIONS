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

typedef long long int           ll;
typedef unsigned long long int  llu;

map<string,vector<string>> mm;

  map<string,int> level;
  map<string,bool> visited;
void bfs(string sos,string des)
{
    //trace("OK");

    level.clear();

    queue<string> Q;

    visited[sos]=true;
    level[sos]=0;

    Q.push(sos);

    while(!Q.empty())
    {
        string top = Q.front();
        Q.pop();

        for(int i=0;i<mm[top].size();i++)
        {
            string ck = mm[top][i];
            if(visited.count(ck)==0)
            {
                Q.push(ck);
                    visited[ck]=true;

                    level[ck]=level[top]+1;
            }
        }
    }
}


bool ck_def(string a,string b)
{
    if(a.size()!=b.size())return false;

    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])cnt++;
    }

    if(cnt==1)return true;
    else return false;
}

int main(void)
{
    //READ_IN;
    //READ_OUT;

    int tt; cin >> tt;

    while(tt--)
    {



        //cin.ignore();
        vector<string> ss;
        ss.clear();

        mm.clear();

        string s;
        while(cin >> s){



                if(s=="*")
                break;

            ss.push_back(s);

            cin.ignore();
           // mm[s].push_back("");
        }

        for(int i=0;i<ss.size();i++)
        {
            for(int j=0;j<ss.size();j++)
            {
                    if(i!=j){
                    bool k = ck_def(ss[i],ss[j]);

                    if(k){
                        mm[ss[i]].push_back(ss[j]);
                    }

                    }
            }
        }

        cin.ignore();



        string aa;
        while(getline(cin,aa)){

                if(aa.size()==0)
                break;

                visited.clear();
                level.clear();


                string x,y;
                bool bol = true;
                int cnt=0;
                for(int i=0;i<aa.size();i++)
                {
                    if(aa[i]==' ')bol=false;

                    if(bol==false){

                        if(cnt==1)
                        y+=aa[i];
                        else
                            cnt++;
                    }
                    else if(bol=true)
                        x+=aa[i];
                }

               // trace(x,y);


            bfs(x,y);
            cout << x << " " << y <<" ";
            cout << level[y] << endl;

        }


        if(tt!=0)
        cout << endl;


    }

    return 0;
}
