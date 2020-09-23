#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& seq,int beg,int end)
{
    int start=beg-1;
    for(int i=beg;i<end;i++)
    {
        if(seq[i]<seq[end])
        {
            start+=1;
            swap(seq[start],seq[i]);
        }
    }
    swap(seq[start+1],seq[end]);
    return start+1;
}
int randomized_select(vector<int>& seq,int beg,int end,int i)
{
    if(beg==end)
    return seq[beg];
    int q=partition(seq,beg,end);
    if(i==q)
    return seq[q];
    else if(i<q)
    return randomized_select(seq,beg,q-1,i);
    else 
    return randomized_select(seq,q+1,end,i);
}
int main()
{
    ifstream infile;
    infile.open("input.txt",ifstream::in);
    vector<int> seq;
    int a;
    while(infile>>a)
    {
        seq.emplace_back(a);
    }
    cout<<randomized_select(seq,0,999,100)<<'\n';
}   

/*
Output-
Enter the input : 448
4558
*/
