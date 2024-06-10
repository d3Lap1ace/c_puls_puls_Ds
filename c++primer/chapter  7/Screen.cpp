#include<string>
#include<iostream>
#include<string>
#include<vector>
class Screen;
class Window_mgr{
    public:
        using ScreenIndex = std::vector<Screen>::size_type;  // 起别名
        inline void clear(ScreenIndex);  // 内联函数
    private:
        std::vector<Screen> Screens;  // 对象数组
};

class Screen{
    friend void Window_mgr::clear(ScreenIndex);


    public:
        using pos = std::string::size_type; // 起别名

        Screen() = default; // 让编译器自己生成默认的构造函数
        Screen(pos ht, pos wd):height(ht),width(wd),contents(ht*wd,' '){ } // 有参构造 
        Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c){ } // 有参构造

        char get() const {return contents[cursor];}  // get方法
        char get(pos r,pos c) const {return contents[r*width+c];} // 同上 

        inline Screen& move(pos r,pos c);
        inline Screen& set(char c);
        inline Screen& set(pos r,pos c,char ch);

        const Screen& display(std::ostream &os)const{do_display(os); return *this; }
        Screen& display(std::ostream &os){do_display(os);return *this;}
    private:
        void do_display(std::ostream &os)const{os<<contents; }
    private:
        pos cursor = 0;
        pos height = 0,width = 0;
        std::string contents; 
    private:
        void do_display(std::ostream &os)const {os << contents;}
};

inline void Window_mgr::clear(ScreenIndex i){
    Screen& s = Screens[i];
    s.contents = std::string(s.height*s.width,' ');
}
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