#include<bits/stdc++.h>
using namespace std;


int coin_change(int n,int *d,int numD,int output[][1000]){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(numD==0){
        return 0;
    }
    if(output[n][numD]>-1){
        return output[n][numD];
    }
    //using the denomination
    int first=coin_change(n-d[0],d,numD,output);
    //not using the denomination
    int second=coin_change(n,d+1,numD-1,output);
    output[n][numD]=first+second;
    return first+second;
}

int main(){
    int size;
    cout<<"enter total number of denomiation";
    cin>>size;
    int d[size];
    cout<<endl<<"enter the denominaitons"<<endl;
    for(int i=0;i<size;i++){
        cin>>d[i];
        cout<<" ";
    }
    cout<<endl;
    int n;
    cout<<"enter the change required"<<endl;
    cin>>n;
    int output[n+1][1000];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=size;j++){
            output[i][j]=-1;
        }
    }
    cout<<endl;
    cout<<"total number of ways are "<<coin_change(n,d,size,output);
    return 0;

}