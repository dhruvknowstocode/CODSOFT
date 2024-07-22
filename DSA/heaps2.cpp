#include<iostream>
using namespace std ;
void maxheapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxheapify(arr,n,largest);
    }
}
#include<iostream>
using namespace std ;
void maxheapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxheapify(arr,n,largest);
    }
}
void minheapify(int arr[],int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<n&&arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        minheapify(arr,n,smallest);
    }
}
void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[6]={45,56,67,43,12,44};
    print(arr,6);
    int n=6;
    for(int i=n/2;i>=0;i--){
        maxheapify(arr,6,i);
    }
    print(arr,6);
    for(int i=n/2;i>=0;i--){
        minheapify(arr,6,i);
    }
    print(arr,6);
    return 0;
}