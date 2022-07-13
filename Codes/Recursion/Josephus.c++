#include<bits/stdc++.h>
using namespace std;

void josephus(vector<int> v, int k, int index, int& ans)
{
    if(v.size() == 1)
    {
        ans = v[0];
        return;
    }
    index = (index+k) % v.size();
    v.erase(v.begin()+index);
    josephus(v,k,index,ans);
    return;
}
int main()
{
    int n,k,ans;
    vector<int> people;
    cout<<"Enter the number of people in circle :: ";
    cin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        people.push_back(i);
    }
    cout<<"Enter count to be killed :: ";
    cin>>k;
    k = k-1;
    int index = 0;
    ans = -1;
    josephus(people,k,index,ans);
    cout<<"The person left is :: "<<ans<<endl;
    return 0;
}