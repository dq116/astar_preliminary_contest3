#include<iostream>
#include<cstring>
using namespace std;
int test=1;
int n,m;
const int n_max=1000;
int f[n_max+1][n_max-1][10+1]; // i 位置之前（包括i）总共有j个传送器 且i是连续的第k个
const int mod=1e9+7;
typedef long long ll;

int func()
{
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        f[i][0][0]=1; //没有传送器的方案数都是1种
        for(int j=1;j<=m;j++) 
        {
            for(int k=0;k<=10; k++)
            {

                f[i][j][0]=(f[i][j][0]+f[i-1][j][k])%mod;
                //cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<" f0: "<<f[i][j][0]<<endl;
                if (k!=0)
                {
                    if(f[i-1][j-1][k-1]==0) //可以起到一定的加速作用不至于TLE
                    continue;
                    f[i][j][k]=(ll)f[i-1][j-1][k-1]*(i-1)%mod;
                    //cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<" f: "<<f[i][j][k]<<endl;
                }
                //你也可以算f[i+1][j][0]
                //f[i+1][j][0]=(f[i+1][j][0]+f[i][j][k])%mod;
                //cout<<"i+1: "<<i+1<<" j: "<<j<<" f: "<<f[i+1][j][0]<<endl;
            }

        }
    }
    if (f[n][m][0]!=0)
    return f[n][m][0];
    else
    return -1;
}
int main()
{   cin>>test;
    for(int k=0;k<test; k++)
    {
        cin>>n>>m;
        if(m<=n-2 || m==0)
        cout<<func()<<endl;
        else
        cout<<-1<<endl;
    }
}
