
/// Codeforces 628D - Magic Numbers 
/// Straight Forward Digit Dp problem 
/// Nice one !

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2002;

const ll MOD = 1000000007;

/// dp[num_of_digit][sum_of_digits][restricted_or_not];
ll dp[2][maxn][maxn];
ll m,d;
string number;

ll FUN(int pos,int rem,bool restricted)
{
    /// if rem is 0 ,that means this number is multiple of m 
    if(pos==number.length()) return (rem==0);

    else if(dp[restricted][pos][rem]!=-1) return dp[restricted][pos][rem];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=0;i<=number[pos]-'0';i++)
        {
            if((pos%2==0) && (i==d)) continue;

            else if((pos%2==1) && (i!=d)) continue;

            else if(i==number[pos]-'0')
            {
                res+=FUN(pos+1,(rem*10+i)%m,true);
                res%=MOD;
            }
            else
            {
                res+=FUN(pos+1,(rem*10+i)%m,false);
                 res%=MOD;
            }
        }
        dp[restricted][pos][rem]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0;
        for(ll i=0;i<=9;i++)
        {
            if((pos%2==0) && (i==d)) continue;

            else if((pos%2==1) && (i!=d)) continue;

            else {
                    res+=FUN(pos+1,(rem*10+i)%m,false);
                    res%=MOD;
                }
        }
        dp[restricted][pos][rem]=res;

        return res;
    }

}

bool check_magic(string a)
{
    	int len=a.size();
	    ll s=0ll;
	for(int i=0; i<len; i++)
	{
		s=(s*10+a[i]-'0')%m;

		if((i+1)%2==0 && a[i]-'0'!=d || (i+1)%2==1 && a[i]-'0'==d)
			return false;
	}
	if(!s)
		return true;
	else
		return false;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>m>>d;
       memset(dp,-1,sizeof(dp));
       cin>>a>>b;
       number=a;
       ll aa=FUN(0,0ll,true);
       memset(dp,-1,sizeof(dp));
       number=b;
       ll bb=FUN(0,0ll,true);
       ll ans=((bb-aa)+MOD)%MOD;
       if(check_magic(a)) ans++;
       ans%=MOD;
       cout<<ans<<endl;

   return 0;
}
