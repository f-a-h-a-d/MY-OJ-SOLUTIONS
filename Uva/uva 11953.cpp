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




typedef long long int           ll;
typedef unsigned long long int  llu;

int n;

vector<string > grid;

char val = 'A';

void flood_fill(int xx,int yy)
{

    if(grid[xx][yy]=='.')
        return ;

    for(int i=0;i<4;i++)
    {
        int ux = xx+dx[i];
        int uy = yy +dy[i];

        if(ux>=0 && ux<n && uy>=0 && uy<n && ((grid[ux][uy]=='x') || grid[ux][uy]=='@'))
        {

            grid[ux][uy]=val;

            flood_fill(ux,uy);
        }
    }
}

int main(void)
{
    //READ_IN;
    //READ_OUT;

    int tt; cin >> tt;
    int kk=0;

    while(tt--)
    {
        grid.clear();
        kk++;

        cin >> n;
        cin.ignore();

        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;

            grid.push_back(s);
        }

        int cnt=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='x'){
                        cnt++;

                flood_fill(i,j);


                }

            }
        }

        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << grid[i][j];

            }
            cout << endl;
        }*/

        /*4
@x@x
@@@@
....
....*/



        cout << "Case " << kk << ": ";
        cout << cnt << en;
        cin.ignore();
    }



    return 0;
}
