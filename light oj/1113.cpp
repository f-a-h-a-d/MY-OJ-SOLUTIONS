#include<bits/stdc++.h>

using  namespace  std;

#define PI              acos(-1.0)
#define lcm(a,b)        (a * (b / __gcd(a,b)))
#define en '\n'

#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);


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

string light = "http://www.lightoj.com/";

int main(void)
{
    //READ_IN

    int tt; cin >> tt;

    for(int i=1;i<=tt;i++)
    {
        cout << "Case "<< i << ":" << endl;
        stack<string> ff;
        stack<string> bb;
        //bb.push(light);
        string cur;
        cur = light;
        string cmd;
        while(cin >> cmd)
        {
            if(cmd=="QUIT")
                break;

            if(cmd == "VISIT")
            {

                while(!ff.empty()){ff.pop();}

                bb.push(cur);
                string s; cin >> s;
                cur = s;

                cout << cur << endl;
            }
            else if(cmd == "BACK")
            {
                if(!bb.empty()){
                ff.push(cur);
                //cout << cur << endl;
                cur = bb.top();
                bb.pop();
                cout << cur << endl;
                }
                else
                    cout << "Ignored" << endl;

            }
            else
            {
                if(!ff.empty()){
                bb.push(cur);
                //cout << cur << endl;
                cur = ff.top();
                ff.pop();
                cout << cur << endl;
                }
                else
                   cout << "Ignored" << endl;
            }
        }



    }

    return 0;
}

