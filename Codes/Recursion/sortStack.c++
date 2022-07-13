#include<bits/stdc++.h>
using namespace std;

void insertStack(stack<int>& s, int temp)
{
    if(s.size()==0 || s.top() <= temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insertStack(s,temp);
    s.push(val);
    return;
}

void sortStack(stack<int>& s)
{
    if(s.size()==1)
        return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    insertStack(s,temp);
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
    int n,key;
    cout<<"Enter number of elements in stack :: ";
    cin>>n;
    stack<int> s;
    cout<<"Enter elements of stack :: \n";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        s.push(key);
    }
    cout<<"Before sort :: ";
    display(s);
    sortStack(s);
    cout<<"After sort :: ";
    display(s);
    return 0;
}