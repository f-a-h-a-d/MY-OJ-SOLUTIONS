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

const int maxe = 100005;
vector<int> ar(maxe);
vector<int> tree_max(maxe*3),tree_min(maxe*3);

void build_max(int node,int b,int e)
{
    if(b==e)
    {
        tree_max[node]=ar[b];
        return ;
    }

    int left = node*2;
    int right = node*2 +1 ;

    int mid = (b+e)/2;

    build_max(left,b,mid);
    build_max(right,mid+1,e);

        tree_max[node] = max(tree_max[left],tree_max[right]);

}

int cke_max(int node ,int b,int e,int i,int j)
{
    if(i>e || j<b)
    {
        return 0;
    }

    if(b>=i && e<=j)
    {
        return tree_max[node];
    }

    int left = node*2;
    int right = node*2+1;

    int mid = (b+e)/2;

    int p1 = cke_max(left,b,mid,i,j);
    int p2 = cke_max(right,mid+1,e,i,j);

    return max(p1,p2);

}

void build_min(int node,int b,int e)
{
    if(b==e)
    {
        tree_min[node]=ar[b];
        return ;
    }

    int left = node*2;
    int right = node*2 +1 ;

    int mid = (b+e)/2;

    build_min(left,b,mid);
    build_min(right,mid+1,e);

        tree_min[node] = min(tree_min[left],tree_min[right]);

}

int cke_min(int node ,int b,int e,int i,int j)
{
    if(i>e || j<b)
    {
        return 1000000;
    }

    if(b>=i && e<=j)
    {
        return tree_min[node];
    }

    int left = node*2;
    int right = node*2+1;

    int mid = (b+e)/2;

    int p1 = cke_min(left,b,mid,i,j);
    int p2 = cke_min(right,mid+1,e,i,j);

    return min(p1,p2);

}


int main(void)
{
    READ_IN;

    int tt;
    scanf("%d",&tt);

    for(int i=1;i<=tt;i++)
    {
        int n,d;
        scanf("%d %d",&n,&d);

        for(int j=1;j<=n;j++)
        {
            scanf("%d",&ar[j]);
        }



        build_max(1,1,n);
        build_min(1,1,n);
        int ans = 0;



        for(int j=1;j<=n-d+1;j++)
        {
            int s = cke_max(1,1,n,j,j+d-1);
            int s2 = cke_min(1,1,n,j,j+d-1);

            ans = max(ans,abs(s-s2));
        }

        printf("Case ");
        printf("%d",i);
        printf(": ");
        printf("%d",ans);
        printf("\n");
        tree_max.clear();
        tree_min.clear();
        ar.clear();

    }

    return 0;
}
