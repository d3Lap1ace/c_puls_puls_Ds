#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<int> v;
    vector<string> v2;
    int i;
    string str;
    while(cin>>i && i != 9){
        v.push_back(i);
    }
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;

    while(cin>>str &&str != "9"){
        v2.push_back(str);
    }
    for(auto x : v2){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}