#include<bits/stdc++.h>
using namespace std;

void Optimal_Alignment( string &S1 , string &S2)
{
    vector<vector<int>> DP(S1.size()+1,vector<int>(S2.size()+1));

    for(int i = 0 ; i <= S2.size() ; i++)
    DP[0][i] = -2 * i ;

    for( int i = 0 ; i <= S1.size() ; i++)
    DP[i][0] = -2 * i ;

    for( int i = 1 ; i <= S1.size() ; i++)
    {
        for( int j = 1 ; j <= S2.size() ; j++)
        {
            if( S1[i-1] == S2[j-1] )
            {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else
            {
                DP[i][j] = max(-2 + DP[i-1][j] , -2 + DP[i][j-1] );
                DP[i][j] = max(DP[i][j] , -1 + DP[i-1][j-1] );
            }
            
        }
    }
    
    cout<<DP[S1.size()][S2.size()];
}

int main()
{
    string S1 = "GATCGGCAT" ;
    string S2 = "CAATGTGAATC";
    Optimal_Alignment( S1 , S2 );
}
