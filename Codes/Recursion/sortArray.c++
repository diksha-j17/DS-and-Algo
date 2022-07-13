#include<bits/stdc++.h>
using namespace std;


void insert(vector<int>& arr,int temp)
{
    if(arr.size()==0 || arr[arr.size()-1] <= temp)
    {
        arr.push_back(temp);
        return;
    }
    int val = arr[arr.size()-1];
    arr.pop_back();
    insert(arr,temp);
    arr.push_back(val);
    return;
}

void sortArr(vector<int>& arr)
{
    if(arr.size()==1)
        return;
    int temp = arr[arr.size()-1];
    arr.pop_back();
    sortArr(arr);
    insert(arr,temp);
}


int main()
{
    int n,key;
    cout<<"Enter number of elements you want in array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements:: \n";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        arr.push_back(key);
    }
    cout<<"Array is :: ";
    for(auto i = arr.begin(); i!= arr.end() ; i++)
    {
        cout<<(*i)<<" ";
    }
    cout<<endl;
    sortArr(arr);
    cout<<"Sorted array is :: ";
    for(auto i = arr.begin(); i!= arr.end(); i++)
    {
        cout<<(*i)<<" ";
    }
    cout<<endl;
    return 0;
}