//dynamic programming fibonacci numbers example
//exponential time complexity using basic recurssion to find nth fibonacci number

#include<bits/stdc++.h>
using namespace std;


int fib(int n,int *arr){
    if(n==0 || n==1){
        return 1;
    }
    //if we have already found out the solution take it directly
    if(arr[n]>0){
        return arr[n];
    }
    //recurssion command
    int output=fib(n-1,arr)+fib(n-2,arr);
    arr[n]=output;
    return output;
}

int fib_itr(int n){
    int *arr=new int[n+1];
    arr[0]=1;
    arr[1]=1;
    //first fill the array itteratively and then return the fibonacci number
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    int output=arr[n];
    delete [] arr;
    return output;
}


int main(){
    int n;
    //finbonaci number to be find
    cin>>n;
    int *arr=new int[n+1];
    memset(arr,0,sizeof(arr));
    cout<<fib(n,arr)<<endl;
    cout<<fib_itr(n)<<endl;
    delete [] arr;
    return 0;
}