#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

bool operator< (pair<int,int> &fir,pair<int,int> &sec)
{
    return fir.first<=sec.first;
}

tuple<vector<int>,double> Bitonic_Euclidean_Travelling_Salesman(vector<pair<int,int>> points)
{
    vector<vector<double>> DP(points.size(),vector<double>(points.size(),0));
    for(int i=0;i<points.size();i++)
    {
        for(int j=0;j<points.size();j++)
        {
            if(i<j)
            {
                DP[i][j]=sqrt(pow((points[j].first-points[i].first),2)+pow((points[j].second-points[i].second),2));
            }
            else if(i==j)
            {
                DP[i][i]==0;
            }
            else
            {
                DP[i][j]=DP[j][i];
            }
        }
    }
    
    int start=0,end=0;
    vector<bool> visit(points.size(),false);
    double answer;
    vector<int> path(points.size());
    int point=0;
    while(point!=points.size()-1)
    {   double length=1e9;
        int next_point;
        for(int i=point+1;i<points.size();i++)
        {
            if(DP[point][i]<length)
            {
                length=DP[point][i];
                path[point]=i;
                next_point=i;
            }
        }
        answer+=length;
        point=next_point;
        visit[next_point]=true;
    }
    while(point!=0)
    {   double length=1e9;
        int next_point;
        for(int i=point-1;i>=0;i--)
        {
            if(!visit[i])
            {
                if(DP[point][i]<length)
                {
                    length=DP[point][i];
                    path[point]=i;
                    next_point=i;
                }
            }
        }
        answer+=length;
        point=next_point;
        visit[next_point]=true;
    }
    
    return make_tuple(path,answer);
}

void Print_Path_Of_Travelling_Salesman(vector<int> &path,int i)
{
    if(path[i]==0)
    {
        cout<<i+1<<' '<<1<<endl;
        return ;
    }
    else
    {
        cout<<i+1<<' ';
        Print_Path_Of_Travelling_Salesman(path,path[i]);
    }
}

int main()
{
    vector<pair<int,int>> points={{0,6},{1,0},{2,3},{6,1},{5,4},{7,5},{8,2}};
    sort(points.begin(),points.end());
    tuple<vector<int>,double> result=Bitonic_Euclidean_Travelling_Salesman(points);
    cout<<"The approximate length of shortest Bitonic tour for the set of points is : "<<get<1>(result)<<endl;
    cout<<"The Path taken by the Salesman is :"<<endl;
    Print_Path_Of_Travelling_Salesman(get<0>(result),0);
}

/*
Output : 
The approximate length of shortest Bitonic tour for the set of points is : 25.584
The Path taken by the Salesman is :
1 3 4 6 7 5 2 1
*/
