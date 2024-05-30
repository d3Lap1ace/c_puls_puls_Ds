#include<string>
#include<iostream>
class Screen{
    public:
        using pos = std::string::size_type; // 起别名

        Screen() = default; // 让编译器自己生成默认的构造函数
        Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c){ }

        char get() const {return contents[cursor];}
        char get(pos r,pos c) const {return contents[r*width+c];}

        inline Screen& move(pos r,pos c);
        inline Screen& set(char c);
        inline Screen& set(pos r,pos c,char ch);

        const Screen& display(std::ostream &os)const{do_display(os); return *this; }
        Screen& display(std::ostream &os){do_display(os);return *this;}
    private:
        pos cursor = 0;
        pos height = 0,width = 0;
        std::string contents; 
    private:
        void do_display(std::ostream &os)const {os << contents;}
};
inline Screen& Screen::move(pos r,pos c){
    cursor = r*width +c;
    return *this;
}
inline Screen& Screen::set(char c){
    contents[cursor] = c;
    return *this;
}
inline Screen& Screen::set(pos r,pos c,char ch){
    contents[r*width+c] = ch;
    return *this;
}

int main(){
    Screen myScreen(5,5,'x');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout<<"\n";
    
    return 0;
}