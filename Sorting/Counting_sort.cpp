
//                      COUNTING SORT

#include<bits/stdc++.h>
using namespace std;
#include<chrono>
using namespace std::chrono;
//           Counting sort algorithm
vector<int> Counting_sort(vector<int>& a,int highest_value)
{
    vector<int> b(highest_value+1,0);
    vector<int> c(a.size()+1,0);
    for(int i=0;i<a.size();i++)
    ++b[a[i]];
    for(int i=1;i<=highest_value;i++)
    b[i]+=b[i-1];
    for(int i=a.size()-1;i>=0;i--)
    {
        c[b[a[i]]]=a[i];
        b[a[i]]-=1;
    }
    return c;
}
int main()
{   
    auto start=high_resolution_clock::now();
    cout<<"Enter the no. of elements to sort : ";
    int n;
    cin>>n;
    cout<<"Enter the no. with highest value : ";
    int highest_value;
    cin>>highest_value;
    cout<<"Enter the sequence to sort : \n";
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
    cin>>a[i];
    auto v=Counting_sort(a,highest_value);
    cout<<"The sorted sequence is : \n";
    for(int i=1;i<v.size();i++)
    cout<<v[i]<<' ';
    cout<<'\n';
    auto elapsed=duration_cast<seconds>(high_resolution_clock::now()-start);
    cout<<"The time taken to execute is "<<elapsed.count()<<endl;
}

/*
Output-
Enter the no. of elements to sort : 10
Enter the no. with highest value : 10
Enter the sequence to sort :
10 1 9 2 8 3 7 4 6 5
The sorted sequence is :
1 2 3 4 5 6 7 8 9 10
The time taken to execute is 2
*/
