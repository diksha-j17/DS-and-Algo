#include<bits/stdc++.h>
using namespace std;

vector<int> neargrright(vector<int> arr)
{
    vector<int> ans;
    stack<int> s;
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(s.size()==0)
        {
            ans.push_back(-1);
        }
        else if(s.size()>0 && s.top()>arr[i])
        {
            ans.push_back(s.top());
        }
        else if(s.size()>0 && s.top()<=arr[i])
        {
            while(s.size()>0 && s.top()<=arr[i])
            {
                s.pop();
            }
                if(s.size()==0)
                {
                    ans.push_back(-1);
                }
                else 
                {
                    ans.push_back(s.top());
                }
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> neargrleft(vector<int> arr)
{
    vector<int> v;
    stack<int> r;
    for(int i=0;i<arr.size();i++)
    {
        if(r.size()==0)
        {
            v.push_back(-1);
        }
        else if(r.size()>0 && r.top()>arr[i])
        {
            v.push_back(r.top());
        }
        else if(r.size()>0 && r.top()<=arr[i])
        {
            while(r.size()>0 && r.top()<=arr[i])
            {
                r.pop();
            }
                if(r.size()==0)
                {
                    v.push_back(-1);
                }
                else 
                {
                    v.push_back(r.top());
                }
        }
        r.push(arr[i]);
    }
    return v;
}
vector<int> nearsmleft(vector<int> arr)
{
    vector<int> v;
    stack <int> s;
    for(int i=0;i<arr.size();i++)
    {
        if(s.size() == 0)
            v.push_back(-1);
        else if(s.size()>0 && s.top()<arr[i])
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top()>=arr[i])
        {
            while(s.size()>0 && s.top()>=arr[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                v.push_back(-1);
            }
            else 
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return v;
}
vector<int> nearsmright(vector<int> arr)
{
    vector<int> vec;
    stack<int> s;
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(s.size() == 0)
        {
            vec.push_back(-1);
        }
        else if(s.size()>0 && s.top()<arr[i])
        {
            vec.push_back(s.top());
        }
        else if(s.size()>0 && s.top()>=arr[i])
        {
            while(s.size()>0 && s.top()>=arr[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                vec.push_back(-1);
            }
            else 
            {
                vec.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(vec.begin(),vec.end());
    return vec;
}
int main()
{
    int n;
    cout<<"Enter number of elements in array/stack \n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array :: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> res;
    res = neargrright(arr);
    cout<<"Nearest greater element to the right of element is :: ";
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    vector<int>ans(n);
    ans = neargrleft(arr);
    cout<<"Nearest greater element to left of element is :: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    vector<int> v;
    v = nearsmleft(arr);
    cout<<"Nearest smaller to left of array elements is :: ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    vector<int>vec;
    vec = nearsmright(arr);
    cout<<"Nearest smaller to right of array elements is :: ";
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
