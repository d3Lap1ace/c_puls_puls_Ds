#include<string>
#include<iostream>
struct Person{
    std::string name;
    std::string address;

    std::string const &getname() const {return name;}
    std::string const &getaddress() const {return address;}
};

std::istream &read(std::istream &is,Person &person){
    return is>> person.name>> person.address;
}


std::ostream &print(std::ostream &os,const Person &person){
    return os<<person.name<<" "<<person.address;
}

