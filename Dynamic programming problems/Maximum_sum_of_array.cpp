#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(void)
{
    fast
    int64_t sum=-1e9,left_index=0,right_index=0;
    vector<vector<int64_t> > arr;
    ifstream in_file;
    in_file.open("input.txt");
    int64_t a,j=0;
    vector<int64_t> v(1000);
    while(in_file>>a)
    {
        v[j]=a;
        if(a>sum)
        {
            sum=a;
            left_index=j;
            right_index=j;
        }
        j++;
        arr.emplace_back(v);
    }
    auto start=high_resolution_clock::now();
    for(int64_t l=2;l<=1000;l++)
    {  
        for(int64_t i=0;i<=1000-l;i++)
        {
            arr[i][i+l-1]=arr[i][i+l-2]+arr[i+l-1][i+l-1];
            if(arr[i][i+l-1]>sum)
            {
                sum=arr[i][i+l-1];
                left_index=i;
                right_index=i+l-1;
            }
        }
    }
    auto stop=high_resolution_clock::now();
    auto elapsed=duration_cast<microseconds>(stop-start);
    cout<<"maximum sum : "<<sum<<'\n';
    cout<<"left index : "<<left_index<<'\n';
    cout<<"right_index : "<<right_index<<'\n';
    cout<<"Total time taken to execute is : "<<elapsed.count()<<" microseconds.";
}
"""
Output-
maximum sum : 1412138
left index : 178
right_index : 261
Total time taken to execute is : 15992 microseconds.
"""
