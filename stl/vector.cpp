#include<bits/stdc++.h>
using namespace std;

int main(){
    //intialised a vector of size 5.
    //no need to explicitly mention the size --- vector<int> v
    vector<int> v(5);

    //can use like we use array also
    for(int i=0;i<v.size();i++){
        v[i]=i+1;

    }
    //we didnt mention the size explicityly
    vector<int> t;
    for(int i=0;i<4;i++){
        t.push_back(i+1);
    }


    //iterator is a pointer to element within range of elements.(sort of working like a pointer)
    // iterator++ -> poitns to next element in data structure, uses derefrence operator
    
    //iterator on vector data structure
    vector<int>::iterator it;
    
    //begin points to first elemnet 
    //end points to next position of last position
    for(it=v.begin();it<v.end();it++){
        //derefrence operator *
        cout<<*it<<endl;
    }

    return 0;
}
