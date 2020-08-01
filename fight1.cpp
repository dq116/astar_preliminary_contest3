#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int test=1;
int a[3]; //攻击力
int hp[3]; //血量
int mini; //最小回合数
int func() // 枚举（0，1）（ 0，2） 对打的回合的次数 计算 1，2 对打的回合次数
{
    int d;
    mini=100000;
    //int num0_1_max =1000; 遍历数量设置成最大的1000也是可以的
    int num0_1_max=ceil(1000*1.0/a[1]);
    for(int i=0;i<=num0_1_max;i++)
    {
        //int num0_2_max=1000; 遍历数量设置成最大的1000也是可以的
        hp[0]=1000-i*a[1];
        int num0_2_max=ceil(hp[0]*1.0/a[2]);
        if (hp[0]<=0)
        num0_2_max=0;
        
        for(int j=0;j<=num0_2_max;j++)
        {
            hp[0]=1000-i*a[1]-j*a[2];
            hp[1]=1000-i*a[0];
            hp[2]=1000-j*a[0];
            d=0;
            for(int k=0;k<3;k++)
            {
                if(hp[k]<=0)
                d++;
            }
            if(d>=2) //（0,1）（0,2） 打完后已经有两个血量小于等于0
            {
                mini=min(mini,i+j);
                continue;
            }
            int num1_2=min(ceil(hp[1]*1.0/a[2]),ceil(hp[2]*1.0/a[1])); //1，2对打分出胜负所需最小回合数
            hp[1]-=num1_2*a[2];
            hp[2]-=num1_2*a[1];
            d=0;
            for(int k=0;k<3;k++)
            {
                if(hp[k]<=0)
                d++;
            }
            if(d>=2)
            {
                mini=min(mini,i+j+num1_2);
            }

        }

    }
    return mini;

}
int main()
{   cin>>test;
    for(int k=0;k<test; k++)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        cout<<func()<<endl;
    }
}
