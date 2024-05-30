#include<string>
#include<iostream>
class Person{
    friend std::istream &read(std::istream &is,Person &person);
    friend std::istream &print(std::ostream &os,const Person &person);

public:
    Person() = default;
    Person(const std::string sname, const std::string saddr):name(sname),address(saddr){}
    Person(std::istream &is){read(is,*this)}
    
    std::string const &getname() const {return name;}
    std::string const &getaddress() const {return address;}
private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is,Person &person){
    return is>> person.name>> person.address;
}


std::ostream &print(std::ostream &os,const Person &person){
    return os<<person.name<<" "<<person.address;
}

