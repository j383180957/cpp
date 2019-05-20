#include<iostream>
#include<string.h>
using std::cout;
using std::endl;
using std::string;

class Computer
{

public:
    void setBrand(const char* brand);
    void setPrice(float price);
    void print();

private:
    char _brand[20];
    float _price;

};

void Computer::setBrand(const char* brand)
{
    strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
    _price = price;
}

void Computer::print()
{
    cout << "brand = " << _brand << endl
         << "price = " << _price << endl;
}



int main(void)
{
    Computer pc;
    pc.setBrand("apple");
    pc.setPrice(10000);
    pc.print();
    return 0;
}

