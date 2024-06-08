#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void bubble(vector<int>&a,int n){
  for(int i=1;i<n;i++){
    bool swapped=false;
    for(int j=0;j<n-i;j++){
      if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
        swapped= true;
      }
    }
    if(swapped==false){
      break;
    }
  }
}
//   place max element at it position by swaping
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  bubble(a,n);
  for (int i = 0; i < n; i++)
  {
    cout<<a[i]<<" ";
  }
  
  return 0;
}