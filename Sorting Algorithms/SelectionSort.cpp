#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void selection(vector<int>&a,int n){
  for(int i=0;i<n-1;i++){
    int index=i;
    for(int j=i+1;j<n;j++){
      if(a[j]<a[index]){
        index=j;
      }
    }
    swap(a[i],a[index]);
  }
}
//   insert min element at it position by swaping
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  selection(a,n);
  for (int i = 0; i < n; i++)
  {
    cout<<a[i]<<" ";
  }
  
  return 0;
}