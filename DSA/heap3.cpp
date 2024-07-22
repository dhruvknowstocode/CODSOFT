#include<iostream>
using namespace std ;

 void heapify(int arr[], int n, int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n&&arr[largest]<arr[left]){
            largest=left;
        }    
        if(right<n&&arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

    void buildHeap(int arr[], int n){
        for(int i=n/2;i>=0;i--){
            heapify(arr,n,i);
        }
    }
    
    void heapSort(int arr[], int n){
        buildHeap(arr,n);
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
int main(){
    return 0;
}