#include<bits/stdc++.h>

using namespace std;

void code(int n)
{


    unsigned int a[100005];

    int s=1;
    a[0]=1;

    int carry=0;

    for(int i=2;i<=n;i++)
    {
        carry=0;

        for(int j=0;j<s;j++){

        int value = a[j]*i+carry;

        a[j]=value%10;
        carry= value/10;

        }



        while(carry!=0)
        {
            a[s]=carry%10;
            carry=carry/10;
            s++;
        }

    }

    cout << n << "!" << endl;

    for(int i=s-1;i>=0;i--)
    {
        cout << a[i];
    }

    cout << endl;


}


int main(void)
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {

        code(n);
    }

    return 0;
}
