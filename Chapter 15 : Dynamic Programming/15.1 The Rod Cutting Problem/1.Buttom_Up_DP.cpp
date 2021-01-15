#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

tuple<vector<int>,vector<int>> Extended_Buttom_Up_Cut_Rod(vector<int> &price,int n)
{
    vector<int> revenue(n+1,0);
    vector<int> slices(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int q=-1e9;
        for(int j=1;j<=i;j++)
        {
            if(q<(price[j]+revenue[i-j]))
            {
                q=price[j]+revenue[i-j];
                slices[i]=j;
            }
        }
        revenue[i]=q;
    }
    return make_tuple(revenue,slices);
}

void Print_Cut_Rod_Solution(vector<int> &price,int n)
{
    tuple<vector<int>,vector<int>> result=Extended_Buttom_Up_Cut_Rod(price,n);
    cout<<"The Highest Revenue Possible is : "<<get<0>(result)[n]<<endl;
    cout<<"The Possible cutting is : ";
    while(n>0)
    {
        cout<<get<1>(result)[n];
        n=n-get<1>(result)[n];
    }
}

int main()
{
    vector<int> price={0,1,5,8,9,10,17,17,20,24,30};
    Print_Cut_Rod_Solution(price,10);
}

/*
Output : 
The Highest Revenue Possible is : 30
The Possible cutting is : 10  
*/
