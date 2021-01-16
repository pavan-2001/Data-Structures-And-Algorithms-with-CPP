#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

tuple<vector<vector<int>>,vector<vector<char>>>LCS_Length(string &X,string &Y)
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
                b[i][j]='D';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='L';
            }
        }
    }
    return make_tuple(c,b);
}

void Print_LCS(vector<vector<char>> &b,string &X,int i,int j)
{
    if(i==0||j==0)
    return ;
    if(b[i][j]=='D')
    {
        Print_LCS(b,X,i-1,j-1);
        cout<<X[i];
    }
    else if(b[i][j]=='U')
    return Print_LCS(b,X,i-1,j);
    else
    return Print_LCS(b,X,i,j-1);
}

int main()
{
    string X="0ABCBDAB";
    string Y="0BDCABA";
    tuple<vector<vector<int>>,vector<vector<char>>> result=LCS_Length(X,Y);
    Print_LCS(get<1>(result),X,X.size()-1,Y.size()-1);
}

/*
Output : 
BCBA
*/
