#pragma once

class Singleton
{
public:
    static Singleton& GetInstance(){
        static Singleton instance;
        return instance;
    }

private:
    Singleton(/* args */){}
    ~Singleton(){}
    
    // assignment operator
    Singleton& operator=(const Singleton& other) = delete;

    // copy constructor
    Singleton(const Singleton& other) = delete;
};

