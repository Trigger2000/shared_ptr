#include "shared_ptr.h"

int main()
{
    int a = 5, b = 7, c = 9;
    shared_ptr<int> ptr1 (&a);
    shared_ptr<int> ptr2 (&b);
    if (5 > 3)
    {
        shared_ptr<int> ptr3 (&a);
    }
    shared_ptr<shared_ptr<int>> ptr3 (&ptr1);
    shared_ptr<int> ptr4 (&c);
    shared_ptr<int> ptr5 (&b);
    
    int d = ptr1.get();
    //std::cout << d << '\n';
    
    char p = 'p';
    
    shared_ptr<char> ptr6 (&p);
    shared_ptr<char> ptr7 (&p);
    
    /*for (auto item: proxies<int>)
    {
        std:: cout << item.amount_ << ' ';
    }
    std:: cout << '\n';
    
    for (auto item: proxies<char>)
    {
        std:: cout << item.amount_ << ' ';
    } */
    
    for (auto item: proxies<shared_ptr<int>>)
    {
        std:: cout << item.amount_ << ' ';
    }
    std:: cout << '\n';
    return 0;
}
