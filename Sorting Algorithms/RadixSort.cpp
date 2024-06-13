#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void countSort(vector<int>&arr,int n,int pos){
  vector<int>freq(10,0);
  for (int i = 0; i < n; i++)
  {
    freq[(arr[i]/pos)%10]++;
  }
  for (int i = 1; i < 10; i++)
  {
    freq[i]+=freq[i-1];
  }
  vector<int>ans(n);
  for (int i = n-1; i >= 0; i--)
  {
    ans[--freq[(arr[i]/pos)%10]]=arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    arr[i]= ans[i];
  }
  
}
void radixSort(vector<int>&arr,int n){
  int m= INT_MIN;
  for (int i = 0; i < n; i++)
  {
    m= max(m,arr[i]);
  }
  for(int i=1;m/i>0;i*=10){
    countSort(arr,n,i);
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
  radixSort(a,n);
  for (int i = 0; i < n; i++)
  {
    cout<<a[i]<<" ";
  }
  
  return 0;
}