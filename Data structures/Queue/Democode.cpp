#include<bits/stdc++.h>
#include"Queue.h"
using namespace std;
int main()
{
    my_queue<string> new_queue;
    cout<<"Is Queue empty : "<<new_queue.queue_empty()<<'\n';
    new_queue.enqueue("apple");
    new_queue.enqueue("mango");
    new_queue.enqueue("grapes");
    new_queue.enqueue("orange");
    new_queue.enqueue("banana");
    cout<<"Is Queue empty : "<<new_queue.queue_empty()<<'\n';
    while(new_queue.queue_empty()!=true)
    cout<<new_queue.dequeue()<<'\n';
    cout<<"Is Queue empty : "<<new_queue.queue_empty()<<'\n';
}

/*
Output : 
Is Queue empty : 1
Is Queue empty : 0
apple
mango
grapes
orange
banana
Is Queue empty : 1
*/
