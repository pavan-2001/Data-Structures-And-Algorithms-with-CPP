#include<bits/stdc++.h>
using namespace std;

// main algorithm

int maximum(vector<int>& seq)
{
    int max=seq[0];
    for(int i=1;i<seq.size();i++)
    {
        if(seq[i]>max)
        max=seq[i];
    }
    return max;
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
    cout<<maximum(seq)<<'\n';
}

/*
Output-
9995
*/
