#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'

int Fibonacci_number(vector<int> &seq,int size)
{   
    if(size==1)
    return seq[size];
    if(seq[size]>0)
    return seq[size];
    int q;
    if(size==2)
    q=1;
    else
    q=Fibonacci_number(seq,size-1)+Fibonacci_number(seq,size-2);
    seq[size]=q;
    return seq[size];
}
int main()
{
    vector<int> seq(12,0);
    int result=Fibonacci_number(seq,11);
    cout<<"The 10th Fibonacci Number is : "<<result<<endl;
    cout<<"The Fibonacci sequence of first 10 numbers is  : "<<endl;
    for(int i=1;i<=11;i++)
    cout<<seq[i]<<' ';
}

/*
Output : 
The 10th Fibonacci Number is : 55
The Fibonacci sequence of first 10 numbers is  : 
0 1 1 2 3 5 8 13 21 34 55
*/
