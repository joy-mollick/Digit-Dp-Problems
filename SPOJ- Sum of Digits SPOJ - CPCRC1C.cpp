

/// Digit DP Problem

/// Here , we use how many numbers are there from a tob inclusive whose sum is equal to s algorithm to make this problem easy 
/// A must do basic problem


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=18;
const int mx=163;/// 9 * 18 = 162

bool mem[maxn][mx];
ll dp[maxn][mx];

ll F(int num_of_dig,int sum)
{
    if(num_of_dig==0) return (ll)(sum==0);

    if(mem[num_of_dig][sum]) return dp[num_of_dig][sum];

    mem[num_of_dig][sum]=1;

    ll res=0ll;

    for(int i=0;i<=9;i++) res+=F(num_of_dig-1,sum-i);

    dp[num_of_dig][sum]=res;

    return res;
}


ll solve(int x,ll s)
{
    ll ret=0;
    string digit=to_string(x);
    ll sum=s;
    int ln=digit.size();
    int len=ln;

    for(int i=0;i<len;i++)
    {
        ln--;
        ll d=(ll)digit[i]-'0';
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
            if(sum-j>=0)
            {
                ret+=F(ln,sum-j);
            }
        }
        sum=sum-d;
    }
    return ret;
}

ll num_digits(ll num)
{
    ll cont=0ll;
    while(num!=0ll)
    {
        cont++;
        num=num/10ll;
    }
    return cont;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b;
   while(true)
   {
       memset(dp,0,sizeof(dp));
       memset(mem,0,sizeof(mem));
       cin>>a>>b;
       if(a==-1&&b==-1) break;
       ll mx_sum=9ll*num_digits((b));
       ll ans=0;
       ll subtract=0ll;
       if(a==0) a=1ll;
       for(ll i=1ll;i<=mx_sum;i++)
       {
           ans+=i*solve(b+1,i);
           subtract+=i*solve(a,i);
       }
       cout<<(ans-subtract)<<endl;
   }

   return 0;
}
