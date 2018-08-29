/*
Given an integer array A which
 contains duplicates. Remove duplicates from 
the array and return a new array 
without any duplicates.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> remove_duplicates(vector<int> input){
set<int> s;
vector<int> result;
for(int i=0;i<input.size();i++){
    s.insert(input[i]);
}
set<int>::iterator it;
for(it=s.begin();it!=s.end();it++){
    result.push_back(*it);
}

return result;
}



int main(){
    int size;
    cin>>size;
    vector<int> v;
    for(int i=0;i<size;i++){
        int input;
        cin>>input;
        v.push_back(input);
    }
    vector<int> ans = remove_duplicates(v);
    vector<int>::iterator it;
    for(it=ans.begin();it<ans.end();it++){
        cout<<*it<<" "<<endl;
    }
    return 0;
}