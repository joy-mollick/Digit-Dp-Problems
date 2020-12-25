
/// SPOJ -> RAONE - Ra-One Numbers
/// Digit DP Problem

/// A must do problem for beginners
/// Nice one


#include<bits/stdc++.h>

using namespace std;

typedef long ll;

const int maxn=11;
const int mx=91;/// 9 * 8 = 72

bool mem[maxn][mx][mx];
ll dp[maxn][mx][mx];


ll F(int num_of_dig,ll odd,ll even)
{
    if(num_of_dig==0) {

        if((even-odd)==1) return 1;
        else return 0ll;
    }

    if(mem[num_of_dig][odd][even]) return dp[num_of_dig][odd][even];

    mem[num_of_dig][odd][even]=1;

    ll res=0ll;

    for(ll i=0;i<=9;i++)
    {
        /// so, when we recur for next (num_of_dig-1) digits
        /// then an odd position is fixed with i
        if(num_of_dig%2==1) res+=F(num_of_dig-1,odd+i,even);
        /// so, when we recur for next (num_of_dig-1) digits
        /// then an even position is fixed with i
        else res+=F(num_of_dig-1,odd,even+i);
    }

    dp[num_of_dig][odd][even]=res;

    return res;
}


ll solve(ll x)
{
     ll ret=0ll;
     ll even=0ll;
     ll odd=0ll;

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
           if((len-i)%2==0)
           {
               /// so, even position means 0,2,4,6... has been fixed by j
               /// by keeping fix j at even position ,
               /// by F() function we will find all such numbers putting all other numbers into other positions
               ret+=F(ln,odd,even+j);
           }
           else
           {
               /// it is like as same as above case
               ret+=F(ln,odd+j,even);
           }
        }

        /// when one digit has been cut off and recur for next then obviously
        /// the number of that position (even or odd) will be added
        if((len-i)%2==0) even+=d;
        else odd+=d;
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
       cout<<solve(b+1)-solve(a)<<'\n';
   }

   return 0;
}
