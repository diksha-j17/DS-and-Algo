#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op)
{
    if(ip.length() == 0)
    {
        //cout<<"in if \n";
        cout<<"Subsets are :: "<<op<<endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);
    return;
}
int main()
{
    vector<string> sol;
    string ip;
    cout<<"Enter the string you want subset of : " ;
    cin>>ip;
    string op = " ";
    solve(ip,op);
    return 0 ;
}