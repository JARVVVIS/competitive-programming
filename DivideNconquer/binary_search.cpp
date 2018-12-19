//divide and conquer 
//break the problem into subproblems
//recursively solve these problems
//combine the answers

//problem:Given a sorted arry find a given element X.
//do it in O(LOG(n))

#include "utility.h"

int binary_search(int* a ,int l ,int r, int x){
        if(r>=l){
            int mid = l+ (r-l)/2;
            if(a[mid] == x){
                return mid;
            }
            if(a[mid]<x){
                return binary_search(a , mid+1,r,x );
            }
            else{
                return binary_search(a , l , mid-1,x);
            }
        }
        return -1; //nahi milla ya invalid array
}







int main(){
    arrayInput* array = take_array_input();
    int* a = array->arr;
    int  size = array->size;
    cout<<"Enter the number "<<endl;
    int x;
    cin>>x;
    int result = binary_search(a,0,size-1,x);
    cout<<"Index of the number is "<<result;
    return 0;
}





