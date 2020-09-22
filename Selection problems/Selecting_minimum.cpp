#include<bits/stdc++.h>
using namespace std;

// main algorithm

int minimum(vector<int>& seq)
{
    int min=seq[0];
    for(int i=1;i<seq.size();i++)
    {
        if(seq[i]<min)
        min=seq[i];
    }
    return min;
}

istream& read(istream& in,int& a)
{
    in>>a;
    return in;
}

int main()
{
    ifstream infile;
    infile.open("input.txt",ifstream::in);
    vector<int> seq;
    int a;
    while(read(infile,a))
    {
        seq.emplace_back(a);
    }
    cout<<minimum(seq)<<'\n';
}

/*
Output-
1
*/
