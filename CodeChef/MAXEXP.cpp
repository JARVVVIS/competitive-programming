#include <iostream>
using namespace std;


void binarySearch(int arr[],int l,int r){
    if(r>=l){
    int mid = l+(r-l)/2;
    if(mid==l){
        cout<<"1 "<<arr[mid]<<endl;
        int ans;
        cin>>ans;
        cout<<"2 "<<endl;
        cout<<"3 "<<arr[mid]<<endl;
        return;
    }
    cout<<"1 "<<arr[mid]<<endl;
    int check;
    cin>>check;
    if(check==0){
        binarySearch(arr,mid+1,r);
    }else{
        cout<<"2"<<endl;
        binarySearch(arr,l,mid);
         }
    }
    return;
}


int main(){
    int n,c;
    cin>>n>>c;
    int *arr = new int(n);
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    binarySearch(arr,0,n-1);
    return 0;
}