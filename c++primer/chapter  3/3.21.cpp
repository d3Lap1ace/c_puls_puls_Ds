#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print_check(const vector<int>& vec){
    cout<<"size: "<< vec.size() <<" content: [";
    for(auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << (it!= vec.end()-1?",":"");
    }
    cout<<"]\n"<<endl;
}
void print_check(const vector<string>& vec){
    cout<<"size :"<<vec.size() <<" content: [";
    for(auto it = vec.begin();it != vec.end();++it){
        cout<<*it<<(it != vec.end()-1?",":"");
    }
    cout<<"]\n"<<endl;
}

int main(){
    vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10, "hi" };
    print_check(v1);
    print_check(v2);
    print_check(v3);
    print_check(v4);
    print_check(v5);
    print_check(v6);
    print_check(v7);
}