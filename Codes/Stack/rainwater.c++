#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int traprain(int n,int arr[])
{
    int maxl[n];
    int maxr[n];
    maxl[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        maxl[i] = max(maxl[i-1],arr[i]);
    }
    maxr[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        maxr[i] = max(maxr[i+1],arr[i]);
    }
    int water[n];
    for(int i=0;i<n;i++)
    {
        water[i] = (min(maxl[i],maxr[i])) - arr[i]; 
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += water[i];
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter num of elements :: ";
    cin>>n;
    int arr[n];
    cout<<"Enter heights :: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res = traprain(n,arr);
    cout<<"Maximum water is :: "<<res<<endl;
    return 0;
}
