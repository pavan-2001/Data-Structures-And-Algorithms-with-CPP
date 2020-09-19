
//             QUICK SORT

#include<bits/stdc++.h>
using namespace std;
#include<chrono>
using namespace std::chrono;

int partition(vector<int>& v,int beg,int end)
{
    int start=beg-1;
    for(int i=beg;i<end;i++)
    {
        if(v[i]<=v[end])
        {
            start+=1;
            swap(v[i],v[start]);
        }
    }
    swap(v[end],v[start+1]);
    return start+1;
}

void Quicksort(vector<int>& v,int beg,int end)
{
    if(beg<end)
    {
        int q=partition(v,beg,end);
        Quicksort(v,beg,q-1);
        Quicksort(v,q+1,end);
    }
}

int main()
{   auto start=high_resolution_clock::now();
    cout<<"Enter the no. of elements to sort : ";
    int n;
    cin>>n;
    cout<<"Enter the sequence : \n";
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    cin>>v[i];
    Quicksort(v,0,n-1);
    cout<<"The sorted sequence is :\n";
    for(auto a:v)
    cout<<a<<' ';
    cout<<'\n';
    auto elapsed=duration_cast<seconds>(high_resolution_clock::now()-start);
    cout<<"The time taken to execute is "<<elapsed.count()<<" seconds.";
}

/*
output-
Enter the no. of elements to sort : 10
Enter the sequence :
10 9 8 7 6 5 4 3 2 1
The sorted sequence is :
1 2 3 4 5 6 7 8 9 10
The time taken to execute is 3 seconds.
*/
