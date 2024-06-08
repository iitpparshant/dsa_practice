#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void insertion(vector<int>&arr,int n){
  for(int i=1;i<n;i++){
    int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;
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
  insertion(a,n);
  for (int i = 0; i < n; i++)
  {
    cout<<a[i]<<" ";
  }
  
  return 0;
}