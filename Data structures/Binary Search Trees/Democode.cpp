#include<bits/stdc++.h>
#include"Binary_search_trees.h"
#include<chrono>
using namespace std::chrono;
using namespace std;
int main()
{
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
    fout.open("Preorder_traversal.txt");
    a.Preorder_traversal(fout,a.root);
    fout.close();
    fout.open("Postorder_traversal.txt");
    a.Postorder_traversal(fout,a.root);
    fout.close();
   bool found=a.Search(a.root,22)==nullptr?false:true;
   cout<<"Is 22 in the BST ? "<<(found?"True":"False");
   found=a.Search(a.root,-94576)==nullptr?false:true;
   cout<<"\nIf -94576 in the BST ? "<<(found?"True":"False");
   cout<<"\nThe highest value in the BST is : "<<a.Maximum(a.root)->value;
   cout<<"\nThe lowest value in the BST is : "<<a.Minimum(a.root)->value;
   cout<<"\nThe Successor of 22 is : "<<a.Successor(a.Search(a.root,22))->value;
   cout<<"\nThe Predecessor of 22 is : "<<a.Predeccessor(a.Search(a.root,22))->value;
   found=a.Search(a.root,24)==nullptr?false:true;
   cout<<"\nIs 24 in the BST ? "<<(found?"True":"False");
   a.Delete(24);
   found=a.Search(a.root,24)==nullptr?false:true;
   cout<<"\nIs 24 in the BST ? "<<(found?"True":"False");
   a.Delete(22);
   found=a.Search(a.root,22)==nullptr?false:true;
   cout<<"\nIs 22 in the BST ? "<<(found?"True":"False");
   cout<<"\nThe root of the tree is : "<<a.root->value;
   a.Delete(25);
   cout<<"\nThe new root of the tree is : "<<a.root->value;
   found=a.Search(a.root,25)==nullptr?false:true;
   cout<<"\nIs 25 in BST : "<<(found?"True":"False");
   cout<<"\nThe successor of 15 is : "<<a.Successor(a.Search(a.root,15))->value;
   cout<<"\nThe successor of 18 is : "<<a.Successor(a.Search(a.root,18))->value;
   auto elapsed=duration_cast<microseconds>(high_resolution_clock::now()-start);
   cout<<"\nTotal time taken to execute is : "<<elapsed.count()<<" microseconds.";
}
/*
Output:
Is 22 in the BST ? True
If -94576 in the BST ? False
The highest value in the BST is : 90
The lowest value in the BST is : 4
The Successor of 22 is : 24
The Predecessor of 22 is : 18
Is 24 in the BST ? True
Is 24 in the BST ? False
Is 22 in the BST ? False
The root of the tree is : 25
The new root of the tree is : 31
Is 25 in BST : False
The successor of 15 is : 18
The successor of 18 is : 31
Total time taken to execute is : 48786 microseconds.
*/
