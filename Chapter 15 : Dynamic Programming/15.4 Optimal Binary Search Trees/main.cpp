#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

tuple<vector<vector<double_t>>,vector<vector<int64_t>>> Optimal_BST(vector<double_t> &p,vector<double_t> &q,int64_t &n)
{
    vector<vector<double_t>> e(n+2,vector<double_t>(n+1));
    vector<vector<double_t>> w(n+2,vector<double_t>(n+1));
    vector<vector<int64_t>> root(n+1,vector<int64_t>(n+1));

    for(int64_t i=1;i<=n+1;i++)
    {
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    for(int64_t l=1;l<=n;l++)
    {
        for(int64_t i=1;i<=n-l+1;i++)
        {
            int64_t j=i+l-1;
            e[i][j]=1e9;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int64_t r=i;r<=j;r++)
            {
                double_t t=e[i][r-1]+e[r+1][j]+w[i][j];
                if(t<e[i][j])
                {
                    e[i][j]=t;
                    root[i][j]=r;
                }
            }
        }
    }
    cout<<w[1][5]<<endl;
    return make_tuple(e,root);
}

int main()
{
    vector<double_t> p={0.0,0.15,0.10,0.05,0.10,0.20};
    vector<double_t> q={0.05,0.10,0.05,0.05,0.05,0.10};
    int64_t n=5;
    tuple<vector<vector<double_t>>,vector<vector<int64_t>>> result=Optimal_BST(p,q,n);
    cout<<get<0>(result)[1][n]<<' '<<get<1>(result)[1][5];
}
