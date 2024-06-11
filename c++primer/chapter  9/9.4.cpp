#include<iostream>
using namespace std;



vector<int>::const_iterator find(vector<int>::const_iterator begin,vector<int>::const_iterator end,int i){
    while(begin++ != end){
        if(*begin == i) return begin;
        ++begin;
    }
    return end;
}

int main(){
}