/*

Problem Statement : 
Give a memoized version of LCS-Length that runs in O(m.n) time ?

*/
//-------------------------------------------------------------------------------Solution------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

int  LCS_Lookup(vector<vector<int>> &c,string &X,string &Y,int i,int j)
{
    if(c[i][j]<1e9)
    return c[i][j];
    if(i==0||j==0)
    c[i][j]=0;
    else
    {
        if(X[i]==Y[j])
        c[i][j]=LCS_Lookup(c,X,Y,i-1,j-1)+1;
        else if(LCS_Lookup(c,X,Y,i-1,j)>=LCS_Lookup(c,X,Y,i,j-1))
        c[i][j]=LCS_Lookup(c,X,Y,i-1,j);
        else
        c[i][j]=LCS_Lookup(c,X,Y,i,j-1);
    }
    return c[i][j];
}

void Print_LCS_Exercise(vector<vector<int>> &c,string &X,string &Y,int i,int j)
{
    if(i==0||j==0)
    return ;
    if(X[i]==Y[j])
    {
        Print_LCS_Exercise(c,X,Y,i-1,j-1);
        cout<<X[i];
    }
    else if(c[i-1][j]>=c[i][j-1])
    Print_LCS_Exercise(c,X,Y,i-1,j);
    else
    Print_LCS_Exercise(c,X,Y,i,j-1);
}

void Memoized_LCS(string &X,string &Y)
{
    vector<vector<int>> c(X.size(),vector<int>(Y.size(),1e9));
    for(int i=0;i<X.size();i++)
    c[i][0]=0;
    for(int i=0;i<Y.size();i++)
    c[0][i]=0;
    int Length_of_LCS=LCS_Lookup(c,X,Y,X.size()-1,Y.size()-1);
    Print_LCS_Exercise(c,X,Y,X.size()-1,Y.size()-1);
}

int main()
{
    string X="_ABCBDAB";
    string Y="_BDCABA";
    Memoized_LCS(X,Y);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Output : 
BCBA
*/
