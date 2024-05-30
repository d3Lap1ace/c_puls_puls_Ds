#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1,str2;
    while(cin >> str1>>str2){
        if(str1 == str2){
            cout<<"the two strings are equal";
        }else{
            cout << "the larger string is:"<<((str1>str2)?str1:str2);
        }
    }
    return 0;
}