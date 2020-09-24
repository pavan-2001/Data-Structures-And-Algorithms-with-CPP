#include<memory>
#include<iostream>
using namespace std;
#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H
template<typename T> class my_stack
{   
    private:
    T* ptr=nullptr;
    int top=-1;
    int end=-1;
    public:
    // constructor
    my_stack(int n)
    {
        ptr=new T[n];
        end=n;
    }
    //funciton to return the size of the stack
    int size() const{return end;}
    // function to check if the stack is empty or not
    bool isempty()const;
    // function to push elements into the stack
    void push(T value);
    //function to pop elements from the stack
    T pop();
    //function to return the top most element of the stack
    T peek();
    //function to delete the stack
    void delete_stack();
};
template<typename T> bool my_stack<T>::isempty() const
{
    if(top==-1)
    return true;
    return false;
}
template<typename T> void my_stack<T>::push(T value)
{
    if(top>=end)
    throw out_of_range("Stack overflow");
    top+=1;
    ptr[top]=value;
}
template<typename T> T my_stack<T>::pop()
{
    if(isempty())
    throw out_of_range("Stack underflow");
    T value=ptr[top];
    top-=1;
    return value;
}
template<typename T> T my_stack<T>::peek()
{
    return ptr[top];
}
template<typename T> void my_stack<T>::delete_stack()
{
    delete [] ptr;
    cout<<"You successfully deleted the stack";
}
#endif