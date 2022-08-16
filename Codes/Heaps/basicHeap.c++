/*Implement heap from basic*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(vector<int> heap, int n,int i)
{
    int sizeNew = heap.size();
    int newNode = i;
    int left = 2 * i +1;
    int right = 2 * i +2;
    if (left < sizeNew && heap[left] > heap[newNode])
        newNode = left;
    if (right < sizeNew && heap[right] > heap[newNode])
        newNode = right;

    if (newNode != i)
    {
        swap(heap[i], heap[newNode]);
        heapify(heap,sizeNew, newNode);
    }
}
void insert(vector<int> heap,int n, int key)
{
    if(n == 0)
    {
        heap.push_back(key);
    }
    else
    {
        heap.push_back(key);
        for(int i=n/2 - 1; i >= 0;i--)
        {
            heapify(heap,n,i);
        }
    }
}

void deleteNode(vector<int> heap,int n, int num)
{
    int size = heap.size();
    int i;
    if(size == 0)
        return;
    for(i=0;i<size;i++)
    {
        if(num == heap[i])
            break;
    }
    swap(&heap[i], &heap[size-1]);
    heap.pop_back();

    for(i=size/2-1; i >= 0; i--)
    {
        heapify(heap,size,i);
    }
}

void display(vector<int> heap)
{
    for(int i = 0; i<heap.size();++i)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

void search(vector<int>& heap, int key)
{
    int size = heap.size();
    if(size == 0)
    {
        cout<<"Heap is empty !";
        return;
    }
    for(int i=0;i<size;i++)
    {
        if(heap[i] == key)
        {
            cout<<"Value found in heap at "<<i+1<<"position\n";
            return;
        }
        else
        {
            cout<<"Value not found\n";
        }
    }
}

void buildheap(vector<int>& heap)
{
    int n = heap.size();
    for(int i= n/2-1;i>=0;i--)
    {
        heapify(heap,n,i);
    }
}
void heapsort(vector<int> heap, int n)
{
    buildheap(heap);
    for(int i = n-1;i>0;i--)
    {
        swap(heap[0],heap[i]);
        heapify(heap,n,i);
    }
}
int main()
{
    int n,key=0;
    int ch;
    cout<<"Enter the nodes you want in heap :: ";
    cin>>n;
    vector<int> heap;
    cout<<"Enter the value of nodes :: ";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        insert(heap,n,key);
        key = 0;
    }
    do{
        cout<<"**********MENU*********\n";
        cout<<"Heap basic opertions without C++ STL\n";
        cout<<"1. Insertion in heap\n";
        cout<<"2. Deletion from heap\n";
        cout<<"3. Search in heap\n";
        cout<<"4. Heap sort\n";
        cout<<"5. Print heap\n";
        cout<<"Enter your choice :: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                cout<<"Enter the Node you want to insert in heap :: ";
                cin>>key;
                insert(heap,n,key);
                cout<<"Node inserted in heap \n";
                break;
            }
            case 2:
            {
                int del;
                cout<<"Enter the node you want to delete from heap :: ";
                cin>>del;
                deleteNode(heap,n,del);
                cout<<"Node deleted !\n";
                break;
            }
            case 3:
            {
                cout<<"Search in heap\n";
                int key;
                cout<<"Enter the value you want to search for :: ";
                cin>>key;
                search(heap,key);
                break;
            }
            case 4:
            {
                cout<<"Heap sort\n";
                heapsort(heap,n);
                cout<<"Sorted arrays is :: ";
                display(heap);
                break;
            }
            case 5:
            {
                cout<<"Print heap\n";
                display(heap);
                break;
            }
            default:{
                cout<<"Wrong choice \n";
                break;
            }
        }
    }while(ch < 6);
return 0;
}