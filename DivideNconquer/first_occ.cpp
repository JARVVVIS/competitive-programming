//first occurence of a element

#include "utility.h"

int first_occurence(int* arr ,  int l ,int r, int x){
    int result=-1;
    while(r>=l){
            int mid = l +(r-l)/2;
            if(arr[mid]==x){
                result = mid;
                r = mid-1;                
            }
          else  if(arr[mid]<x){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
    }    
    return result;
}

int last_occ(int* arr , int l ,int r,int x){
 int result=-1;
    while(r>=l){
            int mid = l +(r-l)/2;
            if(arr[mid]==x){
                result = mid;
                l = mid+1;              
            }
            else if(arr[mid]<x){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
    }    
    return result;
}






int main(){
    arrayInput* array = take_array_input();
    int* a = array->arr;
    int size = array->size;
    int x;
    cout<<"Enter element to be found "<<endl;
    cin>>x;
    int result = first_occurence(a,0,size-1,x);
  //  cout<<"First occurence is at "<<result<<endl;
   int  result1 = last_occ(a,0,size-1,x);
    cout<<"Last occurence is at "<<result1;
    return 0;
}