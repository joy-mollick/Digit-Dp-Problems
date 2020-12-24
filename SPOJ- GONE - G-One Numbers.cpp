

/// Digit DP Problem


/// A must do problem


#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int maxn=10;
const int mx=73;/// 9 * 8 = 72

bool mem[maxn][mx];
ll dp[maxn][mx];
/// all numbers are less than 10^8
/// So, it has total 8 digits
/// so, max sum can be 8*9=72
ll primes[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

ll F(int num_of_dig,ll sum)
{
    if(num_of_dig==0) { if(sum==0ll) {return 1ll;} else {return 0ll;} }

    if(mem[num_of_dig][sum]) return dp[num_of_dig][sum];

    mem[num_of_dig][sum]=1;

    ll res=0ll;

    for(ll i=0;i<=9;i++) res+=F(num_of_dig-1ll,sum-i);

    dp[num_of_dig][sum]=res;

    return res;
}


ll solve(ll x,ll s)
{
    ll ret=0ll;
    string digit=to_string(x);
    ll sum=s;
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
            if(sum>=j)
            {
                ret+=F(ln,sum-j);
            }
        }
        sum=sum-d;
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
       ll ans=0ll;
       ll subtract=0ll;
       for(int i=0;i<20;i++)
       {
           ans+=solve(b+1,primes[i]);
           subtract+=solve(a,primes[i]);
       }
       cout<<(ans-subtract)<<endl;
   }

   return 0;
}
