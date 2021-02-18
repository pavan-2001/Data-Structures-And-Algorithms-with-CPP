#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Image_compression_by_seam_carving(vector<vector<int>> &Intensities)
{
    int n = Intensities.size(); // no. of rows...
    int m = Intensities[1].size(); // no. of columns... 
    vector<vector<int>> DP(n , vector<int>(m,0)) ; 
    DP[1] = Intensities[1] ;
    for(int i = 2 ; i < n ; i++)
    {   
        for(int j = 1 ; j < m ;j++)
        {
            if( j == 1 )
            {
                DP[i][j] = (DP[i-1][j] < DP[i-1][j+1]) ? ( DP[i-1][j] + Intensities[i][j] ) : ( DP[i-1][j+1] + Intensities[i][j] ) ;
            }
            else if( j == m-1 )
            {
                DP[i][j] = ( DP[i-1][j-1] < DP[i-1][j] ) ? ( DP[i-1][j-1] + Intensities[i][j] ) : ( DP[i-1][j] + Intensities[i][j] ) ;
            }
            else
            {
                DP[i][j] = ( DP[i-1][j-1] < DP[i-1][j]) ? (DP[i-1][j-1] + Intensities[i][j]) : (DP[i-1][j] + Intensities[i][j]) ;
                DP[i][j] = (DP[i-1][j+1] + Intensities[i][j] < DP[i][j]) ? (DP[i-1][j+1] + Intensities[i][j]) : (DP[i][j]) ;
            }
        }
    }

    return DP;
}

void Back_Tracking(vector<vector<int>> &Intensities, int i, int j)
{
    if( i == 1)
    {
        cout<<'('<<i<<','<<j<<')';
        return ;
    }
    else if(j == 1)
    {
        if(Intensities[i-1][j] < Intensities[i-1][j+1])
        {
            Back_Tracking(Intensities,i-1,j);
            cout<<" -> ("<<i<<','<<j<<')';
        }
        else{
            Back_Tracking(Intensities,i-1,j+1);
            cout<<" -> ("<<i<<','<<j<<')';
        }
    }
    else if(j == Intensities[1].size()-1)
    {
        if(Intensities[i-1][j-1] < Intensities[i-1][j])
        {
            Back_Tracking(Intensities,i-1,j-1);
            cout<<" -> ("<<i<<','<<j<<')';
        }
        else
        {
            Back_Tracking(Intensities,i-1,j);
            cout<<" -> ("<<i<<','<<j<<')';
        }
    }
    else
    {
        if(Intensities[i-1][j-1] < Intensities[i-1][j] && Intensities[i-1][j-1] < Intensities[i-1][j+1])
        {
            Back_Tracking(Intensities,i-1,j-1);
            cout<<" -> ("<<i<<','<<j<<')';
        }
        else if(Intensities[i-1][j] < Intensities[i-1][j-1] && Intensities[i-1][j] < Intensities[i-1][j+1])
        {
            Back_Tracking(Intensities,i-1,j);
            cout<<" -> ("<<i<<','<<j<<')';
        }
        else
        {
            Back_Tracking(Intensities,i-1,j+1);
            cout<<" -> ("<<i<<','<<j<<')';
        }
    }

}

int main()
{   
    int n = 4 ;
    vector<vector<int>> Intensities = { {} , {0,9,9,0,9,9} , {0,9,1,9,8,9} , {0,9,9,9,9,0} , {0,9,9,9,0,9}};

    vector<vector<int>> result = Image_compression_by_seam_carving(Intensities);
    int min_index ,temp = 1e9;
    for(int i = 1 ; i < result[n].size() ; i++)
    {
        if(result[n][i] < temp)
        {
            temp=result[n][i] ;
            min_index = i;
        }
    }
    cout<<"The Lowest Disruption measure is  : "<< temp << endl;
    Back_Tracking(result,n,min_index);
}
