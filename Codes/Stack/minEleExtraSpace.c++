#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> ss;

void push (int a)
{
    s.push(a);
    if(ss.size()==0 || ss.top()>= a)
        ss.push(a);
    return;
}

int pop()
{
    if(s.size()==0)
        return -1;
    int ans = s.top();
        s.pop();
    if(ss.top() == ans)
        ss.pop();
    return ans;
}

int getmin()
{
    if(ss.size() == 0)
        return -1;
    return ss.top();
}

void display()
{
    cout<<"Content of stack is :: ";
   while(!s.empty())
   {
       cout<<s.top()<<endl;
       s.pop();
   }
}
int main()
{
    int n,minn;
    push(3);
    push(4);
    minn = getmin();
    cout<<"Current min element is :: "<<minn<<endl;
    push(2);
    minn = getmin();
    cout<<"Current min element is :: "<<minn<<endl;
    push(5);
    n = pop();
    cout<<"popped element is :: "<<n<<endl;
    minn = getmin();
    cout<<"Current min element is :: "<<minn<<endl;
    display();
    return 0;
}
