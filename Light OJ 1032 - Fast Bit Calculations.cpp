
/// Light OJ 1032 - Fast Bit Calculations 
/// Time-0.597s
/// Straight Forward Digit DP Problem


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=31;
const int mx=31;/// 9 * 8 = 72
const int sm=160;/// 9*11=99

/// dp[num_of_digit][sum_of_digits][restricted_or_not];
ll dp[maxn][mx][2][2];

ll FUN(string number,int pos,ll sum,bool restricted,int previous)
{
    if(pos==number.length())
    {
       return sum;
    }

    else if(dp[pos][sum][restricted][previous]!=-1) return dp[pos][sum][restricted][previous];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=0;i<=number[pos]-'0';i++)
        {
            if(i==number[pos]-'0')
            {
                res+=FUN(number,pos+1,((i==1)&&(previous))?(sum+1):sum,true,i);
            }
            else
            {
                res+=FUN(number,pos+1,((i==1)&&(previous))?(sum+1):sum,false,i);
            }
        }
        dp[pos][sum][restricted][previous]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0ll;
        for(ll i=0;i<=1;i++)
        {
            res+=FUN(number,pos+1,((i==1)&&(previous))?(sum+1):sum,false,i);
        }
        dp[pos][sum][restricted][previous]=res;
        return res;
    }

}

string to_binary(ll x)
{
    string num="";
    while(x)
    {
        if(x%2==0ll) num=num+'0';
        else num=num+='1';
        x=x>>1ll;
    }
    reverse(num.begin(),num.end());
    return num;
}

int main()

{
    ll a,b;
    int t;
    scanf("%d",&t);
    int caso=0;
   while(t--)
   {
       caso++;
       memset(dp,-1,sizeof(dp));
       scanf("%lld",&b);
       memset(dp,-1,sizeof(dp));
       ll bb=FUN(to_binary(b),0,0ll,true,0ll);
       printf("Case %d: %lld\n",caso,(bb));
   }

   return 0;
}
