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

int count_nodes(Node<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans+=count_nodes(root->children[i]);
    }
    return ans;
}

int count_sum(Node<int>* root){
    if(root==NULL){
        return 0;

    }
    int ans= root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=count_sum(root->children[i]);
    }
    return ans;
}

int max_node(Node<int>* root){
    if(root==NULL){
        return 0;
    }
    for(int i=0;i<root->children.size();i++){
        max_node(root->children[i]);
    }


    for(int i=0;i<root->children.size();i++){
        if(root->data < root->children[i]->data){
            root->data =  root->children[i]->data;
        }
    }
    return root->data;
}


int main(){
    Node<int>* root = takeInput();
    print_tree(root);
    cout<<"Total nummber of nodes : "<<count_nodes(root)<<endl;
    cout<<"Total sum of nodes : "<<count_sum(root)<<endl;
    cout<<"Max node is "<<max_node(root);
    return 0;
}
