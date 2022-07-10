#include<bits/stdc++.h>
using namespace std;

int top =-1;
int arr[100];
void push(int x,int n)
{
    if(top == n-1)
    {
        cout<<"Stack is full \n";
        return;
    }
    else
    { 
        top++;
        arr[top] = x;
        cout<<"Inserted \n";
        return;
    }
}

void pop()
{
    if(top == -1)
    {
        cout<<"Stack is empty, nothing to delete \n";
    }
    else
    {
        cout<<"Deleted\n";
        top--;
    }
}

void display()
{
    if(top == -1)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        cout<<"Elements of stack are :: \n";
        for(int i = top; i>=0;i--)
        {
            cout<<arr[i];
            cout<<endl;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements in size : ";
    cin>>n;
    cout<<"Enter elements of stack :: ";
    int key;
    for(int i=0;i<n;i++)
    {
        cin>>key;
        push(key,n);
    }
    display();
    cout<<"Stack after deletion is :: ";
    pop();
    display();
    return 0;

}