#include <iostream>
#include <string>

void swap(int &x, int &y)
{
    int data = x;
    x = y;
    y = data;
}

int main()
{
    int popa = 3;
    int po = 4;
    int &pop = popa;
    std::cout<<pop;
    swap(popa, po);
    std::cout<<popa<<' '<<po;
    std::cout<<pop;
    // std::string goga = "Jopa";
    // std::cout<<goga + goga<<'\n';
    /*int ebat;
    std::cin>>ebat;
    std::cout<<ebat<<std::endl;*/
    return 0;
}