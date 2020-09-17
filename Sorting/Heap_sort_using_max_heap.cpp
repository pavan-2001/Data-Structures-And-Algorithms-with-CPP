#include<bits/stdc++.h>
using namespace std;
#include<chrono>
using namespace std::chrono;
int left(int);
int right(int);
void Max_heapify(int*,int);
void Build_max_heap(int*);
void Heap_sort(int*);
int heapsize=0;
int main()
{   auto start=high_resolution_clock::now();
    cout<<"Enter the number of elements to sort : ";
    int n;
    cin>>n;
    heapsize=n;
    int seq[n+1];
    seq[0]=0;
    for (int i=1;i<=n;i++)
    cin>>seq[i];
    Heap_sort(seq);
    cout<<"The sorted sequence is : \n";
    for(int i=1;i<=n;i++)
    cout<<seq[i]<<' ';
    cout<<'\n';
    auto elapsed=duration_cast<seconds>(high_resolution_clock::now()-start);
    cout<<"The total time taken to execute is "<<elapsed.count()<<" seconds.";
}
int left(int i)
{
    return (2*i);
}
int  right(int i)
{
    return ((2*i)+1);
}
void Max_heapify(int* seq,int i)
{
    int L=left(i);
    int R=right(i);
    int largest=i;
    if(L<=heapsize&&seq[L]>seq[i])
    largest=L;
    if(R<=heapsize&&seq[R]>seq[largest])
    largest=R;
    if(largest!=i)
    {
        swap(seq[i],seq[largest]);
        Max_heapify(seq,largest);
    }
}
void Build_max_heap(int *seq)
{
    for(int i=(heapsize/2);i>=1;i--)
    Max_heapify(seq,i);
}
void Heap_sort(int* seq)
{
    Build_max_heap(seq);
    for(int i=heapsize;i>=2;i--)
    {
        swap(seq[1],seq[i]);
        heapsize-=1;
        Max_heapify(seq,1);
    }
}

/*
Output-
Enter the number of elements to sort : 10
10 1 9 2 8 3 7 4 6 5
The sorted sequence is :
1 2 3 4 5 6 7 8 9 10
The total time taken to execute is 3 seconds.
*/
