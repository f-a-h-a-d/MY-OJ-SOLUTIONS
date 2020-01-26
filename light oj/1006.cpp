#include<bits/stdc++.h>

using namespace std;

#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);



vector<int> dp(10019,-1);
int a, b, c, d, e, f;
int fn( int n ) {
    if( n == 0 ) return a%10000007;
    if( n == 1 ) return b%10000007;
    if( n == 2 ) return c%10000007;
    if( n == 3 ) return d%10000007;
    if( n == 4 ) return e%10000007;
    if( n == 5 ) return f%10000007;

    int A,B,C,D,E,F;

    if(dp[n-1]!=-1)
        A= dp[n-1];
        else{
        A = fn(n-1)%10000007;
        dp[n-1]=A;
        }

    if(dp[n-2]!=-1)
    B=dp[n-2];
    else{
        B = fn(n-2)%10000007;
     dp[n-2]=B;
    }

    if(dp[n-3]!=-1)
        C=dp[n-3];
    else{
        C = fn(n-3)%10000007;
     dp[n-3]=C;
    }

    if(dp[n-4]!=-1)
        D = dp[n-4];
    else{
        D = fn(n-4)%10000007;
        dp[n-4]=D;
    }
    if(dp[n-5]!=-1)
        E=dp[n-5];
    else{
        E = fn(n-5)%10000007;
        dp[n-5]=E;
    }
    if(dp[n-6]!=-1)
        F=dp[n-6];
    else{
        F=fn(n-6)%10000007;
        dp[n-6]=F;
    }

    return( A%10000007+B%10000007+C%10000007+D%10000007+E%10000007+F%10000007 )%10000007;
}
int main() {



    //READ_IN;

    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {

        for(int i=0;i<dp.size();i++)
            dp[i]=-1;

        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);

    }
    return 0;
}
