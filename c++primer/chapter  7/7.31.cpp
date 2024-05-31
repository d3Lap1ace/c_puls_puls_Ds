#include<iostream>
class Y;

class X{
    Y* y = nullptr;
};
class Y{
    X x;
};

int main(){
    return 0;
}