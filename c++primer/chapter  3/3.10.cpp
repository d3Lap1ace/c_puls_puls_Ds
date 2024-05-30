#include<iostream>
#include<string>
using  namespace std;
int main(){
    string str = "hello,this is c++,not java";
    string result;
    for(auto &x : str){
        if(!ispunct(x)){
            result += x;
        }
    }
    cout<<result<<endl;
}