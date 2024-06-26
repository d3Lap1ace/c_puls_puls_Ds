#include<iostream>
#include<string>
class Sales_data{

    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data() = default;   // 让编译器自己生成默认的构造函数
    Sales_data(const std::string &s):bookNo(s){}  // 只有bookNo的构造函数
    Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(n*p){}  // 有参构造函数
    Sales_data(std::istream &is){read(is, *this)};


    std::string isbn() const {return bookNo;}; // get bookNO
    Sales_data& combine(const Sales_data&);  // 
    
private:
    std::string bookNo;        // string  书的名字
    unsigned units_sold = 0;   // 无符号int 买多少
    double revenue = 0.0;      // double   收入
};

Sales_data& Sales_data::combine(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is,Sales_data &item){
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}
std::ostream &print(std::ostream &os,const Sales_data &item){
    os << item.isbn()<<" "<<item.units_sold<<" "<<item.revenue;
    return os;
}
Sales_data add(const Sales_data &lhs,const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


Sales_data::Sales_data(std::istream &is){
    read(is,*this);
}
Sales_data& Sales_data::combine(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


inline double Sales_data::avg_price() const{
    return units_sold ? revenue/units_sold : 0;
}

int main(){
    Sales_data item1;
    print(std::cout,item1) << std::endl;

    Sales_data item2("0-201-78345-X");
    print(std::cout,item2)<<std::endl;

    Sales_data item3("0-201-78345-X",3,20.00);
    print(std::cout,item3)<<std::endl;

    Sales_data item4(std::cin);
    print(std::cout,item4)<<std::endl;
    
}
