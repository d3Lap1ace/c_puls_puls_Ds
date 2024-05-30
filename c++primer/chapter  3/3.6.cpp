#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1 = "hello";
    for(char &x : str1){
        x = 'X';
    }
    cout<<str1<<endl;
    return 0;
}