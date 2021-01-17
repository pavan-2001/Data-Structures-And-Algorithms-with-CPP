/*

Problem Statement : 
Give pseudocode to reconstruct an LCS from the completed c table and the original sequences X=< x1,x2,...,xm > and Y=< y1,y2,...,yn > in O(m+n) time, without using the b table.

*/
//------------------------------------------------------------------------------Solution-----------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

vector<vector<int>>  LCS_Length(string &X,string &Y)
{
    int m=X.size()-1;
    int n=Y.size()-1;
    vector<vector<int>> c(m+1,vector<int>(n+1));
    vector<vector<char>> b(m+1,vector<char>(n+1));
    for(int i=0;i<=m;i++)
    c[i][0]=0;
    for(int i=0;i<=n;i++)
    c[0][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i]==Y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
            }
            else
            {
                c[i][j]=c[i][j-1];
            }
        }
    }
    return c;
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
int main()
{
    string X="_ABCBDAB";
    string Y="_BDCABA";
    vector<vector<int>> result=LCS_Length(X,Y);
    Print_LCS_Exercise(result,X,Y,X.size()-1,Y.size()-1);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Output : 
BCBA
*/
