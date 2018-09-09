#include<bits/stdc++.h>
using namespace std;

int ways(int n,int *arr){
    //base conditions
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(arr[n]>0){
        return arr[n];
    }
    //recurrence relation
    return ways(n-1,arr)+ways(n-2,arr)+ways(n-3,arr);
}






int main(){
    int n;
    //number of stairs
    cin>>n;
    //for memotisations
    int *arr=new int[n+1];
    memset(arr,0,sizeof(arr));
    cout<<ways(n,arr)<<endl;
    delete [] arr;
    return 0;
}