#include<iostream>
#include "Node.h"
using namespace std;


int sum(Node<int>* root){
    if(root==NULL){
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
}


int main(){
    Node<int>* root = take_input();
    cout<<sum(root);
    return 0;
}