#include<bits/stdc++.h>
using namespace std;
#include"Stack_linked_list_implementation.h"
int main()
{
    my_stack<string> a;
    string value;
    cout<<"Enter the value to push :\n";
    for(int i=1;i<=5;i++)
    {
        cin>>value;
        a.push(value);
    }
    for(int i=1;i<=5;i++)
    {
        cout<<"The peek of the stack is : "<<a.peek()<<endl;
        cout<<"The size of the stack is : "<<a.size()<<endl;
        cout<<"The stack is empty ? "<<a.isempty()<<endl;
        a.pop();
    }
    a.delete_stack();
    cout<<"The peek of the stack is : "<<a.peek();
}
// 0:false
// 1:true
/*
Output-
Enter the value to push :
india
america
japan
china
brazil
The peek of the stack is : brazil
The size of the stack is : 5
The stack is empty ? 0
The peek of the stack is : china
The size of the stack is : 4
The stack is empty ? 0
The peek of the stack is : japan
The size of the stack is : 3
The stack is empty ? 0
The peek of the stack is : america
The size of the stack is : 2
The stack is empty ? 0
The peek of the stack is : india
The size of the stack is : 1
The stack is empty ? 0
The peek of the stack is : terminate called after throwing an instance of 'std::out_of_range'
  what():  error: The stack is empty
*/
