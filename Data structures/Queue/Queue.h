#include<bits/stdc++.h>
#include<memory>
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H
template<typename T>class my_queue
{
    private:
    struct node
    {
        T value;
        node *next=nullptr;
    };
    struct node *head=new node;
    struct node *tail=new node;
    int64_t length=0;
    public:
    bool  queue_empty() const ; // checks if the queue is empty or not.
    void enqueue(T value); // Adds an element to the end of the queue.
    T dequeue(); // removes an element from the front of the queue.
};
template<typename T> bool my_queue<T>::queue_empty() const
{
    if(length==0)
    return true;
    else
    return false;
}
template<typename T > void my_queue<T>::enqueue(T value)
{
    struct node* tempnode=new node;
    tempnode->value=value;
    if(length==0)
    head=tempnode;
    tail->next=tempnode;
    tail=tempnode;
    length+=1;
}
template<typename T> T my_queue<T>::dequeue()
{
    if(length==0)
    throw out_of_range("Error : Queue is empty.");
    length-=1;
    struct node *tempnode=head;
    head=head->next;
    return tempnode->value;
}

#endif
