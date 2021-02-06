#include<bits/stdc++.h>
using namespace std;

int left_child(int index)
{
    return (2*index);
}

int right_child(int index)
{
    return (2*index + 1);
}

void Print_child(int i)
{
    cout<<2*i<<' '<<2*i+1<<' ';
}

tuple<vector<char>,double> Planning_a_Company_Party( vector<double> &Tree )
{
    vector<double> DP (Tree.size());
    vector<char> data(Tree.size());
    for(int i = Tree.size()-1; i >= 1 ; i--)
    {
        int rc = right_child(i);
        int lc = left_child(i);
        int r_r_c = right_child(rc);
        int r_l_c = left_child(rc);
        int l_r_c = right_child(lc);
        int l_l_c = left_child(lc);
        double sum_of_childrens = (rc >= Tree.size() ? 0 : DP[rc]) + (lc >= Tree.size() ? 0 : DP[lc]) ;
        double sum_of_grand_childrens = (l_l_c >= Tree.size() ? 0 : DP[l_l_c]) + (l_r_c >= Tree.size() ? 0 : DP[l_r_c] ) + (r_l_c >= Tree.size() ? 0 : DP[r_l_c]) + (r_r_c >= Tree.size() ? 0 : DP[r_r_c]) + Tree[i];
        DP[i] = max(sum_of_grand_childrens , sum_of_childrens);
        data[i] = sum_of_grand_childrens >= sum_of_childrens ? 'g' : 'c' ;
    }
    
    return make_tuple(data,DP[1]);
}

void Print_List(vector<char> &data, int i)
{
    if(i >= data.size())
    return ;
    if(data[i] == 'g')
    {
        cout<<i<<' ';
        Print_List(data,(2*i)*2);
        Print_List(data,(2*i)*2+1);
        Print_List(data,(2*i+1)*2);
        Print_List(data,(2*i+1)*2+1);
    }
    else
    {
        Print_List(data,2*i);
        Print_List(data,2*i+1);
    }
    
}

int main()
{
    vector<double> Tree = {0.0, 1.0, -2.0, 6.0, -2.0, 2.4, 3.5, -1.00, 3.7, 4.98, -0.34};
    tuple<vector<char>, double> result =  Planning_a_Company_Party(Tree);
    if(get<1>(result))
    {
        cout<<"The maximum conviviality of the invited guests is "<<get<1>(result)<<endl;
        Print_List(get<0>(result),1);
    }
    else
    {
        cout<<"We have not invited any employee...!";
    }
}
/*
Output : 
The maximum conviviality of the invited guests is 17.08
8 9 5 3
*/
