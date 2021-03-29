#include<iostream>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
int longestArea(int arr[], int n)
{

  int ns[n];
  int ps[n];
  int top=-1;
  int res=-1;
  stack<int> s;
  s.push(0);
  for(int i=0;i<n;i++)
  {
  while(s.empty()==false && arr[s.top()]>=arr[i])
  {
  s.pop();
  }
  int pse=s.empty()? -1:s.top();
  ps[i]=pse;
  s.push(i);
  }
  while(s.empty()==false)
  s.pop();

  s.push(n-1);
  for(int i=n-1;i>0;i--)
  {
    while(s.empty() && arr[s.top()]>=arr[i])
    s.pop();
    int nse=s.empty()?n:s.top();
    ns[i]=nse;
    s.push(i);
  }
  for(int i=0;i<n;i++)
  {
    int ar=arr[i];
    ar+=(i-ps[i]-1)*arr[i];
    ar+=(ns[i]-i-1)*arr[i];
    res=max(res,ar);
  }
  return res;
}
int main()
{
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<longestArea(arr,n);
    return 0;
}
