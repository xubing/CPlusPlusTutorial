
//
//  main.cpp
//  TestCPlus
//
//  Created by Bing on 1414.
//  Copyright (c) 2014年 zhang xubing. All rights reserved.
//


#include <thread>
#include <iostream>
#include <vector>
#include <atomic>

using namespace std;

void hello()
{
    cout << "hello from thread" <<endl;
}

void distinguishhello(){
    std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
}

class A
{
public:
    int Func(int x, int y)
    {
        std::cout <<"class A Func "<<x+y<<endl;
        return 0;
    };
};

struct Counter {
    std::mutex _mutex;
    int value;
    
    void increment(){
        _mutex.lock();
        ++value;
        std::cout<<value<<endl;
        _mutex.unlock();
    }
};


    //原子类型 。
struct AtomicCounter {
    std::atomic<int> value;
    
    void increment(){
        ++value;
    }
    
    void decrement(){
        --value;
    }
    
    int get(){
        return value.load();
    }
};


int main(int argc, const char * argv[])
{
    
        // insert code here...
    /*
     std::thread t1(hello);
     t1.join();
     */
    
        //
    /*
     std::vector<std::thread> threads;
     
     for(int i = 0; i < 5; ++i){
     threads.push_back(std::thread(distinguishhello));
     }
     
     for(auto& thread : threads){
     thread.join();
     }
     */
    
    
        //并发。
        //信号量
    /*
     Counter counter;
     std::vector<std::thread> threads;
     for(int i = 0; i < 5; ++i){
     threads.push_back(std::thread([&counter](){
     for(int i = 0; i < 100; ++i){
     counter.increment();
     }
     }));
     }
     
     for(auto& thread : threads){
     thread.join();
     }
     
     std::cout << counter.value << std::endl;
     */
    
        //原子类型
    AtomicCounter counter;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread([&counter](){
            for(int i = 0; i < 100; ++i){
                counter.increment();
            }
        }));
    }
    
    for(auto& thread : threads){
        thread.join();
    }
    
    std::cout << counter.value << std::endl;
    
    
        //bind
    /*
     A a;
     auto bf2 = std::bind(&A::Func, a,40,std::placeholders::_2);
     bf2(10,20,200,100,00,20); ///< same as a.Func(10, 20)
     */
        //function
    /*
     std::function< int(int)> bf3 = std::bind(&A::Func, a, std::placeholders::_1, 100);
     bf3(10); ///< same as a.Func(10, 100)
     return 0;
     */
    
        //lamda
    /*
     vector< int> vec;
     int i= 52;
     vec.push_back(i++);
     vec.push_back(i++);
     vec.push_back(i++);
     vec.push_back(i++);
     vec.push_back(i++);
     vec.push_back(i++);
     /// 1. simple lambda
     auto it = std::find_if(vec.begin(), vec.end(), [](int i) { return i > 50; });
     if(it != vec.end())
     cout<< (*it)<<endl;
     
     
     /// 2. lambda return syntax
     std::function< int(int)> square = [](int i) > int { return i * i; };
     cout<< square(20)<<endl;
     */
}
