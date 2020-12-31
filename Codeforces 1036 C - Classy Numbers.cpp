/// A normal sum of digits problem different another solution

/// Codeforces 1036 C - Classy Numbers
/// Nice one !


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=20;
const int sm=160;/// 9*11=99

/// dp[num_of_digit][sum_of_digits][restricted_or_not];
ll dp[maxn][sm][2];

ll FUN(string number,int pos,ll non_zero_digit,bool restricted)
{
    if(pos==number.length()) return (non_zero_digit<=3ll);

    else if(dp[pos][non_zero_digit][restricted]!=-1) return dp[pos][non_zero_digit][restricted];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=0;i<=number[pos]-'0';i++)
        {
            if(i==number[pos]-'0')
            {
                res+=FUN(number,pos+1,non_zero_digit+(i>0),true);
            }
            else
            {
                res+=FUN(number,pos+1,non_zero_digit+(i>0),false);
            }
        }
        dp[pos][non_zero_digit][restricted]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0;
        for(ll i=0;i<=9;i++)
        {
            res+=FUN(number,pos+1,non_zero_digit+(i>0),false);
        }
        dp[pos][non_zero_digit][restricted]=res;
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
       cout<<(bb-aa)<<endl;
   }

   return 0;
}
