#include<iostream>
using namespace std;
#include "Node.h"


bool check_leaf(Node<int>* root){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;


}


void calc_sum_left(Node<int>* root , int& sum){
    if(root==NULL){
        return ;
    }
    if(check_leaf(root->left)){
        sum+=root->left->data;
    }
    calc_sum_left(root->left,sum);
    calc_sum_left(root->right,sum);

}

void calc_sum_right(Node<int>* root , int& sum){
    if(root==NULL){
        return ;
    }
    if(check_leaf(root->right)){
        sum+=root->right->data;
    }
    calc_sum_right(root->left,sum);
    calc_sum_right(root->right,sum);

}





int left_leaf(Node<int>* root){
    int sum=0;
    calc_sum_left(root,sum);
    return sum;

}
int right_leaf(Node<int>* root){
    int sum=0;
    calc_sum_right(root,sum);
    return sum;

}




int main(){
    Node<int>* root = take_input();
    cout<<left_leaf(root);
    cout<<endl<<right_leaf(root);
    return 0;
}