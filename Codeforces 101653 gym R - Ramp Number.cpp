
/// Codeforces 101653 gym R - Ramp Number 
/// Nice one !


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=81;
const int sm=160;/// 9*11=99

/// dp[num_of_digit][sum_of_digits][restricted_or_not];
ll dp[maxn][2][10];

ll FUN(string number,int pos,bool restricted,int pre)
{
    if(pos==number.length()) return (1ll);

    else if(dp[pos][restricted][pre]!=-1) return dp[pos][restricted][pre];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=pre;i<=number[pos]-'0';i++)
        {
            if(i==number[pos]-'0')
            {
                res+=FUN(number,pos+1,true,i);
            }
            else
            {
                res+=FUN(number,pos+1,false,i);
            }
        }
        dp[pos][restricted][pre]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0;
        for(ll i=pre;i<=9;i++)
        {
             res+=FUN(number,pos+1,false,i);
        }
        dp[pos][restricted][pre]=res;
        return res;
    }

}

bool ramp(string s)
{
    int len=s.size();
    for(int i = 1; i < len; i ++)
        {
            if(s[i]<s[i-1])
            {
              return false;
            }
        }
    return true;
}

int main()

{
    string b;
    int t;
    cin>>t;
   while(t--)
   {
       memset(dp,-1,sizeof(dp));
       cin>>b;
       if(!ramp(b)) {cout<<"-1"<<endl;continue;}
       ll aa=FUN(b,0,true,0);
       aa--;/// because of 0 (zero)
       cout<<(aa)<<endl;
   }
   return 0;
}
