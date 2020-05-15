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

typedef long long int  ll;
typedef unsigned long long int llu;

ll par[100004],tot_connected_nodes_of[100004];


ll FindParent(ll node){
    if(par[node]==node)
        return par[node];
    else{
        return par[node]=FindParent(par[node]);
    }
}

ll Union(ll node1,ll node2){
    ll parent1,parent2;

    parent1=FindParent(node1);
    parent2=FindParent(node2);

    if(parent1==parent2){
        return tot_connected_nodes_of[parent1];
    }
    if(tot_connected_nodes_of[parent1]>=tot_connected_nodes_of[parent2]){
        tot_connected_nodes_of[parent1]+=tot_connected_nodes_of[parent2];
        //tot_connected_nodes_of[parent2]+=tot_connected_nodes_of[parent1];
        par[parent2]=parent1;

        return tot_connected_nodes_of[parent1];
    }
    else{
        //tot_connected_nodes_of[parent1]+=tot_connected_nodes_of[parent2];
        tot_connected_nodes_of[parent2]+=tot_connected_nodes_of[parent1];
        par[parent1]=parent2;

        return tot_connected_nodes_of[parent2];
    }
}

void Initialize(){
    for(ll i=0;i<100004;i++){
        par[i]=i;
        tot_connected_nodes_of[i]=1;
    }
}

int main(void){

    //READ_IN;
    //READ_OUT;

    int tt;
    cin >> tt;

    while(tt--){

        Initialize();

        int n; cin >> n;

        vector<pair<string,string>> vec;
        set<string> s;
        for(int i=0;i<n;i++){
            string a,b;
            cin >> a >> b;

            vec.push_back({a,b});
            s.insert(a);
            s.insert(b);
        }
        map<string,int> from;
       // map<int,string> to;
        int cnt=1;
        for(auto it : s){

            from[it]=cnt;
            //to[cnt]=it;
            cnt++;
        }

        for(int i=0;i<vec.size();i++){
            string a,b;
            a = vec[i].first;
            b = vec[i].second;

            int x = from[a];
            int y = from[b];
            ll g = Union(x,y);
            cout << g << endl;
        }

        s.clear();
        from.clear();
        vec.clear();

    }

    return 0;
}
