#include<iostream>
using namespace std;
#include "Node.h"




int sum_child_x(Node<int>* root,int& sum,int child){
        if(root==NULL){
            return 0;
        }
    if ((root->left && root->left->data == child) || 
        (root->right && root->right->data == child)) {
        sum+=root->data;
    }
    sum_child_x(root->left,sum ,child);
    sum_child_x(root->right,sum,child);
  //  return sum+sum_child_x(root->left,sum,child)+sum_child_x(root->right,sum,child);  wrong approach
}

int util(Node<int>*root ,int x){
    int sum=0;
    sum_child_x(root,sum,x);
    return sum;
}




int main(){
    Node<int>* root = take_input();
    int x;
    cout<<"Enter the child value "<<endl;
    cin>>x;

    cout<<util(root,x);
}