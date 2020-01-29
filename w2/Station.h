#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
namespace w2{
    enum PassType{adult,student};
    class Station {
        string name;
        unsigned int student_pass;
        unsigned int adult_pass;
    public:
        Station();
        void set(const std::string& name1, unsigned s, unsigned a);
        void update(PassType, int num);
        unsigned inStock(PassType);
        const std::string& getName()const;

    };

}

