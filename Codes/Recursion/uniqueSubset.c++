#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op,vector<string>& v)
{
    if(ip.length()==0)
    {
        v.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1,v);
    solve(ip,op2,v);
    //print(v);
    return;
}

/*void print(vector<string> v)
{
    vector<string> newsub;
    set<string>str;
    for(int i=0;i<v.size();i++)
    {
        cout<<"in for\n";
        str.insert(v[i]);
    }
    newsub.assign(str.begin(),str.end());
    for(int i=0;i<newsub.size();i++)
    {
         cout<<"Unique Subsets are:: "<<newsub[i]<<endl;
    }
    return;
}*/

int main()
{
    vector<string> v;
    set<string>str;
    vector<string> newsub;
    string ip;
    cout<<"Enter the string :: ";
    cin>>ip;
    string op =" ";
    solve(ip,op,v);
    for(int i=0;i<v.size();i++)
    {
        str.insert(v[i]);
    }
    newsub.assign(str.begin(),str.end());
    for(int i=0;i<newsub.size();i++)
    {
        cout<<"Unique subsets are :: "<<newsub[i]<<endl;
    }
    return 0;
}