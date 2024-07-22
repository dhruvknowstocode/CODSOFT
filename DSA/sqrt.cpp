#include<iostream>
using namespace std ;
int floorSqrt(int n){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int sqr=mid*mid;
        if(sqr==n){
            return mid;
        }
        else if(sqr>n){
            e=mid-1;
        }
        else{
            s=mid+1;
            ans=mid;
        }
    }
    return ans;
}
double decimal(int n,int precision,int tempsol){
    double ans=tempsol;
    double factor=1;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    int tempsol=floorSqrt(n);
    cout<<decimal(n,3,tempsol);
    return 0;
}