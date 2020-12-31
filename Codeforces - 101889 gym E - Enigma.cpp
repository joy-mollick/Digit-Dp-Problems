 
/// Codeforces 101653 gym R - Ramp Number
/// Nice one !


/// Codeforces - 101889 gym E - Enigma
/// Very Nice one 


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1001;

int ans[1001];
ll mod;

/// dp[num_of_digit][sum_of_digits][restricted_or_not];
ll dp[maxn][1001];

ll FUN(string number,int pos,ll rem )
{
    if(pos==number.length())
    {
        if(rem==0)
        {
            for(int i=0;i<number.length();i++)
            {
                cout<<ans[i];
            }
            cout<<endl;
            exit(0);
            return 0ll;
        }
        else return -1;
    }

    else if(dp[pos][rem]!=-1) return dp[pos][rem];

    if(number[pos]!='?')
    {
        ans[pos]=number[pos]-'0';
        dp[pos][rem]=FUN(number,pos+1,(rem*10ll+ans[pos])%mod);
    }
    else
    {
        ll res=0ll;
        for(int i=pos?0:1;i<=9;i++)
        {
            ans[pos]=i;
            res+=FUN(number,pos+1,(rem*10ll+i)%mod);
        }
        dp[pos][rem]=res;
        return res;
    }

}


int main()

{
   string s;
   cin>>s>>mod;
   memset(dp,-1,sizeof(dp));
   if(FUN(s,0,0ll)!=0ll) cout<<"*"<<endl;
   return 0;
}
