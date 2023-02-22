//
//  SharedPointer.hpp
//  ThirdGame-mobile
//
//  Created by SarthakR on 22/02/23.
//

#ifndef SharedPointer_hpp
#define SharedPointer_hpp

#include <stdio.h>
#include<iostream>

template <typename T> class SharedPointer{
   
public:
    T *m_ptr;
    int *count;
    SharedPointer(){
        std::cout<<"Default Constructor Called\n";
        m_ptr = new T();
        count = new int();
    }
    
    SharedPointer(T obj){
        std::cout<<"\nParameter Constructor Called\n";
        m_ptr= new T(obj);
        count = new int(1);
    }
    
    ~SharedPointer(){
        std::cout<<"Destructor Called\n";
        (*count)--;
        if(count==0)
            delete m_ptr;
    }
    
    SharedPointer& operator=(const SharedPointer& other){
        m_ptr = other.m_ptr;
        count = other.count;
        (*count)++;
        return *this;
    }

    SharedPointer(const SharedPointer& other){
        m_ptr = other.m_ptr;
        count = other.count;
        (*count)++;
  
    }

    SharedPointer(SharedPointer&&)=delete;

    SharedPointer& operator=(SharedPointer&&)=delete;
    
};


#endif /* SharedPointer_hpp */
