/*
Each node in a binary tree consists of the attributes.
1) key.
2) pointer to left child.
3) pointer to right child.

Operations on Binary Search Tree.
1) Searching.
2) Minimun.
3) Maximum.
4) Predeccessor.
5) Successor.
6) Insert.
7) Delete.

Traversals on a Binary Search Tree.
1) In-order traversal.
2) Pre-order traversal.
3) Post-order trversal.

*/
#include<bits/stdc++.h>
using namespace std;
#ifndef BINARY_SEARCH_TREES_H
#define BINARY_SEARCH_TREES_H
template<typename T> class BST
{
    private:
    struct node
    {
        T value;
        node *parent=nullptr;
        node *left=nullptr;
        node *right=nullptr; 
    };  
    public:
    node *root=nullptr;
    void Insert(T value) ;
    void Delete(T value) ;
    node* Search(node *x,T value) ;
    node* Maximum(node *x) ;
    node* Minimum(node *x);
    node* Successor(node *x);
    node* Predeccessor(node *x);
    void Inorder_traversal(ofstream &fout,node *x);
    void Preorder_traversal(ofstream &fout,node *x);
    void Postorder_traversal(ofstream &fout,node *x);
    void write(ofstream &fout,T value);
};
template<typename T> void BST<T>::Insert(T value)
{
    if(root==nullptr)
    {
        node* new_node=new node;
        new_node->value=value;
        root=new_node;
    }
    else
    {
        struct node* tempnode=root;
        while(tempnode!=nullptr)
        {
            if(tempnode->value>value)
            {
                if(tempnode->left==nullptr)
                {
                    struct node* new_node=new node;
                    new_node->value=value;
                    tempnode->left=new_node;
                    new_node->parent=tempnode;
                    tempnode=nullptr;
                }
                else
                {
                    tempnode=tempnode->left;
                } 
            }
            else
            {
                if(tempnode->right==nullptr)
                {
                    struct node* new_node=new node;
                    new_node->value=value;
                    new_node->parent=tempnode;
                    tempnode->right=new_node;
                    tempnode=nullptr;
                }
                else
                {
                    tempnode=tempnode->right;
                }
            }         
        }
    }
    
}
template<typename T> class BST<T>::node* BST<T>::Search(node *x,T value)
{
    if(x==nullptr||x->value==value)
    return x;
    else if(value>x->value)
    return Search(x->right,value);
    else
    return Search(x->left,value);
}
template<typename T> class BST<T>::node* BST<T>::Maximum(node *x)
{
    if(x->right==nullptr)
    return x;
    else
    return Maximum(x->right);
}
template<typename T> class BST<T>::node* BST<T>::Minimum(struct node* x)
{
    if(x->left==nullptr)
    return x;
    else
    return Minimum(x->left);
}
template<typename T> class BST<T>::node* BST<T>::Successor(struct node* x)
{
    if(x->right!=nullptr)
    return Minimum(x->right);
    struct node* y=new node;
    y=x->parent;
    while(y!=nullptr&&x==y->right)
    {
        x=y;
        y=y->parent;
    }
    return y;
}
template<typename T> class BST<T>::node* BST<T>::Predeccessor(struct node* x)
{
    if(x->left!=nullptr)
    return Maximum(x->left);
    else
    {
        struct node* y=x->parent;
        y=x->parent;
        while(y!=nullptr&&x==y->left)
        {
            x=y;
            y=y->parent;
        }
        return y;
    }
    
}
template<typename T> void BST<T>::Inorder_traversal(ofstream &fout,node *x) 
{
    if(x==nullptr)
    return ;
    else
    {
        Inorder_traversal(fout,x->left);
        write(fout,x->value);
        Inorder_traversal(fout,x->right);
    }
}
template<typename T> void BST<T>::Preorder_traversal(ofstream &fout,node *x)
{
    if(x==nullptr)
    return ;
    else
    {
        write(fout,x->value);
        Preorder_traversal(fout,x->left);
        Preorder_traversal(fout,x->right);
    }
    
}
template<typename T> void BST<T>::Postorder_traversal(ofstream &fout,node *x)
{
    if(x==nullptr)
    return ;
    else
    {
        Postorder_traversal(fout,x->left);
        Postorder_traversal(fout,x->right);
        write(fout,x->value);
    }
    
}
template<typename T> void BST<T>::Delete(T value)
{
    node *node_to_delete=Search(root,value);
    if(node_to_delete==nullptr)
    {
        cout<<"Error: Value doesn't exists in the tree.";
        return ;
    }
    else if(node_to_delete->left==nullptr&&node_to_delete->right==nullptr)
    {
        if(node_to_delete->parent->left==node_to_delete)
        node_to_delete->parent->left=nullptr;
        else
        node_to_delete->parent->right=nullptr;
        delete node_to_delete;
    }
    else if((node_to_delete->left!=nullptr&&node_to_delete->right==nullptr)||(node_to_delete->left==nullptr&&node_to_delete->right!=nullptr))
    {
        node_to_delete->value=node_to_delete->left!=nullptr?node_to_delete->left->value:node_to_delete->right->value;
        node_to_delete->left=node_to_delete->right=nullptr;
    }
    else
    {
        node *successor_of_node_to_delete=Minimum(node_to_delete->right);
        successor_of_node_to_delete->parent->left=successor_of_node_to_delete->right;
        node_to_delete->value=successor_of_node_to_delete->value;
        delete successor_of_node_to_delete;
    }
}
template<typename T> void BST<T>::write(ofstream &fout,T value)
{
    fout<<value<<'\n';
}
#endif