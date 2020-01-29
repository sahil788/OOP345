
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"Text.h"
using namespace std;
namespace w3{

    Text::Text()
    {
        file_name = "";
    }
    Text::Text(const char* fname) {
        if (fname[0] == '/0') {
            file_name = "";
            cout << "file name not valid" << endl;
        }
        else {
            file_name = fname;
            fstream in(file_name,ios::in);
            string templine;
            if (in.is_open()) {
               
                while (getline(in, templine)) {
                    m_size++;
                }
                cout << size() << endl;
                text = new string[size()];
                in.clear();
                in.seekp(0);
             
                for (int i = 0; i < size(); i++) {
                    getline(in, text[i]);
                }
                in.close();
                
            }
            
                        
        } 
       
                              
    }
    Text::Text(Text& src){

        *this = src;
    }
    Text& Text::operator=(Text& rhs) {
        if (this != &rhs) {
            delete[] text;

            m_size = rhs.m_size;
            text = new string[size()];
           
            for (size_t i = 0; i < size(); i++) {
                text[i] = rhs.text[i];
            }
            return *this;

        }
    }
    

    Text::~Text()
    {
        cout << "in destructor" << endl;
        delete[]text;
    }
    //move constructor
    Text::Text(Text&& src) {
        cout << "in move constructor" << endl;
        m_size = src.m_size;
        text = src.text;
        src.m_size=0;
        src.text = nullptr;
        
    }
    //move operator
    Text& Text::operator=(Text&& rhs) {
        if (this != &rhs) {
            cout << "in move=" << endl;
            delete[] text;
            m_size = rhs.m_size;
            text = rhs.text;
            rhs.m_size = 0;
            rhs.text = nullptr;
            return *this;
        }
    }
    
}












