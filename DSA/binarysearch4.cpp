#include<iostream>
using namespace std ;
int binarysearch(int x){
        int s=0;
        int e=x;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            long long square=(long long)mid*mid;
            if(square==x){
                return mid;
            }
            else if(square>x){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
}
double moreprecision(int n,int precision,int tempsol){
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=0;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter your number :";
    cin>>n;
    int tempsol=binarysearch(n);
    cout<<moreprecision(n,3,tempsol);
    return 0;
}