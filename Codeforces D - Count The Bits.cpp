#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define ll long long
int  dp[130][1010][130],ans;
int n,k;

ll fun(int pos,ll rem,bool flag,ll  ss)
{
    if(pos==n)return rem==0?ss%mod:0ll;

    if(!flag && dp[pos][rem][ss]!=-1)return (dp[pos][rem][ss])%mod;

    ll sum=0ll;

    for(int i=0; i<=1; i++)
        sum=(sum+fun(pos+1,(rem*2ll+i)%k,flag&&i==1,i==1?(ss+1ll)%mod:ss%mod))%mod;

    dp[pos][rem][ss]=sum;

    return sum;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&k,&n);
     ans=fun(0,0ll,true,0ll);
    printf("%lld\n",ans);
    return 0;
}
