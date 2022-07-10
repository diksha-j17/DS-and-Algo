#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int minele = 32000;

void Push(int a)
{
    if(s.size()==0)
    {
        s.push(a);
        minele = a;
    }
    else{
        if(a >= minele)
            s.push(a);
        else if(a < minele)
        {
            s.push(2*a - minele);
            minele = a;
        }
    }
}

void Pop()
{
    if(s.size() == 0)
        return;
    else{
        if(s.top() >= minele)
            s.pop();
        else if(s.top() < minele)
            minele = 2*minele - s.top();
            s.pop();
    }
}

int Top()
{
    if(s.size() == 0)
    {
        return -1;
    }
    else
    {
        if(s.top() >= minele)
            return s.top();
        else if(s.top()< minele)
            return minele;
    }
    return -1;
}

int getmin()
{
    if(s.size()==0)
        return -1;
    return minele;
}

void display()
{
    cout<<"Contents of stack are :: \n";
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main()
{
    int n,minn,topp;
    Push(3);
    Push(4);
    Push(10);
    topp = Top();
    cout<<"Top element is :: "<<topp<<endl;
    minn = getmin();
    cout<<"Current min element is :: "<<minn<<endl;
    Push(2);
    topp = Top();
    cout<<"Top element is :: "<<topp<<endl;
    minn = getmin();
    cout<<"Current min element is :: "<<minn<<endl;
    Push(5);
    Push(4);
    Push(11);
    Pop();
    minn = getmin();
    cout<<"Current min element is :: "<<minn<<endl;
    Pop();
    Push(1);
    topp = Top();
    cout<<"Top element is :: "<<topp<<endl;
    display();
}