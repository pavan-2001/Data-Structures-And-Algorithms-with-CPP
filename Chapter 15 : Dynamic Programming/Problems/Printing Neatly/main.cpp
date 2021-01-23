#include<bits/stdc++.h>
using namespace std;

void Print_The_Paragraph(vector<vector<int>> &word_length,vector<string> &words,vector<int> &line_breaks,int &max_line_width)
{
    int i = 0;
    while(i < words.size())
    {
        int j = line_breaks[i] ;
        if(j - i == 1 || j >= words.size()-1)
        {
            int spacesToRight = max_line_width - word_length[i][j-1] - ( j - i - 1);
            cout << words[i];
            for(int k = i + 1; k < j ; k++)
            cout << '_' << words[k];
            for(int k = 1; k <= spacesToRight ; k++)
            cout << '_';
            cout << endl;
        }
        else
        {
            int line_split = j - i - 1;
            int no_of_spaces = ( max_line_width - word_length[i][j-1] );
            int req_spacing = ( no_of_spaces / line_split  );
            int left_spaces = no_of_spaces % line_split;
            cout << words[i];
            for(int k = i+1; k < j; k++)
            {
                
                for(int m = 1 ; m <= req_spacing; m++)
                cout << '_';
                
                if(left_spaces > 0)
                {
                    cout << '_';
                    left_spaces--;
                }

                cout << words[k];
            }

            cout << endl;
        }
        i = j;
    }
}


void Printing_Neatly( vector<string> &words ,int &max_line_width )
{
    vector<vector<int>> DP(words.size(),vector<int>(words.size(),1e9));
    vector<vector<int>> word_length(words.size(),vector<int>(words.size(),0));
    int n = words.size();

    for(int i = 0; i < n; i++)
    {
        DP[i][i] = pow( max_line_width - words[i].size() , 3 );
        word_length[i][i] = words[i].size();
    }
    
    for(int i = 0;i < n; i++)
    {   
        for(int j = i + 1; j < n && ( word_length[i][j-1] + words[j].size() + (j - i) <= max_line_width) ; j++)
        {
            word_length[i][j] = word_length[i][j-1] + words[j].size();
            DP[i][j] = pow( max_line_width - (word_length[i][j] +(j - i)) , 3);
        }
    }

    vector<int> line_breaks(n,0);
    vector<int> break_cost(n+1,0);
    int i = n - 1 ;
    while( i >= 0 )
    {   
        break_cost[i] = 1e9;
        for(int j = n; j > i; j--)
        {
            if( DP[i][j-1] !=1e9 && DP[i][j-1] + break_cost[j] < break_cost[i])
            {
                line_breaks[i] = j;
                break_cost[i] = DP[i][j-1] + break_cost[j];
            }
        }
        i--;
    }
    cout << "The minimum sum of the cubes of the number of extra space characters at the end of lines is : " << break_cost[0] << endl;
    cout << endl;
    Print_The_Paragraph(word_length,words,line_breaks,max_line_width);
    cout << endl;
    cout << "** Attention  :  single _ (underscore) denotes a single space character **";
}

int main()
{
    vector<string> words = {"what","must","be","acknowledgment","shall","be"};
    int max_line_width = 15;
    Printing_Neatly( words , max_line_width );
}

/*
Output : 

The minimum sum of the cubes of the number of extra space characters at the end of lines is : 371

what___must__be
acknowledgment_
shall_be_______

** Attention  :  single _ (underscore) denotes a single space character **

*/
