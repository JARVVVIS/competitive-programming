//taking input without recurssion
#include<iostream>
#include<queue>
#include "Node.h"
using namespace std;


Node<int>* takeInput(){
    int rootData;
    cout<<"Enter rootData "<<endl;
    cin>>rootData;
    Node<int>* root  = new Node<int>(rootData);

    queue<Node<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Node<int>* front  = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter children of "<<front->data << endl;
        int numChild;
        cin>>numChild;
        for(int i =0 ;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of  "<<front->data<<endl;
            cin>>childData;
            Node<int>* child = new Node<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

return root;
}




void print_tree(Node<int>* root){
    if(root==NULL){
        return ;
    }
    queue<Node<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Node<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

int height(Node<int>* root){
    int ans = 0;
    for(int i=0;i<root->children.size();i++){
        int child = height(root->children[i]);
        if(child > ans){
            ans = child;
        }
    }
    return ans+1;
}

int leaf_nodes(Node<int>* root){
    if(root==NULL){
        return 1;
    }
    if(root->children.size()==0){
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans+=leaf_nodes(root->children[i]);
    }
    return ans;
}


int main(){
    Node<int>* root = takeInput();
    print_tree(root);
    cout<<endl;
    cout<<"Height of the tree is : "<<height(root)<<endl;
    cout<<"Num of leaf nodes are : "<<leaf_nodes(root);
    return 0;
}
