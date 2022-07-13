#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>& s, int k)
{
    if(k==1){
        s.pop();
        return ;
    }
    int temp = s.top();
    s.pop();
    solve(s,k-1);
    s.push(temp);
    return;
}

stack<int> delMid(stack<int>& s, int n)
{
    if(s.size()==0)
        return s;
    int k = (n/2)+1;
    solve(s,k);
    return s;
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
    cout<<"Enter number of elements in the stack :: ";
    cin>>n;
    int key;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>key;
        s.push(key);
    }
    stack<int>res;
    cout<<"Before deletion :: ";
    display(s);
    res = delMid(s,n);
    cout<<"After deletion :: ";
    display(res);
    return 0;
}
