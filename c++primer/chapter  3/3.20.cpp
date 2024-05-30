#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<int> v1;
    int i;
    while(cin >> i){
        v1.push_back(i);
    }
    for(int i = 0;i<v1.size()-1;++i){
        cout<<v1[i]+v1[i+1]<<endl;
    }
    cout<<"-----------------"<<endl;

    int m =0;
    int n = v1.size()-1;
    while(m<n){
        cout<<v1[m]+v1[n]<<endl;
        ++m;
        ++n;
    }
}