

/// Straight Forward Digit DP + Binary Search Problem


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=19;
const int mx=64;/// 9 * 8 = 72
const int sm=160;/// 9*11=99

/// dp[num_of_digit][sum_of_digits][restricted_or_not];
ll dp[mx][mx][2];
int k;

ll FUN(string number,int pos,ll cnt,bool restricted)
{
    if(pos==number.length())
    {
        if(cnt==k) return 1ll;
        else return 0ll;
    }

    else if(dp[pos][cnt][restricted]!=-1) return dp[pos][cnt][restricted];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=0;i<=number[pos]-'0';i++)
        {
            if(i==number[pos]-'0')
            {
                res+=FUN(number,pos+1,i==1?cnt+1ll:cnt,true);
            }
            else
            {
                res+=FUN(number,pos+1,i==1?cnt+1ll:cnt,false);
            }
        }
        dp[pos][cnt][restricted]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0ll;
        for(ll i=0;i<=1;i++)
        {
            res+=FUN(number,pos+1,i==1?cnt+1ll:cnt,false);
        }
        dp[pos][cnt][restricted]=res;
        return res;
    }

}

string to_binary(ll x)
{
    string num="";
    while(x)
    {
        if(x%2ll==0ll) num+='0';
        else num+='1';
        x=x>>1ll;
    }
    reverse(num.begin(),num.end());
    return num;
}

int main()

{
       ll m;
       cin>>m>>k;
       ll lo=1ll,hi=1ll<<62,mid,ans1,ans2;
       while(lo<hi)
       {
           memset(dp,-1,sizeof(dp));
           mid=(lo+(hi-lo)/2ll);
           ans1=FUN(to_binary(2*mid),0,0ll,true);
            memset(dp,-1,sizeof(dp));
           ans2=FUN(to_binary(mid),0,0ll,true);
           if((ans1-ans2)>=m) hi=mid;
           else lo=mid+1;
       }
      cout<<lo<<endl;
      return 0;
}
