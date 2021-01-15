#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

int n=10;
vector<int> revenue(n+1,-1e9);

int Top_Buttom_Cut_Rod(vector<int> &price,int size)
{
    if(revenue[size]>=0)
    return revenue[size];
    int q;
    if(size==0)
    q=0;
    else
    {   q=-1e9;
        for(int i=1;i<=size;i++)
        {
            q=max(q,price[i]+Top_Buttom_Cut_Rod(price,size-i));
        }
    }
    revenue[size]=q;
    return revenue[size];
}

void Print_Cut_Rod_Solution(vector<int> &price,int size)
{
    int result=Top_Buttom_Cut_Rod(price,size);
    cout<<"The Highest Revenue Possible is : "<<result<<endl;
}

int main()
{
    vector<int> price={0,1,5,8,9,10,17,17,20,24,30};
    Print_Cut_Rod_Solution(price,10);
}

/*
Output : 
The Highest Revenue Possible is : 30
*/
