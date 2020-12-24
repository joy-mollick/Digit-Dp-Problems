
/// Very Basic Digit Dp Problem 
/// How many numbers are there from a to b inclusive where sum of digits are equal to given sum S . 
/// Requirement - recursive knowledge and memoization

/// First define a function F(k,s) 
/// F(k,s) = count of number representation with k digits having sum equal to s 

/// solve function exactly divides a number into different parts and recur to F(k,s) 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=18;

int s;

bool mem[maxn][maxn];
ll dp[maxn][maxn];

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


int solve(int x)
{
    int ret=0;
    string digit=to_string(x);
    int sum=s;
    int ln=digit.size();
    int len=ln;

    for(int i=0;i<len;i++)
    {
        ln--;
        int d=digit[i]-'0';
        ///
        for(int j=0;j<d;j++)
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

int main()

{
    int a,b;
    cin>>a>>b>>s;
   cout<<solve(b+1)-solve(a)<<endl;
   return 0;
}
