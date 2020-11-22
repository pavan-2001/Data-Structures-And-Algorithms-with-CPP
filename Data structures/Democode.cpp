#include<bits/stdc++.h>
#include"Binary_search_trees.h"
#include<chrono>
using namespace std::chrono;
using namespace std;
int main()
{
    /*
    ofstream fout;
    fout.open("input.txt");
    uniform_int_distribution<unsigned> u(0,10000000000);
    default_random_engine e;
    for(int64_t i=1;i<=10000000;i++)
    fout<<u(e)<<'\n';
    */
    BST<int64_t> a;
    ifstream fin;
    fin.open("input.txt");
    int64_t s;
    while(fin>>s)
    a.Insert(s);
    fin.close();
    auto start=high_resolution_clock::now();
    ofstream fout;
    fout.open("Inorder_traversal.txt");
    a.Inorder_traversal(fout,a.root);
    fout.close();
    auto elapsed=duration_cast<seconds>(high_resolution_clock::now()-start);
    cout<<"Time taken to execute Inorder traversal on 2*(10^6) random values is : "<<elapsed.count()<<" seconds\n";
    start=high_resolution_clock::now();
    fout.open("Preorder_traversal.txt");
    a.Preorder_traversal(fout,a.root);
    fout.close();
    elapsed=duration_cast<seconds>(high_resolution_clock::now()-start);
    cout<<"Time taken to execute Preorder traversal on 2*(10^6) random values is : "<<elapsed.count()<<" seconds\n";
    start=high_resolution_clock::now();
    fout.open("Postorder_traversal.txt");
    a.Postorder_traversal(fout,a.root);
    fout.close();
    elapsed=duration_cast<seconds>(high_resolution_clock::now()-start);
    cout<<"Time taken to execute Postorder traversal on 2*(10^6) random values is : "<<elapsed.count()<<" seconds\n";
}