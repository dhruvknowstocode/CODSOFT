#include<iostream>
using namespace std ;
int firstocc(int arr[],int size,int target){
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==target){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return ans;
}
int lastocc(int arr[],int size,int target){
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==target){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return ans;
}
int main(){
    int arr[7]={1,3,3,3,7,9,11};
    cout<<"first occurence is at :"<<firstocc(arr,7,3)<<endl;
    cout<<"last occurence is at :"<<lastocc(arr,7,3)<<endl;
    int len=lastocc(arr,7,3)-firstocc(arr,7,3)+1;
    cout<<len;
    return 0;
}