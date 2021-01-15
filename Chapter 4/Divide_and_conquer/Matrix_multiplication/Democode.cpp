#include<bits/stdc++.h>
using namespace std;
#include<chrono>
using namespace std::chrono;
vector<vector<int> > Matrix_multiplication(vector<vector<int> >& m1,vector<vector<int> >& m2)
{
    vector<vector<int> > m3;
    for(int i=0;i<m1.size();i++)
    {   vector<int> v(m2[0].size(),0);
        for(int j=0;j<m2[0].size();j++)
        {
            v[j]=0;
            for(int k=0;k<m2.size();k++)
            {
                v[j]+=m1[i][k]*m2[k][j];
            }
        }
        m3.emplace_back(v);
    }
    return m3;
}
int main()
{   auto start=high_resolution_clock::now();
    cout<<"Enter the order of first matrix : ";
    int r1,c1,r2,c2;
    cin>>r1>>c1;
    cout<<"Enter the order of second matrix : ";
    cin>>r2>>c2;
    if(c1!=r2)
    cout<<"error: Incorrect order!!\nCan't multiply matrices\n";
    else 
    {   vector<vector<int> > m1,m2;
        cout<<"Enter the first matrix : \n"
        for(int i=0;i<r1;i++)
        {   vector<int> v(c1,0);
            for(int j=0;j<c1;j++)
            cin>>v[j];
            m1.emplace_back(v);
        }
        cout<<"Enter the second matrix : \n"
        for(int i=0;i<r2;i++)
        {   vector<int> v(c2,0);
            for(int j=0;j<c2;j++)
            cin>>v[j];
            m2.emplace_back(v);
        }
        vector<vector<int> > m3=Matrix_multiplication(m1,m2);
        cout<<'\n';
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            cout<<m3[i][j]<<' ';
            cout<<'\n';
        }
    }
      auto stop=high_resolution_clock::now();
      auto elapsed=duration_cast<seconds>(stop-start);
      cout<<"Time taken to execute : "<<elapsed.count()<<" seconds"<<endl;
}

/*
                 Testcase 1
Enter the order of first matrix : 3 3
Enter the order of second matrix : 3 4
Enter the first matrix :
1 2 3
4 5 6
7 8 9
Enter the second matrix :
1 2 3 4
5 6 7 8
9 10 11 12
The final matrix is of order 3X4
 Resultant matrix :
38 44 50 56
83 98 113 128
128 152 176 200
Time taken to execute : 15 seconds
           
                   Testcase 2
Enter the order of first matrix : 3 4
Enter the order of second matrix : 3 4
error: Incorrect order!!
Can't multiply matrices
Time taken to execute : 9 seconds

*/
