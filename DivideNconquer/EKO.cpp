#include "utility.h"
#include<conio.h>
#include<stdio.h>
int n,m;

bool func(int*arr , int num){
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>num){
            sum+=arr[i]-num;
        }
    }
    return sum >= m;
}



int bs(int* a){
    int h=-1;
    int ini = 0;
    int last=a[n-1];
    while(last>ini){
        int mid = ini+(last-ini)/2;
        if(func(a,mid)){
            if(mid>h){
                h=mid;
            }
            ini = mid+1;
        }
        else{
           last = mid-1;
        }
    }
    return h;




}

int main(){
    scanf("%d %d",&n,&m);
    int* a = new int(n);
    for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int result = bs(a);
    printf("%dn",result);
    return 0;
}