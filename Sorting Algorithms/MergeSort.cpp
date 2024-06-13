#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int povit= arr[s];
    int count=0;
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i]<=povit){
            count++;
        }
    }
    int povitIndex= s+count;
    swap(arr[s],arr[povitIndex]);
    int i = s, j = e;

    while(i < povitIndex && j > povitIndex) {

        while(arr[i] <= povit) 
        {
            i++;
        }

        while(arr[j] > povit) {
            j--;
        }

        if(i < povitIndex && j > povitIndex) {
            swap(arr[i++], arr[j--]);
        }

    }
    return povitIndex; 
}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
   int p= partition(arr,s,e);

    //left part sort karna h 
    quickSort(arr, s, p-1);
    
    //right part sort karna h 
    quickSort(arr, p+1, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}