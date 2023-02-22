//
//  UniquePointer.hpp
//  ThirdGame-mobile
//
//  Created by SarthakR on 22/02/23.
//

#ifndef UniquePointer_hpp
#define UniquePointer_hpp
#include <stdio.h>
#include<iostream>

template <typename T> class UniquePointer{
   
public:
    T *m_ptr;
    UniquePointer(){
        std::cout<<"Default Constructor Called\n";
        m_ptr = new T();
    }
    
    UniquePointer(T obj){
        m_ptr= new T(obj);
        std::cout<<"\nParameter Constructor Called\n";
    }
    
    ~UniquePointer(){
        std::cout<<"Destructor Called\n";
        delete m_ptr;
    }
    
    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& other){
        std::cout<<"Move Constructor Called\n";
        m_ptr = other.m_ptr;
        other.m_ptr=nullptr;


    }

    UniquePointer& operator=(UniquePointer&& other){
        std::cout<<"Move Assignment Called\n";
        if(this != &other){
            if(m_ptr!=nullptr)
                delete[] m_ptr;
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }
   
   T operator*(){
        return *m_ptr;
    }
    
};

#endif /* UniquePointer_hpp */
