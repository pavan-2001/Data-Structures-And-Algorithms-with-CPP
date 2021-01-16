#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

int Look_Chain(vector<vector<int>> &m,vector<vector<int>> &s,vector<int> &p,int i,int j)
{
    if(m[i][j]<1e9)
    return m[i][j];
    if(i==j)
    m[i][j]=0;
    else
    {  
        for(int k=i;k<j;k++)
        {
            int q=Look_Chain(m,s,p,i,k)+Look_Chain(m,s,p,k+1,j)+(p[i-1]*p[k]*p[j]);
            if(q<m[i][j])
            {
                m[i][j]=q;
                s[i][j]=k;
            }
        }
    }
    return m[i][j];
}

tuple<vector<vector<int>>,vector<vector<int>>> Memoized_Matrix_Chain(vector<int> &p)
{
    int n=p.size()-1;
    vector<vector<int>> m(n+1,vector<int>(n+1));
    vector<vector<int>> s(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        m[i][j]=1e9;
    }
    int result=Look_Chain(m,s,p,1,n);
    cout<<result<<endl;
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
    tuple<vector<vector<int>>,vector<vector<int>>> result=Memoized_Matrix_Chain(p);
    Print_Optimal_Parens(get<1>(result),1,6);
}

/*
Output : 
(( A1 ( A2  A3 ))(( A4  A5 ) A6 ))
*/
