#include<iostream>
using namespace std ;
class heap{
    public:
    int size;
    int arr[100];
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    void deletee(){
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int left=2*i;
            int right=2*i+1;
            int largest=i;
            if(left<=size&&arr[largest]<arr[left]){
                largest=left;
            }
            if(right<=size&&arr[largest]<arr[right]){
                largest=right;
            }
            if(largest!=i){
                swap(arr[i],arr[largest]);
                i=largest;
            }
            else{
                break;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    heap h;
    h.insert(40);
    h.insert(45);
    h.insert(50);
    h.insert(35);
    h.insert(55);
    h.print();
    h.deletee();
    h.print();
    return 0;
}