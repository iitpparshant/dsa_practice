#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void countSort(vector<int>&arr,int n){
  int m= INT_MIN;
  for (int i = 0; i < n; i++)
  {
    m= max(m,arr[i]);
  }
  vector<int>freq(m+1,0);
  for (int i = 0; i < n; i++)
  {
    freq[arr[i]]++;
  }
  for (int i = 1; i <= m; i++)
  {
    freq[i]+=freq[i-1];
  }
  vector<int>ans(n);
  for (int i = n-1; i >= 0; i--)
  {
    ans[--freq[arr[i]]]=arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    arr[i]= ans[i];
  }
  
}
//   place min element at it position by inserting 
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  countSort(a,n);
  for (int i = 0; i < n; i++)
  {
    cout<<a[i]<<" ";
  }
  
  return 0;
}