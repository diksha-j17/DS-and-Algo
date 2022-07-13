#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int temp)
{
    if(s.size()==0)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}

void reverse(stack<int>& s)
{
    if(s.size()== 1)
        return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
    return;
}

void display(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter size of the stack :: ";
    cin>>n;
    stack<int> s;
    cout<<"Enter the elements of stack :: ";
    int key;
    for(int i=0;i<n;i++)
    {
        cin>>key;
        s.push(key);
    }
    cout<<"Stack is :: ";
    display(s);
    reverse(s);
    cout<<"Reversed stack is :: ";
    display(s);
    return 0;
}