#include<iostream>
#include<cstring>
using namespace std;
int test=1;
int n,m;
const int n_max=1000;
typedef long long ll;
int f[n_max+1][n_max+1]; // i 位置之前（包括i）总共有j个传送器 且i是连续的第k个
const int mod=1e9+7;


int func()
{
    memset(f,0,sizeof(f));
    
    for(int i=1;i<=n;i++)
    {
        f[i][0]=1; //没有传送器的方案数都是1种
        for(int j=1;j<=m;j++)
        {
            int temp=1;
            for(int k=1;k<=11; k++)
            {
                if(i-k<=0 || j-(k-1) <0)
                    break;
                if(k==1)
                temp = 1 ;
                else
                temp=(ll)temp*(i-k)%mod;

                f[i][j]=(f[i][j]+(ll)f[i-k][j-(k-1)]*temp)%mod;
            }

        }
    }
    if (f[n][m]!=0)
    return f[n][m];
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
