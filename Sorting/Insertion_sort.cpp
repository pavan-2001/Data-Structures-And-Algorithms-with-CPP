#include<bits/stdc++.h>
using namespace std;
void  INSERTION_SORT(vector<int>&);
int main()
{
    cout<<"Enter the number of elements you want to insert : ";
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    cin>>v[i];
    INSERTION_SORT(v);
    cout<<"The sorted list is : ";
    for(auto i:v)
    cout<<i<<' ';
    cout<<endl;
}
void  INSERTION_SORT(vector<int>& v1)
{
    for(int j=1;j<v1.size();j++)
    {
        int i=j-1;
        int key=v1[j];
        while(i>=0 and v1[i]>key)
        {
            v1[i+1]=v1[i];
            i--;
        }
        v1[i+1]=key;
    }
}

"""
Output-Enter the number of elements you want to insert : 10
10 1 9 2 8 3 7 4 6 5
The sorted list is : 1 2 3 4 5 6 7 8 9 10
"""
