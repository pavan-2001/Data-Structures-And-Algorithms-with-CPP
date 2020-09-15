#include<bits/stdc++.h>
using namespace std;
#include<chrono>
using namespace std::chrono;
tuple<int,int> Randomized_hire_assistant(vector<int>& v,int fees)
{
    int cost=0;
    int best=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>best)
        {
            best=v[i];
            cost+=fees;
        }
    }
    return make_tuple(best,cost);
}
tuple<int,int> Randomize_in_place(vector<int>& v,int fees)
{
    int end=v.size()-1;
    uniform_int_distribution<unsigned> u(0,end);
    default_random_engine e;
    for(int i=0;i<v.size();i++)
    swap(v[i],v[u(e)]);
    return Randomized_hire_assistant(v,fees); 
}
int main()
{   
    auto start=high_resolution_clock::now();
    cout<<"Enter the hiring fees of the employment agency : ";
    int fees;
    cin>>fees;
    cout<<"Enter the no.of assistants : ";
    int n;
    cin>>n;
    vector<int> v(n,0);
    cout<<"Enter the list of assistants qualification : ";
    for(int i=0;i<n;i++)
    cin>>v[i];
    auto p=Randomize_in_place(v,fees);
    cout<<"The best candidate's qualification is "<<get<0>(p)<<" ."<<'\n';
    cout<<"The cost of the problem is : "<<get<1>(p)<<" .\n";
    cout<<"The ranomized list is : ";
    for(auto a:v)
    cout<<a<<' ';
    cout<<'\n';
    auto elapsed=duration_cast<seconds>(high_resolution_clock::now()-start);
    cout<<"The total time taken to execute this program is "<<elapsed.count()<<" seconds."<<endl;
}

/*
Output-
                             worstcase
Enter the hiring fees of the employment agency : 100
Enter the no.of assistants : 10
Enter the list of assistants qualification : 1 2 3 4 5 6 7 8 9 10
The best candidate's qualification is 10 .
The cost of the problem is : 400 .
The ranomized list is : 7 2 4 5 6 8 9 1 3 10
The total time taken to execute this program is 27 seconds.

                             bestcase
Enter the hiring fees of the employment agency : 100
Enter the no.of assistants : 10
Enter the list of assistants qualification : 10 1 2 3 4 5 6 7 8 9
The best candidate's qualification is 10 .
The cost of the problem is : 400 .
The ranomized list is : 6 1 3 4 5 7 8 10 2 9
The total time taken to execute this program is 11 seconds.

                              Averagecase
Enter the hiring fees of the employment agency : 100
Enter the no.of assistants : 10
Enter the list of assistants qualification : 1 2 3 4 10 5 6 7 8 9
The best candidate's qualification is 10 .
The cost of the problem is : 200 .
The ranomized list is : 6 2 4 10 5 7 8 1 3 9
The total time taken to execute this program is 10 seconds.
*/
