//some utility functions
#include<iostream>
#include<algorithm>
using namespace std;

class arrayInput{
    public:
    int* arr;
    int size;
    arrayInput(int size){
        this->size = size;
    }

};


arrayInput* take_array_input(){
    cout<<"Enter the size "<<endl;
    int size;
    cin>>size;
    arrayInput* array = new arrayInput(size);
    int* arr = new int(size);
    for(int i=0;i<size;i++){
        cout<<"Enter the "<<i<<" element ";
        cin>>arr[i];
        cout<<endl;
    }
    array->arr = arr;
    return array;
}


void print_array(int* a , int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl; 
}