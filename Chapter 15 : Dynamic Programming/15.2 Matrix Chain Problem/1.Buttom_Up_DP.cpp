#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

tuple<vector<vector<int>>,vector<vector<int>>> Matrix_Chain_Order(vector<int> &p)
{
    int n=p.size()-1;
    vector<vector<int>> m(n+1,vector<int>(n+1,0));
    vector<vector<int>> s(n+1,vector<int>(n+1));
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=1e9;
            for(int k=i;k<j;k++)
            {
                int q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    return make_tuple(m,s);
}

void Print_Optimal_Parens(vector<vector<int>> &s,int i,int j)
{
    if(i==j)
    cout<<" A"<<i<<' ';
    else
    {
        cout<<"(";
        Print_Optimal_Parens(s,i,s[i][j]);
        Print_Optimal_Parens(s,s[i][j]+1,j);
        cout<<')';
    }
    
}

int main()
{
    vector<int> p={30,35,15,5,10,20,25};
    tuple<vector<vector<int>>,vector<vector<int>>> result=Matrix_Chain_Order(p);
    Print_Optimal_Parens(get<1>(result),1,6);
}

/*
Output : 
( A1 ( A2  A3 ))(( A4  A5 ) A6 ))
*/
