#include<bits/stdc++.h>
using namespace std;

tuple<vector<vector<int>>,vector<vector<int>>>  Viterbi_Algorithm(map<int,vector<pair<int,char>>> &edges,string &s,int &vo)
{
    vector<vector<int>> DP(s.size(),vector<int>(edges.size()+1,0));
    vector<vector<int>> retrace(s.size(),vector<int>(edges.size()+1,0));
    DP[0][vo] = 1;
    retrace[0][vo] = vo;
    for(int i = 1 ; i < s.size() ; i++)
    {   
        for(int j = 1 ; j <= edges.size() ; j++)
        {
            if(DP[i-1][j] == 1)
            {
                for(int k = 0 ; k < edges[j].size() ; k++)
                {
                    if(edges[j][k].second == s[i])
                    {
                        DP[i][edges[j][k].first] = 1;
                        retrace[i][edges[j][k].first] = j ;
                    }
                }
            }
        }
    }

    return make_tuple(DP,retrace);
}

void Print_Vertices(vector<vector<int>> &retrace,int & last,int &vo,int index)
{
    if(index == 0)
    {
        cout<<vo<<' ';
        return ;
    }
    else
    {
        Print_Vertices(retrace,retrace[index][last],vo,index-1);
        cout<<last<<' ';
    }
    
}

int main()
{
    map<int,vector<pair<int,char>>> edges;
    edges[1]={{2,'a'},{4,'b'},{5,'a'}};
    edges[2]={{3,'b'},{6,'d'}};
    edges[3]={};
    edges[4]={{2,'c'}};
    edges[5]={{4,'b'}};
    edges[6]={{1,'a'}};
    int vo = 2;
    string s = " daabc";

    tuple<vector<vector<int>>,vector<vector<int>>> result=Viterbi_Algorithm(edges,s,vo);
    bool path=false;
    int last = 0;
    for(int i=0;i<=edges.size();i++)
    {
        if(get<0>(result)[s.size()-1][i] == 1)
        {
            path=true;
            last = i;
            break ;
        }
    }
    if(path)
    {
        Print_Vertices(get<1>(result),last,vo,s.size()-1);
    }
    else
    {
        cout<<"NO-SUCH-PATH"<<endl;
    }
    
}

/*
Testcase 1 : 
vo = 2
s = " daabc"
output : 2 6 1 5 4 2 

Testcase : 2 
vo = 2
s = " dabc"
output : 2 6 1 4 2

Testcase : 3 
vo = 2
s = " dabb"
output : NO-SUCH-PATH

*/
