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

vector<int> parent;
void make(int n)
{
    for(int i=1;i<=n;i++)
    parent[i]=i;
}
int Find(int A)
{
    if(parent[A]!=A){
         parent[A]= Find(parent[A]);
         return parent[A];
    }
    else{
        return A;
    }

}
void un(int A,int B)
{

    int p = Find(A);
    int q = Find(B);

    if(q==p){
        return;
    }
    else
    parent[p]=q;
}

bool ck(int A,int B){

    int p=Find(A);
    int q=Find(B);

    //if(p==q)cout << "X" << endl;

    if(p==q){
        return true;
    }
    else{
        return false;
    }
}



int main(void){

    READ_IN;
    READ_OUT;

    int tt;
    scanf("%d",&tt);

    for(int i=1;i<=tt;i++){

        int n;
        scanf("\n%d\n",&n);
        parent.assign(n+3,0);

        make(n);


        int cntT=0,cntF=0;

        char ch;
        int a,b;
        string s;
        //cin.ignore();
        while(1){

            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&ch,&a,&b);


            if(ch=='c'){

                un(a,b);
            }
            else{

                bool bol = ck(a,b);
                //trace(bol);
                if(bol){
                    cntT++;
                }
                else{
                    cntF++;
                }
            }


        }
        cout << cntT << "," << cntF << endl;
        if(i!=tt)
        cout << endl;
    }

    return 0;
}
