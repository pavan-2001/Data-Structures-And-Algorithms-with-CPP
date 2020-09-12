#include<bits/stdc++.h>
using namespace std;
void merge(int *A,int beg,int mid,int end)
{
    int n1=mid-beg+1;
    int n2=end-mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++)
    L[i]=A[beg+i];
    for(int i=0;i<n2;i++)
    R[i]=A[mid+i+1];
    L[n1]=1e9;
    R[n2]=1e9;
    int i=0,j=0;
    for( int k=beg;k<=end;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
}
void merge_sort(int *A,int beg,int end)
{
    if(beg<end)
    {
        int mid=((beg+end)/2);
        merge_sort(A,beg,mid);
        merge_sort(A,mid+1,end);
        merge(A,beg,mid,end);
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements to sort sequence to sort : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    merge_sort(arr,0,n-1);
    for(auto a :arr)
    cout<<a<<' ';
    cout<<'\n';
}

/*

Output-
Enter the number of elements to sort sequence to sort : 10
10 1 9 2 8 3 7 4 6 5
1 2 3 4 5 6 7 8 9 10

*/
