

/// A normal sum of digits problem different another solution
/// It is however a default solution 


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=16;
const int mx=91;/// 9 * 8 = 72
const int sm=160;/// 9*11=99

bool mem[maxn][sm][2];
/// dp[num_of_digit][sum_of_digits][restricted_or_not];
ll dp[maxn][sm][2];
int total_dig;

ll FUN(string number,int pos,ll sum,bool restricted)
{
    if(pos==number.length()) return sum;

    else if(dp[pos][sum][restricted]!=-1) return dp[pos][sum][restricted];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=0;i<=number[pos]-'0';i++)
        {
            if(i==number[pos]-'0')
            {
                res+=FUN(number,pos+1,sum+i,true);
            }
            else
            {
                res+=FUN(number,pos+1,sum+i,false);
            }
        }
        dp[pos][sum][restricted]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0;
        for(ll i=0;i<=9;i++)
        {
            res+=FUN(number,pos+1,sum+i,false);
        }
        dp[pos][sum][restricted]=res;
        return res;
    }

}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b;
    int t;
    cin>>t;
   while(t--)
   {
       memset(dp,-1,sizeof(dp));
       cin>>a>>b;
       ll aa=FUN(to_string(a-1),0,0ll,true);
       memset(dp,-1,sizeof(dp));
       ll bb=FUN(to_string(b),0,0ll,true);
       cout<<(bb-aa)<<'\n';
   }

   return 0;
}
