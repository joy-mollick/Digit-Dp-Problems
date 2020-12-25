
/// How many numbers from(a to b)where number of 3s and 6s and 9s are equal ? 
/// Digit DP Problem

/// A must do problem for beginners
/// Nice one


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=1000000007;
const int maxn=11;
const int mx=91;/// 9 * 8 = 72

bool mem[maxn][mx][mx][mx];
ll dp[maxn][mx][mx][mx];
/// dp[num_of_dig][three][six][nine]


ll F(int num_of_dig,ll three,ll six,ll nine)
{
    if(num_of_dig==0)
    {
        if(three==0) return 0ll;
        else if(three==six && six==nine) return 1ll;
        else return 0ll;
    }

    if(mem[num_of_dig][three][six][nine]) return dp[num_of_dig][three][six][nine];

    mem[num_of_dig][three][six][nine]=1;

    ll res=0ll;

    for(ll i=0;i<=9;i++)
    {
       if(i==3)
       {
           res+=F(num_of_dig-1,three+1,six,nine);
           if(res>=mod) res=res%mod;
       }
       else if(i==6)
       {
            res+=F(num_of_dig-1,three,six+1,nine);
           if(res>=mod) res=res%mod;
       }
       else if(i==9)
       {
            res+=F(num_of_dig-1,three,six,nine+1);
           if(res>=mod) res=res%mod;
       }
       else
       {
            res+=F(num_of_dig-1,three,six,nine);
           if(res>=mod) res=res%mod;
       }
    }

    dp[num_of_dig][three][six][nine]=res;

    return res;
}


ll solve(ll x)
{
     ll ret=0ll;

     ll three=0ll;
     ll six=0ll;
     ll nine=0ll;

    string digit=to_string(x);
    int ln=digit.size();
    int len=ln;

    for(int i=0;i<len;i++)
    {
        ln--;
        ll d=(ll)(digit[i]-'0');
        ///
        for(ll j=0;j<d;j++)
        {
            /// sum-j=property
            /// it is for upper numbers without first digit
            /// say , your x is 698
            /// then first loop is for first digit
            /// which will run till 599
            /// next iteration we will iterate assuming first digit as 6
            /// and iter from 600 to 689 as second digit is 9
            /// again iter from 690 to 697
           if(j==3ll)
           {
               ret+=F(ln,three+1ll,six,nine);
               if(ret>=mod) ret=ret%mod;
           }
           else if(j==6ll)
           {
               ret+=F(ln,three,six+1ll,nine);
                if(ret>=mod) ret=ret%mod;
           }
           else if(j==9ll)
           {
               ret+=F(ln,three,six,nine+1ll);
                if(ret>=mod) ret=ret%mod;
           }
           else
           {
               ret+=F(ln,three,six,nine);
                if(ret>=mod) ret=ret%mod;
           }
        }

        /// when one digit has been cut off and recur for next then obviously
        /// the number of that position (even or odd) will be added
        if(d==3) three++;
        else if(d==6) six++;
        else if(d==9) nine++;
    }
    return ret;
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
       memset(dp,0,sizeof(dp));
       memset(mem,0,sizeof(mem));
       cin>>a>>b;
       ll up=solve(b+1ll);
       ll down=solve(a);
       ll ans=up-down;
       if(ans<0) ans=(ans+mod);
       cout<<ans<<'\n';
   }

   return 0;
}
