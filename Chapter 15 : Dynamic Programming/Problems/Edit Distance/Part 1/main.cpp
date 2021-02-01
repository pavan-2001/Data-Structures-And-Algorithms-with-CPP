#include<bits/stdc++.h>
using namespace std;

void Edit_Distance(string s1, string s2, int m, int n ) {
    vector<vector<int>> DP(m,vector<int> (n,0));
    vector<vector<string>> operations(m,vector<string> (n));
    // Boundary conditions when s1 is empty and s2 is not.
    for( int i = 0; i < n ; i++ )
    DP[0][i] = i;

    // Boundary condition when s2 is empty and s1 is not.
    for( int i = 1 ; i < m ; i++)
    DP[i][0] = i;

    for( int i = 1 ; i < m ; i++ ) {
        for( int j = 1 ; j < n ; j++ ) {

            if ( s1[i] == s2[j] ) {
                DP[i][j] = DP[i-1][j-1];
            }
            else {
            
                int cost_of_delete = DP[i-1][j] + 1 ; 
                int cost_of_insert = DP[i][j-1] + 1 ; 
                int cost_of_replace = DP[i-1][j-1] + 1 ;
                DP[i][j] = min( cost_of_insert , cost_of_delete );
                DP[i][j] = min(DP[i][j] , cost_of_replace );
            }
        }
    }
    
    cout << "The minimum number of operations required to transform" << s1 << " to" << s2 << " is " << DP[m-1][n-1]<<endl;
}

int main()
{
    string s1 = " sunday" ;
    string s2 = " saturday" ;
    int m = s1.size() ;
    int n = s2.size();
    Edit_Distance(s1,s2,m,n);
}
