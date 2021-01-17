/*

Problem Statement : 
Give an O(n^2) time algorithm to find the longest monotonically increasing subsequence of a sequence of n numbers.

*/
//--------------------------------------------------------------------------------Solution------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

tuple<vector<vector<int>>,int,int> Longest_Monotonically_increasing_Subsequence(vector<int> &s)
{
    vector<vector<int>> c(s.size(),vector<int>(s.size(),1));
    int result=0;
    int index=0;
    for(int i=0;i<s.size();i++)
    {
        int curr_num=s[i];
        for(int j=i+1;j<s.size();j++)
        {
            if(s[j]>curr_num)
            {
                curr_num=s[j];
                c[i][j]=c[i][j-1]+1;
            }
            else
            {
                c[i][j]=c[i][j-1];
            }
        }
        if(c[i][s.size()-1]>result)
        {
            result=c[i][s.size()-1];
            index=i;
        }
    }
    return make_tuple(c,index,result);
}

void Print_Sequence(vector<vector<int>> c,vector<int> s,int i,int j)
{
    if(i==j)
    {
        cout<<s[i]<<' ';
        return ;
    }
    if(c[i][j]!=c[i][j-1])
    {
        Print_Sequence(c,s,i,j-1);
        cout<<s[j]<<' ';
    }
    else
    {
        Print_Sequence(c,s,i,j-1);
    }
}
int main()
{
    vector<int> s={1,-2,-3,0,5,-6,7};
    tuple<vector<vector<int>>,int,int> result=Longest_Monotonically_increasing_Subsequence(s);
    cout<<"The Length of Longest Monotonically increasing subsequence of numbers is : "<<get<2>(result)<<endl;
    Print_Sequence(get<0>(result),s,get<1>(result),s.size()-1);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Output : 
The Length of Longest Monotonically increasing subsequence of numbers is : 4
-2 0 5 7
*/
