#include<bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> arr)
{
    vector<int> res;
    stack<pair<int,int>> s;
    for(int i=0;i<arr.size();i++)
    {
        if(s.size()==0)
        {
            res.push_back(-1);
        }
        else if(s.size()>0 && s.top().first>arr[i])
        {
            res.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first<=arr[i])
        {
            while(s.size()>0 && s.top().first<=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                res.push_back(-1);
            }
            else{
                res.push_back(s.top().second);
            }
        }
        s.push({arr[i],i});
    }
    for(int i=0;i<res.size();i++)
    {
        res[i] = i - res[i];
    }
    return res;
}
int main()
{
    int n;
    cout<<"Enter number of elements in array :: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements :: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\n";
    vector<int>ans;
    ans = stockspan(arr);
    cout<<"The solution to stock span problem is :: \n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}