

/// Time-0.300s
/// LightOJ - 1140 - How Many Zeroes? 
/// A nice one 
/// Digit DP 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=16;
const int mx=91;/// 9 * 8 = 72
const int sm=160;/// 9*11=99

/// dp[num_of_digit][sum_of_digits][restricted_or_not][starting_with_zero];
ll dp[maxn][sm][2][2];
int total_dig;

ll FUN(string number,int pos,ll sum,bool restricted,bool start)
{
    if(pos==number.length()) return sum;

    else if(dp[pos][sum][restricted][start]!=-1) return dp[pos][sum][restricted][start];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=0;i<=number[pos]-'0';i++)
        {
            if(i==number[pos]-'0')
            {
                res+=FUN(number,pos+1,start?0:(sum+(i==0)),true,i==0&&start);
            }
            else
            {
                res+=FUN(number,pos+1,start?0:(sum+(i==0)),false,i==0&&start);
            }
        }
        dp[pos][sum][restricted][start]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0ll;
        for(ll i=0;i<=9;i++)
        {
            res+=FUN(number,pos+1,start?0:(sum+(i==0)),false,i==0&&start);
        }
        dp[pos][sum][restricted][start]=res;
        return res;
    }

}

int main()

{
    ll a,b;
    int t;
    cin>>t;
    int caso=0;
   while(t--)
   {
       caso++;
       memset(dp,-1,sizeof(dp));
       scanf("%lld%lld",&a,&b);
       ll aa=FUN(a>0?to_string(a-1):to_string(0),0,0ll,true,1);
       if(a!=0) aa=aa+1ll;
       memset(dp,-1,sizeof(dp));
       ll bb=FUN(to_string(b),0,0ll,true,1);
       bb=bb+1ll;
       printf("Case %d: %lld\n",caso,(bb-aa));
   }

   return 0;
}
