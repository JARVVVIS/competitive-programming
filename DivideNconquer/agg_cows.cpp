#include "utility.h"


bool func(int num , int* a, int c, int n){
    int cows = 1 ;
    int pos = a[0];
    for(int i=1;i<n;i++){
        if(a[i]-pos>=num){
            cows++;
            if(cows==c){
                return true;
            }
            pos = a[i];
        }
    }
    return false;

}




int bs(int* a , int l , int r , int c , int size ){
    int max=-1;
    int ini = a[l];
    int last = a[r];
    while(last > ini){
        int mid = ini+(ini+last)/2;
        if(func(mid,a,c,size)){
            if(mid>max){
                max = mid;
            }
            ini=mid+1;
        }        
        else{
            last = mid-1;
        }
    }
    return max;
}






int main(){
    arrayInput* arr = take_array_input();
    int* a = arr->arr;
    int N = arr->size;
    int c;
    cout<<"Enter number of cows "<<endl;
    cin>>c;
    sort(a,a+N);
    int k = bs(a,0,N-1,c,N);
    cout<<"Min distance possible is "<<k;
    return 0;

}