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


int main(void)
{
    //READ_IN;
    int tt; cin >> tt;

    for(int i=1;i<=tt;i++)
    {
        int n,m; cin >> n >> m;
        deque<int> kk;
        cout << "Case " << i << ":" << endl;

        while(m--)
        {
            string ss; cin >> ss;
            int a;
            if(ss=="pushLeft" || ss=="pushRight"){
             cin >> a;
            }

            if(ss=="pushLeft" && kk.size()<=n)
            {
                    if(kk.size()>=n){
                    cout << "The queue is full" << endl;
                        }
                        else{
                kk.push_front(a);
                cout << "Pushed in left: " << a << endl;
                        }
            }
            else if(ss=="pushRight" && kk.size()<=n)
            {
                if(kk.size()>=n){
                    cout << "The queue is full" << endl;
                }
                else{
                kk.push_back(a);
                cout << "Pushed in right: " << a << endl;
                }
            }
            else if(ss=="popLeft" && kk.size()<=n && !kk.empty())
            {
                int b = kk.front();
                kk.pop_front();
                cout << "Popped from left: " << b << endl;
            }
            else if(ss=="popRight" && kk.size()<=n && !kk.empty())
            {
                int b = kk.back();
                kk.pop_back();
                cout << "Popped from right: " << b << endl;
            }
            else if(kk.empty())
            {
                cout << "The queue is empty" << endl;
            }
        }
    }



    return 0;
}
