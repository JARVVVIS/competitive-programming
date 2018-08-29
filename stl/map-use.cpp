#include<bits/stdc++.h>
using namespace std;


//map stores numbers as well as their frequency
//both key value pair
int main(){
    int arr[] = {1,2,3,4,32,12,3,12,3};
    map<int,int> m;
    //storing the frequencies
    for(int i=0;i<9;i++){
        m[arr[i]]++;
    }
    map<int,int>::iterator it;
    //printing using an iterator
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    //to delete
    m.erase(1);
    cout<<endl;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    //we also have unordered maps
    //made through hash tables
    //O(1)
    unordered_map<int,int> o;
    //else all functions are same,its just faster
    
    return 0;
}