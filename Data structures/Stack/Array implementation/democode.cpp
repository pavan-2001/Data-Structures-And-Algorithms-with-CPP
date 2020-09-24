#include<bits/stdc++.h>
using namespace std;
#include"Stack_template.h"
int main()
{
    cout<<"Enter the size of the stack : ";
    int n;
    cin>>n;
    my_stack<string> a(n);
    cout<<"The size of the stack is "<<a.size()<<'\n';
    cout<<"Is the stack empty :  "<<a.isempty()<<'\n';
    string value;
    cout<<"Enter the value to push :\n";
    for(int i=1;i<=n;i++)
    {
        cin>>value;
        a.push(value);
    }
    cout<<"Is the stack empty : "<<a.isempty()<<'\n';
    cout<<"The peek of the stack is "<<a.peek()<<'\n';
    for(int i=1;i<=n;i++)
    cout<<"You poped out an element : "<<a.pop()<<'\n';
    a.delete_stack();
}

/*
Output-
Enter the size of the stack : 5
The size of the stack is 5
Is the stack empty :  1
Enter the value to push :
India
America
China
Germay
Russia
Is the stack empty : 0
The peek of the stack is Russia
You poped out an element : Russia
You poped out an element : Germay
You poped out an element : China
You poped out an element : America
You poped out an element : India
You successfully deleted the stack
*/
