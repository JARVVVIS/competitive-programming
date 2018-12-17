//remove leaf nodes and print level wise

#include<iostream>
#include<queue>
using namespace std;
#include "Node.h"


Node<int>* delete_leaf(Node<int>* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    root->left = delete_leaf(root->left);
    root->right = delete_leaf(root->right);
}
int count_no_leaf(Node<int>* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right == NULL){
        return 1;
    }
    return count_no_leaf(root->left)+count_no_leaf(root->right);

}


int main(){
    Node<int>* root = take_input();
   // root =  delete_leaf(root);    delete leafs
   // print_level_line(root);
   cout<<count_no_leaf(root);      // count no. of leaf nodes
  
    return 0;
}