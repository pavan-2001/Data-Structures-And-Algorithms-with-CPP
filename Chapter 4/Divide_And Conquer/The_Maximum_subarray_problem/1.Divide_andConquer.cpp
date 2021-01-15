#include<chrono>
using namespace std::chrono;
#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int> Find_Maximum_Subarray_Crossing_Midpoint(vector<int>& in_seq,int low,int mid,int high)
{
    int left_sum=-1e9,right_sum=-1e9;
    int sum=0;
    int left_index=mid,right_index=mid+1;
    for(int i=mid;i>=low;i--)
    {
        sum+=in_seq[i];
        if(sum>left_sum)
        {
            left_sum=sum;
            left_index=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=in_seq[i];
        if(sum>right_sum)
        {
            right_sum=sum;
            right_index=i;
        }
    }
    return make_tuple(left_index,right_index,left_sum+right_sum);
}
tuple<int,int,int> Find_Maximum_Subarray(vector<int>& in_seq,int low,int high)
{
    if(low==high)
    return make_tuple(low,high,in_seq[low]);
    int mid=(high+low)/2;
    auto left=Find_Maximum_Subarray(in_seq,low,mid);
    auto right=Find_Maximum_Subarray(in_seq,mid+1,high);
    auto cross_section=Find_Maximum_Subarray_Crossing_Midpoint(in_seq,low,mid,high);
    auto ans=get<2>(left)>get<2>(right)?left:right;
    ans=get<2>(ans)>get<2>(cross_section)?ans:cross_section;
    return ans;
}
int main()
{
    auto start=high_resolution_clock::now();
    int n;
    cout<<"Enter the size of your sequence : ";
    cin>>n;
    vector<int> in_seq(n,0);
    for(int i=0;i<n;i++)
    cin>>in_seq[i];
    auto ans=Find_Maximum_Subarray(in_seq,0,n-1);
    cout<<"Starting index is : "<<get<0>(ans)+1<<'\n';
    cout<<"Ending index is : "<<get<1>(ans)+1<<'\n';
    cout<<"The maximum sum possible is : "<<get<2>(ans)<<'\n';
    auto stop=high_resolution_clock::now();
    auto elapsed=duration_cast<seconds>(stop-start);
    cout<<"The time taken is : "<<elapsed.count()<<" seconds";
}

/*

Output-
Enter the size of your sequence : 10
-10 20 -30 40 -50 60 -70 80 -90 100
Starting index is : 10
Ending index is : 10
The maximum sum possible is : 100
The time taken is : 2 seconds

*/
