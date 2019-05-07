//
//  shared_ptr.h
//  shared_ptr
//
//  Created by Илья  on 01/05/2019.
//  Copyright © 2019 Илья . All rights reserved.
//

#ifndef shared_ptr_h
#define shared_ptr_h

#include <iostream>
#include <vector>

template <typename type>
class proxy
{
public:
    type* ptr_;
    int amount_;
};

template <typename type>
class shared_ptr
{
    type* ptr_;
public:
    shared_ptr(type* item);
    ~shared_ptr();
    type& get();
};

template <typename type>
std::vector<proxy<type>> proxies;

template <typename type>
shared_ptr<type> :: shared_ptr(type* item)
{
    ptr_ = item;
    //std:: cout << item << '\n';
    bool check = 0;
    int pos = 0;
    for (auto it: proxies<type>)
    {
        if (it.ptr_ == item)
        {
            check = 1;
            break;
        }
        pos++;
    }
    
    if (check == 0)
    {
        proxy<type> pr;
        pr.amount_ = 1;
        pr.ptr_ = item;
        proxies<type>.push_back(pr);
    }
    else
    {
        proxies<type>[pos].amount_++;
    }
}

template <typename type>
shared_ptr<type>:: ~shared_ptr()
{
    int pos = 0;
    for (auto item: proxies<type>)
    {
        if (item.ptr_ == ptr_)
        {
            break;
        }
        pos++;
    }
    
    proxies<type>[pos].amount_ --;
    if (proxies<type>[pos].amount_ == 0)
    {
        proxies<type>[pos].ptr_ = nullptr;
    }
    
    ptr_ = nullptr;
}

template <typename type>
type& shared_ptr<type>:: get()
{
    std:: cout << '*';
    return *ptr_;
}


#endif /* shared_ptr_h */
