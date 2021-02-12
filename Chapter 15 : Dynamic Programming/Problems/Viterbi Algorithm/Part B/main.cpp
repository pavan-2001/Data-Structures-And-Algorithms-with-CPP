#include<bits/stdc++.h>
using namespace std;

vector<vector<tuple<int,double>>> Viterbi_Algorithm(map<int,vector<tuple<int,char,double>>> &G, string &s, int Vo)
{
    vector<vector<int>> DP(s.size(),vector<int>(G.size()+1,0));
    vector<vector<tuple<int,double>>> path(s.size(),vector<tuple<int,double>>(G.size()+1,{0,0}));

    DP[0][Vo] = 1;
    path[0][Vo]={0,1};

    for(int i=1;i<s.size();i++)
    {   
        for(int j=1;j<=G.size();j++)
        {
            if(DP[i-1][j]==1)
            {
                for(int k=0;k<G[j].size();k++)
                {
                    if(get<1>(G[j][k])==s[i])
                    {
                        DP[i][get<0>(G[j][k])]=1;
                        path[i][get<0>(G[j][k])]= get<1>(path[i][get<0>(G[j][k])]) >= get<2>(G[j][k])*get<1>(path[i-1][j]) ? path[i][get<0>(G[j][k])] : make_tuple(j,(get<2>(G[j][k])*get<1>(path[i-1][j])));
                    }
                }
            }
        }
    }
    return path;
}

void Print_Path(vector<vector<tuple<int,double>>> &path,int i,int j)
{
    if(i==0)
    {
        cout<<j;
        return ;
    }
    else{
        Print_Path(path,i-1,get<0>(path[i][j]));
        cout<<" -> "<<j;
    }
}

int main()
{
    map<int,vector<tuple<int,char,double>>> G;
    G[1]={{2,'d',0.5},{4,'d',0.8}};
    G[2]={{6,'e',0.3}};
    G[3]={{2,'e',0.7}};
    G[4]={{3,'e',0.1}};
    G[5]={{4,'d',0.2}};
    G[6]={{5,'a',0.6},{1,'a',0.4}};
    int Vo = 6;
    string s = " ade";
    vector<vector<tuple<int,double>>> result  = Viterbi_Algorithm(G,s,Vo);
    int index=0;
    double prob=0;
    for(int i=1;i<=G.size();i++)
    {
        if(get<1>(result[s.size()-1][i])>prob)
        {
            index=i;
            prob=get<1>(result[s.size()-1][i]);
        }
    }
    if(index==0)
    {
        cout<<"NO-SUCH-PATH"<<endl;
    }
    else
    {
        cout<<"The Maximum possible Probability : "<<prob<<endl;
        Print_Path(result,s.size()-1,index);
    }
    
}

/*
Output : 
The Maximum possible Probability : 0.06
6 -> 1 -> 2 -> 6
*/
