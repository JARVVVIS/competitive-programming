#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


vector<int> removeDuplicates(int* a, int size){
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0;i<size;i++){
        if(seen.count(a[i]) > 0){
            continue;
        }
        seen[a[i]]  == true;
        output.push_back(a[i]);
    }
    return output;
}

int main(){
    int a[] = {1,2,3,4,3,2,1,4,3,6,7,8};
    vector<int> output = removeDuplicates(a,12);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
}