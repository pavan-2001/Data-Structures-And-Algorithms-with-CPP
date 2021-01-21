#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

tuple<vector<vector<int64_t>>,int64_t> Longest_Palindrome_Subsequence(string &s)
{
    vector<vector<int64_t>> dp(s.size(),vector<int64_t>(s.size(),0));
    int64_t n=s.size()-1;
    for(int64_t i=0;i<s.size();i++)
    dp[i][i]=1;
    for(int64_t l=2;l<=n+1;l++)
    {
        for(int64_t i=0;i<=n-l+1;i++)
        {
            int64_t j=i+l-1;
            if(s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return make_tuple(dp,dp[0][s.size()-2]);
}

void Print_Longest_Palindrome_Subsequence(vector<vector<int64_t>> &dp,string &s,int64_t i,int64_t j,int64_t &count)
{
    if(count==0)
    {   
        return ;
    }
    else if(s[i]==s[j])
    {
        --count;
        Print_Longest_Palindrome_Subsequence(dp,s,i+1,j-1,count);
        cout<<s[i];
    }
    else if(dp[i][j-1]>=dp[i+1][j])
    {
        Print_Longest_Palindrome_Subsequence(dp,s,i,j-1,count);
    }
    else
    {
        Print_Longest_Palindrome_Subsequence(dp,s,i+1,j,count);
    }
}

int main()
{
    string s="character";
    tuple<vector<vector<int64_t>>,int64_t> result=Longest_Palindrome_Subsequence(s);
    Print_Longest_Palindrome_Subsequence(get<0>(result),s,0,s.size()-2,get<1>(result));
}

/*
Output : 
carac
*/
