#include <iostream>
#include <string>

class Kvas
{
public:
    int xui;
private:
    char gl;
protected:
    bool gh;
public:
    Kvas():xui(1),gl('g')
    {
       std::cout<<'3'<<'\n'; 
    }
    Kvas(int xui, bool gh, char gl):xui(xui),gl(gl),gh(gh)
    {
        std::cout<<"Romawins;";
    }
    ~Kvas()
    {
       std::cout<<"563636"<<'\n'; 
    }
};

int main()
{
    Kvas tr;
    std::cout<<tr.xui;
    return 0;
}