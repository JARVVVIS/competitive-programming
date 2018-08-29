#include<bits/stdc++.h>
using namespace std;



//set takes only one value one time -> unique value
int main(){
    //declaring
    set<int> s;
    int arr[]={1,2,3,4,5,5,6};
    for(int i=0;i<7;i++){
        //inserting elements in set
        s.insert(arr[i]);
    }
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++){
//        cout<<*it<<endl;
    }

    //s.find returns and iterator
    //if element is not there it returns s.end()
    if(s.find(6)==s.end()){
        cout<<"element not found";
    }
    else{
        cout<<"element is there";
    }


    return 0;
}