#include<iostream>
using namespace std ;
bool binarysearch(int arr[],int size,int target){
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;
    while(s<e){
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return false;
}
int main(){
    int arr[5]={1,2,3,6,7};
    int target;
    cout<<"Enter the value of target :";
    cin>>target;
    int size=5;
    if(binarysearch(arr,size,target)){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}