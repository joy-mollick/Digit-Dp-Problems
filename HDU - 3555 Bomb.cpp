
/// HDU - 3555 Bomb 
/// Time- 70ms
/// Straight Forward Digit DP Problem
/// First find reciprocal properties and then find exact answer 


#include<cstdio>
 #include<sstream>
 #include<cstdlib>
 #include<cctype>
 #include<cmath>
 #include<algorithm>
 #include<set>
 #include<queue>
 #include<stack>
 #include<list>
 #include<iostream>
 #include<fstream>
 #include<numeric>
 #include<string>
 #include<vector>
 #include<cstring>
 #include<map>
 #include<iterator>


using namespace std;

typedef unsigned long long ll;

const int maxn=19;
const int mx=31;/// 9 * 8 = 72
const int sm=160;/// 9*11=99

/// ll dp[mx][mx][10][2];
///ll dp[2][10][mx][mx];
ll dp[2][mx][mx];
string number;

ll FUN(int pos,ll cnt,bool restricted)
{
    if(pos==number.length())
    {
        return 1;
    }

    else if(dp[restricted][pos][cnt]!=-1) return dp[restricted][pos][cnt];

    /// we can't cross position's number
    else if(restricted)
    {
        ll res=0ll;
        for(ll i=0;i<=number[pos]-'0';i++)
        {
            if(cnt&&i==9) continue;

            else if(i==number[pos]-'0')
            {
                res+=FUN(pos+1,i==4,true);
            }
            else
            {
                res+=FUN(pos+1,i==4,false);
            }
        }
        dp[restricted][pos][cnt]=res;
        return res;
    }

    /// we can go up to 9 from 0 ,as there is no restriction
    else
    {
        ll res=0ll;
        for(ll i=0;i<=9;i++)
        {
            if(cnt&&i==9) continue;
            else  {res+=FUN(pos+1,i==4,false);}
        }
        dp[restricted][pos][cnt]=res;
        return res;
    }

}


int main()

{
      int t;
      scanf("%d",&t);
      ll n;
      while(t--)
      {
          cin>>number;
          memset(dp,-1,sizeof(dp));
          stringstream ss(number);
          ss>>n;
          /// first find which numbers don't contain 49
          printf("%llu\n",n-FUN(0,0,1)+1);
      }
      return 0;
}
