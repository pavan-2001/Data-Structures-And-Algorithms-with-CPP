#include<bits/stdc++.h>
#include<memory>
using namespace std;
#ifndef STACK_LINKED_LIST_IMPLEMENTATION_H
#define STACK_LINKED_LIST_IMPLEMENTATION_H
template<typename T> class my_stack
{   private:
/* The structure of a node using struct keyword.
which has attributes:
1) value : value holded by the node
2) prev : pointer to the previous node.
*/
/*
Attributes of class my_stack are :
1) nil: a sentinel that points to the top most node of the stack.
2)length: this keeps track of the size of stack.
*/
    struct node//priavte
    {   
    T value;
    node* prev=nullptr;
    };
    struct node* nil;//private
    int length=0;//private
    public:
    void push(T value);// pushes an element into the stack and returns nothing .
    void pop();//pops out an element and returns nothing.
    T peek() const;//returns the peek element of the stack .
    void delete_stack();//deletes the entire stack and returns nothing.
    int size() const;//returns the size of stack.
    bool isempty() const;//checks whether the stack is empty or not.true if empty else returns false.
};
template<typename T> bool my_stack<T>::isempty() const
{
    if(size()==0)
    return true;
    else
    return false;
}
template<typename T> void my_stack<T>::push(T value)
{
    struct node* n=new node;
    n->value=value;
    n->prev=nil;
    nil=n;
    length+=1;
}
template<typename T> void my_stack<T>::pop() 
{
    if(isempty())
    throw out_of_range("error: The Stack is empty ");
    nil=nil->prev;
    length-=1;
}
template<typename T> T my_stack<T>::peek() const
{   
    if(!isempty())
    return nil->value;
    else
    throw out_of_range("error: The stack is empty ");
}
template<typename T> void my_stack<T>::delete_stack() 
{
    nil=nullptr;
    length=0;
}
template<typename T> int my_stack<T>::size() const
{
    return length;
}
#endif
