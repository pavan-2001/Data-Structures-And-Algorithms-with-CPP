#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

tuple<int,int,int> Find_maximum_subarray(vector<int>& arr)
{
    int sum=-1e9;
    int left_index=0;
    int right_index=0;
    for(int i=0;i<arr.size();i++)
    {   
        int temp_sum=arr[i];
        for(int j=i+1;j<arr.size();j++)
        {
            temp_sum+=arr[j];
            if(temp_sum>=sum)
            {
                sum=temp_sum;
                left_index=i;
                right_index=j;
            }
        }
    }
    return make_tuple(sum,left_index,right_index);
}

int main()
{
    vector<int> arr={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    tuple<int,int,int> temp=Find_maximum_subarray(arr);
    cout<<"The maximum possible subarray is : "<<get<0>(temp)<<endl;
    cout<<"The Left index is : "<<get<1>(temp)+1<<endl;
    cout<<"The Right index is : "<<get<2>(temp)+1<<endl;
}

/*
Output : 
The maximum possible subarray is : 43
The Left index is : 8
The Right index is : 11
*/
