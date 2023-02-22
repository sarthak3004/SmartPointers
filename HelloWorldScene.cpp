/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include<iostream>
#include "UniquePointer.hpp"
#include "SharedPointer.hpp"
USING_NS_CC;


//UniquePointer<int> f()
//    {
//        std::cout<<"IN F\n";
//        UniquePointer<int> p(new int(7));
//        std::cout<<"OUT F\n";
//        return p;
//    }

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{

    if ( !Scene::init() )
    {
        return false;
    }
    
    {
//        UniquePointer<int> p (7);
//        UniquePointer<int> q = std::move(p);
//        std::cout<<"Value with q="<<*(q.m_ptr)<<"\n";
//        UniquePointer<int> r;
//        r=std::move(q);
//        if(p.m_ptr==nullptr && q.m_ptr==nullptr)
//            std::cout<<"\np and q are null\n";
//        std::cout<<"Value with r="<<*(r.m_ptr)<<"\n";
        
        SharedPointer<int> p (7);
        std::cout<<"Value="<<*(p.m_ptr)<<" Count="<<*(p.count)<<"\n";
        {
            SharedPointer<int> p2(p);
            std::cout<<"Value="<<*(p.m_ptr)<<" Count="<<*(p.count)<<"\n";
            std::cout<<"Value="<<*(p2.m_ptr)<<" Count="<<*(p2.count)<<"\n";
        }
        std::cout<<"Value="<<*(p.m_ptr)<<" Count="<<*(p.count)<<"\n";
    }
    return true;
}


