
/// Light OJ -1068 - Investigation 
/// Straight Forward Digit DP Problem 


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=11;
const int mx=85;/// 9 * 8 = 72
const int sm=160;/// 9*11=99

/// dp[num_of_digit][sum_of_digits][restricted_or_not];
ll dp[maxn][mx][2][mx];
int total_dig;
ll mod;

ll FUN(string number,int pos,ll sum,bool restricted,ll rem)
{
    if(pos==number.length())
    {
        if(sum%mod==0 && rem%mod==0) return 1ll;
         else  return 0ll;
    }

    else if(dp[pos][sum][restricted][rem]!=-1) return dp[pos][sum][restricted][rem];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=0;i<=number[pos]-'0';i++)
        {
            if(i==number[pos]-'0')
            {
                res+=FUN(number,pos+1,(sum+i)%mod,true,(rem*10ll+i)%mod);
            }
            else
            {
                res+=FUN(number,pos+1,(sum+i)%mod,false,(rem*10ll+i)%mod);
            }
        }
        dp[pos][sum][restricted][rem]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0ll;
        for(ll i=0;i<=9;i++)
        {
            res+=FUN(number,pos+1,(sum+i)%mod,false,(rem*10ll+i)%mod);
        }
        dp[pos][sum][restricted][rem]=res;
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
       scanf("%lld%lld%lld",&a,&b,&mod);
       ll aa=FUN(to_string(a-1),0,0ll,true,0ll);
       memset(dp,-1,sizeof(dp));
       ll bb=FUN(to_string(b),0,0ll,true,0ll);
       printf("Case %d: %lld\n",caso,(bb-aa));
   }

   return 0;
}
