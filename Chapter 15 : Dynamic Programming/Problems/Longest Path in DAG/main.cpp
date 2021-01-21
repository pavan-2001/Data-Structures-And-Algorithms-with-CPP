#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void Depth_First_Search(map<int64_t,vector<int64_t>> &graph,vector<int64_t> &DP,vector<bool> &visit,vector<int64_t> &Nodes,int64_t &i)
{
    if(visit[i])
    return ;
    visit[i]=true;
    DP[i]=0;
    for(int64_t j=0;j<graph[i].size();j++)
    {   int64_t neighbour=graph[i][j];
        if(!visit[neighbour])
        {
            Depth_First_Search(graph,DP,visit,Nodes,neighbour);
        }
        if(DP[i]<(DP[neighbour]+1))
        {
            DP[i]=DP[neighbour]+1;
            Nodes[i]=neighbour;
        }
    }
    return ;
}

tuple<vector<int64_t>,int64_t,int64_t> Longest_Path_In_DAG(map<int64_t,vector<int64_t>> &graph,int64_t &n)
{
    vector<bool> visit(n+1,false);
    vector<int64_t> DP(n+1);
    vector<int64_t> Nodes(n+1,0);
    for(int64_t i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            Depth_First_Search(graph,DP,visit,Nodes,i);
        }
    }
    int64_t From_node;
    int64_t Length=0;
    for(int64_t i=1;i<=n;i++)
    {
        if(Length<DP[i])
        {
            Length=DP[i];
            From_node=i;
        }
    }

    return make_tuple(Nodes,From_node,Length);
}

void Print_Longest_Path(vector<int64_t> &Nodes,int64_t i)
{
    if(i==0)
    return ;
    else
    {
        cout<<i<<' ';
        Print_Longest_Path(Nodes,Nodes[i]);
    }
}

int main()
{
    map<int64_t,vector<int64_t>> graph;
    graph[1]={3,4};
    graph[2]={3,4};
    graph[3]={};
    graph[4]={3};
    graph[5]={2,3,1};
    int64_t n=graph.size();
    tuple<vector<int64_t>,int64_t,int64_t> result=Longest_Path_In_DAG(graph,n);
    cout<<"The Length Longest Path in Directed Acyclic Graph is : "<<get<2>(result)<<endl;
    Print_Longest_Path(get<0>(result),get<1>(result));
}

/*
Output : 
The Length Longest Path in Directed Acyclic Graph is : 3
5 2 4 3
*/
