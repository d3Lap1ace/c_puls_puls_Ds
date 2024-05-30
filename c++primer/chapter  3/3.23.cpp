#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int>vec(10,1);
    for(auto it=vec.begin();it!=vec.end();it++){
        *it *=2;
        cout<<*it<<(it!=vec.end()-1 ? ",":" "); 
    }

}

