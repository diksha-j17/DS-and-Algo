#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int src, int dest, int help,int n)
{
    //int ctr=0;
    if(n==1){
        cout<<"Moving plate number "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    solve(src,help,dest,n-1);
        cout<<"Moving plate number "<<n<<" from "<<src<<" to "<<help<<endl;
    solve(help,dest,src, n-1);
    //cout<<"Number of shifts are :: "<<ctr<<endl;
        return;
}

int main()
{
    int n;
    cout<<"Enter total number of disks :: ";
    cin>>n;
    int src=1;
    int dest=3; 
    int help = 2;
    //int ctr=0;
    solve(src,dest,help,n);
}