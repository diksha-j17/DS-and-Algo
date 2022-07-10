#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int> leftarr(vector<int>arr)
{
    vector<int>left;
    stack<pair<int,int>> s;
    
    for(int i=0;i<arr.size();i++)
    {
        if(s.size() == 0)
        {
            left.push_back(-1);
        }
        else if(s.size()>0 && s.top().first<arr[i])
        {
            left.push_back(s.top().second);
        }
        else if (s.size()>0 && s.top().first>=arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
            {   
                s.pop();
            }
                if(s.size() == 0)
                {
                    left.push_back(-1);
                }
                else{
                    left.push_back(s.top().second);
                }
        }
        s.push({arr[i],i});
    }
    return left;
}
vector<int> rightarr(vector<int>arr)
{
    //NSR
    vector<int> right;
    stack<pair<int,int>> r;
    for(int i=arr.size()-1;i>=0;i--)
    {
       if(r.size()==0)
       {
           right.push_back(7);
       } 
       else if(r.size()>0 && r.top().first<arr[i])
       {
           right.push_back(r.top().second);
       }
       else if(r.size()>0 && r.top().first>=arr[i])
       {
           while(r.size()>0 && r.top().first>=arr[i])
           {
               r.pop();
           }
           if(r.size()==0)
           {
               right.push_back(7);
           }
           else{
               right.push_back(r.top().second);
           }
       }
       r.push({arr[i],i});
    }
    reverse(right.begin(),right.end());
    return right;
}
int MAH(vector<int>arr,int n)
{
    vector<int>res;
    vector<int>res2;
    res = leftarr(arr);
    res2 = rightarr(arr);
    vector<int>width(n,0);
    for(int i=0;i<n;i++)
    {
        width[i] = res2[i] - res[i] -1;
    }
    vector<int>ans(n,0);
    for(int i=0;i<n;i++)
    {
        ans[i] = arr[i] * width[i];
    }
    int result = *max_element(ans.begin(),ans.end());
    return result;
}
int main()
{
    int n;
    cout<<"Enter number of towers in histogram :: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter heights of towers :: \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int test = MAH(arr,n);
    cout<<"Maximum area of historgram is :: "<<test<<endl;
    return 0;
}